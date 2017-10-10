package com.in28minutes.spring.basics.springin5steps.xml;

import com.in28minutes.spring.basics.springin5steps.scope.SpringIn5StepsScopeApplication;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.context.support.ClassPathXmlApplicationContext;


public class SpringIn5StepsXMLContextApplication {

	// What are the beans?
	// What are the dependencies of a bean?
	// Where to search for beans? => No need
private static Logger LOGGER = LoggerFactory.getLogger(SpringIn5StepsScopeApplication.class);

	public static void main(String[] args) {

		// BinarySearchImpl binarySearch =
		// new BinarySearchImpl(new QuickSortAlgorithm());
		// Application Context
		ClassPathXmlApplicationContext applicationContext = 
				new ClassPathXmlApplicationContext("appCont.xml");
		
                LOGGER.info("Beans Loaded -> {}", (Object)applicationContext.getBeanDefinitionNames());
                XmlPersonDAO personDao = 
				applicationContext.getBean(XmlPersonDAO.class);
	
		LOGGER.info("{} {}", personDao, personDao.getXmlJdbcConnection());
	        
	}
}

// @Repository refers to Data Layer
// @Controller to the web layer to control resources
// @Service refers to the business logic