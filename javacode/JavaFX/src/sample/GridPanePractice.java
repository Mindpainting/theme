package sample;

import javafx.application.Application;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class GridPanePractice extends Application {
    @Override
    public void start(Stage primaryStage) {
        GridPane gridPane = new GridPane();
        gridPane.setAlignment(Pos.CENTER);
        gridPane.setPadding(new Insets(11.5, 12.5, 13.5, 14.5));
        // 结点间的水平间距
        gridPane.setHgap(5.5);
        // 结点间的垂直间距
        gridPane.setVgap(5.5);

        // 添加多个结点到指定的列
        gridPane.addColumn(0, new Label("First Name:"), new Label("MI:"), new Label("Last Name:"));
        gridPane.addColumn(1, new TextField(), new TextField(), new TextField());
        Button button = new Button("Add Name");
        gridPane.add(button, 1, 3);

        // 为单元格中的子结点设置水平对齐
        GridPane.setHalignment(button, HPos.RIGHT);

        Scene scene = new Scene(gridPane);
        primaryStage.setTitle("ShowGridPane");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
