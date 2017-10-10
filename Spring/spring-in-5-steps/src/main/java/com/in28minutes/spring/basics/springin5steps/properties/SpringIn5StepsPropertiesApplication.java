package com.in28minutes.spring.basics.springin5steps.properties;

import com.in28minutes.spring.basics.springin5steps.scope.SpringIn5StepsScopeApplication;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.PropertySource;


@SpringBootApplication
@PropertySource("classpath:app.properties")
public class SpringIn5StepsPropertiesApplication {

	// What are the beans?
	// What are the dependencies of a bean?
	// Where to search for beans? => No need
private static Logger LOGGER = LoggerFactory.getLogger(SpringIn5StepsScopeApplication.class);

	public static void main(String[] args) {

		// BinarySearchImpl binarySearch =
		// new BinarySearchImpl(new QuickSortAlgorithm());
		// Application Context
		ApplicationContext applicationContext = 
				SpringApplication.run(SpringIn5StepsPropertiesApplication.class, args);
		//Getting the bean from the application context. Singleton - same bean on all request
                SomeExternalService service = 
				applicationContext.getBean(SomeExternalService.class);
		
		System.out.println(service.returnServiceUrl());
                
            
                
	}
}