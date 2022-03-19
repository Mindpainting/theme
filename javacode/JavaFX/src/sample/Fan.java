package sample;

import javafx.animation.KeyFrame;
import javafx.animation.KeyValue;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Arc;
import javafx.scene.shape.ArcType;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Fan extends Application {
    @Override
    public void start(Stage primaryStage) {
        Circle circle = new Circle(125, 125, 75);
        // 设置画笔颜色
        circle.setStroke(Color.BLACK);
        // 设置填充颜色
        circle.setFill(Color.WHITE);

        // 创建三个按钮
        Button button1 = new Button("Pause");
        Button button2 = new Button("Resume");
        Button button3 = new Button("Reverse");

        HBox hBox = new HBox();
        // 设置面板内容整体对齐方式
        hBox.setAlignment(Pos.CENTER);
        // 设置结点之间的间隔
        hBox.setSpacing(20);
        hBox.getChildren().addAll(button1, button2, button3);

        Arc[] arc = new Arc[4];
        for (int i = 0; i < 4; i++) {
            arc[i] = new Arc(125, 125, 60, 60, 22.5 + 90 * i, 45);
            arc[i].setFill(Color.BLACK);
            // 设置弧的类型
            arc[i].setType(ArcType.ROUND);
        }

        // 创建时间轴动画,顺时针动画与逆时针动画
        Timeline timeline1 = new Timeline();
        timeline1.setCycleCount(Timeline.INDEFINITE);
        Timeline timeline2 = new Timeline();
        timeline2.setCycleCount(Timeline.INDEFINITE);
        Duration duration = Duration.millis(4000);
        KeyValue[] kv1 = new KeyValue[4];
        KeyFrame[] kf1 = new KeyFrame[4];
        KeyValue[] kv2 = new KeyValue[4];
        KeyFrame[] kf2 = new KeyFrame[4];
        for (int j = 0; j < 4; j++) {
            kv1[j] = new KeyValue(arc[j].startAngleProperty(), 360 + arc[j].getStartAngle());
            kf1[j] = new KeyFrame(duration, kv1);
            timeline1.getKeyFrames().add(kf1[j]);
            kv2[j] = new KeyValue(arc[j].startAngleProperty(), -360 + arc[j].getStartAngle());
            kf2[j] = new KeyFrame(duration, kv2);
            timeline2.getKeyFrames().add(kf2[j]);
        }
        button2.setOnMouseClicked(e -> {
            timeline2.pause();
            timeline1.play();
        });
        button1.setOnMouseClicked(e -> {
            timeline1.pause();
            timeline2.pause();
        });
        button3.setOnMouseClicked(e -> {
            timeline1.pause();
            timeline2.play();
        });

        // 创建一个Pane
        Pane pane = new Pane();
        pane.getChildren().addAll(circle, arc[0], arc[1], arc[2], arc[3]);
        // 创建一个BorderPane
        BorderPane borderPane = new BorderPane();
        borderPane.setCenter(pane);
        borderPane.setBottom(hBox);
        Scene scene = new Scene(borderPane, 250, 250);
        primaryStage.setTitle("Fan");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
