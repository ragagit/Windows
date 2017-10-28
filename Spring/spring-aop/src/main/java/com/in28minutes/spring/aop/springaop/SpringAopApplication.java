package com.in28minutes.spring.aop.springaop;

import com.in28minutes.spring.aop.springaop.business.Business1;
import com.in28minutes.spring.aop.springaop.business.Business2;
import java.util.logging.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class SpringAopApplication implements CommandLineRunner{

    private static final Logger LOG = Logger.getLogger(SpringAopApplication.class.getName());

    
    @Autowired
    Business1 business1;
    
    @Autowired
    Business2 business2;
    
	public static void main(String[] args) {
		SpringApplication.run(SpringAopApplication.class, args);
	}

    @Override
    public void run(String... strings) throws Exception { 
        
        try{
            LOG.info("Business1:"+business1.calculateSomething());
            LOG.info("Business2:"+business1.calculateSomething());
        }
        catch(Exception e){
         throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }
        
    }
}
