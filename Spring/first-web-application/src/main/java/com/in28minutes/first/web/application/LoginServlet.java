package com.in28minutes.first.web.application;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = "/login.do")
public class LoginServlet extends HttpServlet {
    
@Override
	protected void doGet(HttpServletRequest request,
			HttpServletResponse response) throws IOException, ServletException {
            
            PrintWriter out = response.getWriter();
            out.println("<html>");          
            out.println("<head>");
            out.println("<title>Yahoo!!!!</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("My First Servlet");
            out.println("</body>");                                  
            out.println("</html>");
            
        }

    

//	private LoginService service = new LoginService();
//
//	@Override
//	protected void doGet(HttpServletRequest request,
//			HttpServletResponse response) throws IOException, ServletException {
//		request.getRequestDispatcher("/WEB-INF/views/login.jsp").forward(
//				request, response);
//	}
//
//	@Override
//	protected void doPost(HttpServletRequest request,
//			HttpServletResponse response) throws IOException, ServletException {
//		String name = request.getParameter("name");
//		String password = request.getParameter("password");
//
//		boolean isValidUser = service.validateUser(name, password);
//
//		if (isValidUser) {
//			request.setAttribute("name", name);
//			request.getRequestDispatcher("/WEB-INF/views/welcome.jsp").forward(
//					request, response);
//		} else {
//			request.setAttribute("errorMessage", "Invalid Credentials!!");
//			request.getRequestDispatcher("/WEB-INF/views/login.jsp").forward(
//					request, response);
//		}
//	}

}