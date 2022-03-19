package sample;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class AttributesBind extends Application {
    @Override
    public void start(Stage primaryStage) {
        // 创建面板
        Pane pane = new Pane();

        Circle circle = new Circle();
        // bind() 单向绑定，和面板宽和高的一半进行绑定
        circle.centerXProperty().bind(pane.widthProperty().divide(2));
        circle.centerYProperty().bind(pane.heightProperty().divide(2));
        circle.setRadius(50);
        circle.setStroke(Color.BLACK);
        circle.setFill(null);

        // pane.getChildren()返回面板中的结点列表
        pane.getChildren().add(circle);
        Scene scene = new Scene(pane, 300, 300);
        primaryStage.setTitle("AttributesBind");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
