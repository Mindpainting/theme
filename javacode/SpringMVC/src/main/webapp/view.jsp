<%--
  Created by IntelliJ IDEA.
  User: think
  Date: 2021/8/1
  Time: 10:06
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page isELIgnored="false" %>
<html>
    <head>
        <title>Title</title>
    </head>
    <body>
        <%-- 取 request 域中的对象 --%>
        ${requestScope.user}
        <hr/>
        <%-- 取 session 域中的对象 --%>
        ${sessionScope.user}
    </body>
</html>
