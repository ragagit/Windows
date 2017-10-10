package com.in28minutes.spring.basics.springin5steps.scope;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.config.ConfigurableBeanFactory;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Scope;

@SpringBootApplication
//@Scope(ConfigurableBeanFactory.SCOPE_PROTOTYPE) //This return a different bean for each request using getBean
//By default this classes are looked up in ..scope package, if we want to scan on dif pkg
//@ComponentScan("com.in28minutes.spring.basics.springin5steps.basic")
public class SpringIn5StepsScopeApplication {

    private static Logger LOGGER = LoggerFactory.getLogger(SpringIn5StepsScopeApplication.class);

    public static void main(String[] args) {

        ApplicationContext applicationContext
                = SpringApplication.run(SpringIn5StepsScopeApplication.class, args);
        //Getting the bean from the application context. Singleton - same bean on all request
        PersonDAO personDAO
                = applicationContext.getBean(PersonDAO.class);
        PersonDAO personDAO2
                = applicationContext.getBean(PersonDAO.class);

        LOGGER.info("{}", personDAO);
        LOGGER.info("{}", personDAO.getJdbcConnection());

        LOGGER.info("{}", personDAO2);
        LOGGER.info("{}", personDAO2.getJdbcConnection());

    }
}
