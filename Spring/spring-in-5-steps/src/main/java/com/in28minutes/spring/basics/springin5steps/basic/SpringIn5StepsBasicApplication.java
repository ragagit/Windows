package com.in28minutes.spring.basics.springin5steps.basic;

import com.in28minutes.spring.basics.springin5steps.scope.SpringIn5StepsScopeApplication;
import javax.annotation.PostConstruct;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.config.ConfigurableBeanFactory;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Scope;

//Ctrl+Space for code completion
//Ctrl+Shift+Space for documentation
//Ctrl+Shift+I to resolve import conflicts
//Alt+Insert for code generation
//Type /** then enter above the method without comments
//Alt+Shift+F to format the document
//Notes: Maven life cycle
// Verify, Compile, Test, Inetgration, package, Insatll, Deployment
// Grouip, Artifact, Dependencies, Parent, Repository
@SpringBootApplication
@Scope(ConfigurableBeanFactory.SCOPE_PROTOTYPE) //This return a different bean for each request using getBean
public class SpringIn5StepsBasicApplication {

	// What are the beans?
	// What are the dependencies of a bean?
	// Where to search for beans? => No need
private static Logger LOGGER = LoggerFactory.getLogger(SpringIn5StepsScopeApplication.class);

	public static void main(String[] args) {

		// BinarySearchImpl binarySearch =
		// new BinarySearchImpl(new QuickSortAlgorithm());
		// Application Context
		ApplicationContext applicationContext = 
				SpringApplication.run(SpringIn5StepsBasicApplication.class, args);
		//Getting the bean from the application context. Singleton - same bean on all request
                BinarySearchImpl binarySearch = 
				applicationContext.getBean(BinarySearchImpl.class);
		int result = 
				binarySearch.binarySearch(new int[] { 12, 4, 6 }, 3);
		System.out.println("The result is:" + result);
                
            
                
	}
}