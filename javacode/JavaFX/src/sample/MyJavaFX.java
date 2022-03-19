package sample;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class MyJavaFX extends Application {
    @Override
    public void start(Stage primaryStage) {
        Pane pane = new Pane(new Line(50, 100, 150, 100));
        Scene scene = new Scene(pane, 200, 200);
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}

