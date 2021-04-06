package cn.itcast.servlet;

import java.io.IOException;

import javax.servlet.GenericServlet;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;

public class HelloWorldServlet extends GenericServlet {

	public void init(ServletConfig config) throws ServletException {
		System.out.println("hello");
	}

	public void service(ServletRequest request, ServletResponse respones) 
			throws ServletException {
		System.out.println("them");
	}

	public void destroy() {
		System.out.println("miss me?");
	}

}
