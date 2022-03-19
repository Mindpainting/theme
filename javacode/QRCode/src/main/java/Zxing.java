import com.google.zxing.BarcodeFormat;
import com.google.zxing.EncodeHintType;
import com.google.zxing.MultiFormatWriter;
import com.google.zxing.common.BitMatrix;
import com.google.zxing.qrcode.decoder.ErrorCorrectionLevel;
import com.spire.doc.Document;
import com.spire.doc.FileFormat;
import com.spire.doc.Section;
import com.spire.doc.documents.HorizontalAlignment;
import com.spire.doc.documents.Paragraph;

import javax.imageio.ImageIO;
import javax.swing.filechooser.FileSystemView;
import java.awt.image.BufferedImage;
import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Zxing {
    /**
     * CODE_WIDTH：二维码宽度，单位像素
     * CODE_HEIGHT：二维码高度，单位像素
     * FRONT_COLOR：二维码前景色，0x000000 表示黑色
     * BACKGROUND_COLOR：二维码背景色，0xFFFFFF 表示白色
     * 演示用 16 进制表示，和前端页面 CSS 的取色是一样的，注意前后景颜色应该对比明显，如常见的黑白
     */
    private static final int CODE_WIDTH = 200;
    private static final int CODE_HEIGHT = 200;
    private static final int FRONT_COLOR = 0x000000;
    private static final int BACKGROUND_COLOR = 0xFFFFFF;

    /**
     * 生成二维码并保存为图片：write(RenderedImage im,String formatName,File output)
     *
     * @param codeContent        :二维码参数内容，如果是一个网页地址，如 https://www.baidu.com/ 则微信扫一扫会直接进入此地址
     *                           如果是一些参数，如 1541656080837，则微信扫一扫会直接回显这些参数值
     * @param codeImgFileSaveDir :二维码图片保存的目录，如 D:/codes
     * @param fileName           :二维码图片文件名称，带格式，如 123.png
     * @param docx               :存放二维码的 word 的文件
     */
    public static void addQrCodeFromFileToWord(String codeContent, File codeImgFileSaveDir, String fileName, File docx) {
        try {
            /* 参数检验 */
            // public String trim()返回一个字符串，其值为此字符串，并删除任何前导和尾随空格
            if (codeContent == null || "".equals(codeContent.trim())) {
                System.out.println("二维码内容为空，不进行操作...");
                return;
            }

            codeContent = codeContent.trim();

            if (codeImgFileSaveDir == null || codeImgFileSaveDir.isFile()) {
                // 获取当前系统桌面路径
                codeImgFileSaveDir = FileSystemView.getFileSystemView().getHomeDirectory();
                System.out.println("二维码图片存放目录为空，默认放在桌面...");
            }
            if (!codeImgFileSaveDir.exists()) {
                // mkdirs() 创建包含多级的文件夹
                boolean mkdirs = codeImgFileSaveDir.mkdirs();
                System.out.println("二维码图片存放目录不存在，开始创建..." + " " + mkdirs);
            }
            if (fileName == null || "".equals(fileName)) {

                fileName = System.currentTimeMillis() + ".jpg";
                System.out.println("二维码图片文件名为空，随机生成 jpg 格式图片...");
            } else {
                fileName = fileName + ".jpg";
            }
            if (!docx.exists()) {
                // createNewFile() 创建文件
                boolean newFile = docx.createNewFile();
                System.out.println("docx 文件不存在，正在创建..." + " " + newFile);
            }

            /* com.google.zxing.EncodeHintType：编码提示类型，枚举类型
             * EncodeHintType.CHARACTER_SET：设置字符编码类型
             * EncodeHintType.ERROR_CORRECTION：设置误差校正
             * ErrorCorrectionLevel：误差校正等级，L = ~7% correction、M = ~15% correction、Q = ~25% correction、H = ~30% correction
             * 不设置时，默认为 L 等级，等级不一样，生成的图案不同，但扫描的结果是一样的
             * EncodeHintType.MARGIN：设置二维码边距，单位像素，值越小，二维码距离四周越近
             * */
            Map<EncodeHintType, Object> hints = new HashMap<>();
            hints.put(EncodeHintType.CHARACTER_SET, "UTF-8");
            hints.put(EncodeHintType.ERROR_CORRECTION, ErrorCorrectionLevel.M);
            hints.put(EncodeHintType.MARGIN, 1);

            /*
             * MultiFormatWriter:多格式写入，这是一个工厂类，里面重载了两个 encode 方法，用于写入条形码或二维码
             *      encode(String contents,BarcodeFormat format,int width, int height,Map<EncodeHintType,?> hints)
             *      contents:条形码/二维码内容
             *      format：编码类型，如条形码，二维码等
             *      width：码的宽度
             *      height：码的高度
             *      hints：码内容的编码类型
             * BarcodeFormat：枚举该程序包已知的条形码格式，即创建何种码，如一维的条形码，二维的二维码等
             * BitMatrix：位(比特)矩阵或叫 2D 矩阵，也就是需要的二维码
             */
            MultiFormatWriter multiFormatWriter = new MultiFormatWriter();
            BitMatrix bitMatrix = multiFormatWriter.encode(codeContent, BarcodeFormat.QR_CODE, CODE_WIDTH, CODE_HEIGHT, hints);

            /* java.awt.image.BufferedImage：具有图像数据的可访问缓冲图像，实现了 RenderedImage 接口
             * BitMatrix 的 get(int x, int y) 获取比特矩阵内容，指定位置有值，则返回 true，将其设置为前景色，否则设置为背景色
             * BufferedImage 的 setRGB(int x, int y, int rgb) 方法设置图像像素
             *      x：像素位置的横坐标，即列
             *      y：像素位置的纵坐标，即行
             *      rgb：像素的值，采用 16 进制,如 0xFFFFFF 白色
             */
            BufferedImage bufferedImage = new BufferedImage(CODE_WIDTH, CODE_HEIGHT, BufferedImage.TYPE_INT_BGR);
            for (int x = 0; x < CODE_WIDTH; x++) {
                for (int y = 0; y < CODE_HEIGHT; y++) {
                    bufferedImage.setRGB(x, y, bitMatrix.get(x, y) ? FRONT_COLOR : BACKGROUND_COLOR);
                }
            }

            /* javax.imageio.ImageIO   java 扩展的图像 IO
             * write(RenderedImage im,String formatName,File output)
             *      im：待写入的图像
             *      formatName：图像写入的格式
             *      output：写入的图像文件，文件不存在时会自动创建
             */
            File codeImgFile = new File(codeImgFileSaveDir, fileName);
            ImageIO.write(bufferedImage, "jpg", codeImgFile);


            // 将存放在文件中的二维码写入到 word 中
            // 创建 Document对象，加载 Word文档
            Document doc = new Document();
            doc.loadFromFile(docx.getPath());
            for (int i = 0; i < doc.getSections().getCount(); i++) {
                Section section = doc.getSections().get(i);
                Paragraph pText = section.addParagraph();
                Paragraph pImage = section.addParagraph();

                // 添加去掉图片后缀名的二维码说明文字到正文段落
                pText.appendText(fileName.substring(0, fileName.length() - 4));

                // 添加二维码到正文段落
                pImage.appendPicture(codeImgFile.getPath());

                // 设置文字和二维码居中显示
                pText.getFormat().setHorizontalAlignment(HorizontalAlignment.Center);
                pImage.getFormat().setHorizontalAlignment(HorizontalAlignment.Center);
            }

            // 保存文档
            doc.saveToFile("C:\\Users\\think\\Desktop\\qrcode.docx", FileFormat.Docx_2013);
            doc.dispose();

            // getPath() 将此抽象路径名转换为路径名字符串
            System.out.println("二维码图片生成成功：" + codeImgFile.getPath());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void createQrCodeToFile() {
        try {
            BufferedReader bufferedReader = new BufferedReader(new FileReader("C:\\Users\\think\\Desktop\\representation.txt"));
            String line;
            try {
                while ((line = bufferedReader.readLine()) != null) {
                    String[] info = line.split(",");
                    String codeContent = info[2];
                    // 存二维码的目录
                    File file = new File("C:\\Users\\think\\Desktop\\qrcode");
                    // 存二维码的 word 文件
                    File docx = new File("C:\\Users\\think\\Desktop\\qrcode.docx");
                    addQrCodeFromFileToWord(codeContent, file, info[0] + info[1], docx);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        createQrCodeToFile();
    }
}
