package com.in28minutes.spring.basics.spring5steps.cdi;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import org.springframework.context.ApplicationContext;

@SpringBootApplication
//Next two lines are for Spring only not Boot
//@Configuration
//@ComponentScan
public class SpringIn5StepsCdiApplication {

    //private static final Logger LOGGER = LoggerFactory.getLogger(SpringIn5StepsCdiApplication.class);

    public static void main(String[] args) {

        ApplicationContext applicationContext=
                SpringApplication.run(SpringIn5StepsCdiApplication.class, args);
        //Next line is for Spring
        // AnnotationConfigApplicationContext applicationContext= new AnnotationConfigApplicationContext(SpringIn5StepsCdiApplication.class);
        //Getting the bean from the application context. Singleton - same bean on all request
        SomeCdiBusiness business
                = applicationContext.getBean(SomeCdiBusiness.class);
        
        //LOGGER.info("{} dao-{}", business, business.getSomeCdiDao()); 
        System.out.println(business);
        
        //applicationContext.close();

    }
}
