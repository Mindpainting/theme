<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
<%--
  Created by IntelliJ IDEA.
  User: think
  Date: 2021/8/2
  Time: 15:03
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page isELIgnored="false" %>
<html>
    <head>
        <title>Title</title>
    </head>
    <body>
        <form:form modelAttribute="person" action="/validator/enroll" method="post">
            用户名：<form:input path="username"/><form:errors path="username"/><br/>
            密码：<form:password path="password"/><form:errors path="password"/><br/>
            电话：<form:input path="phone"/><form:errors path="phone"/><br/>
            邮箱：<form:input path="email"/><form:errors path="email"/><br/>
            <input type="submit" value="提交"/>
        </form:form>
    </body>
</html>
