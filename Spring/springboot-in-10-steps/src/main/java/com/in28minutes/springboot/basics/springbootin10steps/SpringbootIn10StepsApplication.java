package com.in28minutes.springboot.basics.springbootin10steps;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

//Goals
//Enable building production ready applications quickly
//Provide common non-functional features 
//- embedded servers
//- metrics
//- health checks
//- externalized configuration
//
//What Spring Boot is NOT!
//ZERO code generation
//Neither an application server nor a web server
//
//Features
//Quick Starter Projects with Auto Configuration
// - Web
// - JPA
//Embedded Servers - Tomcat, Jetty or Undertow
//Production-ready features
// - metrics and health checks 
// - externalized configuration

@SpringBootApplication
public class SpringbootIn10StepsApplication {

	public static void main(String[] args) {
		ApplicationContext applicationContext = 
                        SpringApplication.run(SpringbootIn10StepsApplication.class, args);
                for( String name : applicationContext.getBeanDefinitionNames()){
                    System.out.println("bean:" + name);
                }        
	}
}
