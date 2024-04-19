package model;

import lombok.Data;

/**
 * @Author Evjy
 * @Date 2024/4/15 13:43
 * @Description Native Pay 通知数据
 */

@Data
public class Resource {

    /**
     * 加密算法类型
     */
    private String algorithm;

    /**
     * 数据密文
     */
    private String ciphertext;

    /**
     * 附加数据
     */
    private String associated_data;

    /**
     * 原始类型
     */
    private String original_type;

    /**
     * 随机串
     */
    private String nonce;

}
