<%--
  Created by IntelliJ IDEA.
  User: think
  Date: 2021/7/31
  Time: 10:38
  To change this template use File | Settings | File Templates.
--%>
<%@page contentType= "text/html; charset=utf-8" pageEncoding= "utf-8" %>
<html>
    <head>
        <title>Register</title>
    </head>
    <body>
        <form action="/hello/save" method="post">
            Username: <label><input type="text" name="username"/></label><br>
            Password:<label><input type="text" name="password"/></label><br>
            Address:<label><input type="text" name="address.province"/></label><br>
            <input type="submit" name="Register"><br>
        </form>
    </body>
</html>
