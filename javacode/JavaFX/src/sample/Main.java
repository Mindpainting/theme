package sample;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) {
        Circle circle = new Circle(100, 100, 50);

        /*// 设置圆心坐标
        circle.setCenterX(100);
        circle.setCenterY(100);
        // 设置半径
        circle.setRadius(50);*/

        // 设置画笔颜色
        circle.setStroke(Color.BLACK);
        // 设置填充颜色
        circle.setFill(Color.WHITE);

        Pane pane = new StackPane(circle);
        // 设置舞台名称
        primaryStage.setTitle("Circle");
        // 舞台之上设置场景
        primaryStage.setScene(new Scene(pane, 200, 200));
        primaryStage.show();
    }
}
