<%@page import="java.util.Date"%>
<html>
<head>
<title>Yahoo!!</title>
</head>
<body>
    My JSP ${name}
    <%
        Date date = new Date();
        %>
        <div> Current Date: <%= date %></div>
    <p><font color="red">${errorMessage}</font></p>
    <form action="/login.do" method="POST">
        Name : <input name="name" type="text" /> Password : <input name="password" type="password" /> <input type="submit" />
    </form>
</body>
</html>