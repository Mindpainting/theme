<%--
  Created by IntelliJ IDEA.
  User: think
  Date: 2021/7/31
  Time: 22:42
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>Title</title>
        <script type="text/javascript" src="js/jquery-3.6.0.js"></script>
        <script type="text/javascript">
            $(function () {
                const user = {
                    "username": "THY",
                    "password": 122344
                };
                $.ajax({
                    url: "/data/json",
                    // JSON 数据必须⽤ JSON.stringify() ⽅法转换成字符串，应为 HTTP 请求只能传字符串
                    data: JSON.stringify(user),
                    type: "POST",
                    contentType: "application/json;charset=UTF-8",
                    dataType: "JSON",
                    success: function (data) {
                        alert(data.username + "---" + data.password);
                    }
                })
            });
        </script>
    </head>
    <body>

    </body>
</html>
