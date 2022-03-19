<%--
  Created by IntelliJ IDEA.
  User: think
  Date: 2021/7/31
  Time: 20:28
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>Title</title>
    </head>
    <body>
        <form action="/data/map" method="post">
            <input type="text" name="userMap['1'].username"/><br/>
            <input type="text" name="userMap['1'].password"/><br/>
            <input type="text" name="userMap['2'].username"/><br/>
            <input type="text" name="userMap['2'].password"/><br/>
            <input type="submit" value="Submit">
        </form>
    </body>
</html>
