<%--
  Created by IntelliJ IDEA.
  User: think
  Date: 2021/7/31
  Time: 13:04
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>List</title>
    </head>
    <body>
        <form action="/data/list" method="post">
            <label>
                <input type="text" name="userList[0].username"/>
            </label><br/>
            <label>
                <input type="text" name="userList[0].password"/>
            </label><br/>
            <label>
                <input type="text" name="userList[1].username"/>
            </label><br/>
            <label>
                <input type="text" name="userList[1].password"/>
            </label><br/>
            <label>
                <input type="text" name="userList[2].username"/>
            </label><br/>
            <label>
                <input type="text" name="userList[2].password"/>
            </label><br/>
            <input type="submit" value="Submit">
        </form>
    </body>
</html>
