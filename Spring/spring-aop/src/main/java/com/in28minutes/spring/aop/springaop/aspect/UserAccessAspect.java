/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.aop.springaop.aspect;

import java.util.logging.Logger;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.springframework.context.annotation.Configuration;

/**
 *
 * @author Administrator
 */
//AOP 
//Configuration
@Aspect // What methods to intercept (Point Guard) and Advice (what to do)
@Configuration
public class UserAccessAspect {

    private static final Logger LOG = Logger.getLogger(UserAccessAspect.class.getName());
    
    //What kind of methods calls I would intercept
    //EXECUTION (* PACKAGE.*.*(..))
    @Before("execution(* com.in28minutes.spring.aop.springaop.business.*.*(..))")
    public void before(JoinPoint joinPoint ){
        //What to do?
        //Weaving & Weaver (Framework that implements Weaving)
        LOG.info("Check for user access");
        LOG.info("Intercepted Method in business package");
    }
    
}
