/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.aop.springaop.aspect;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.context.annotation.Configuration;

/**
 *
 * @author Administrator
 */
//AOP 
//Configuration
@Aspect // What methods to intercept (Point Guard) and Advice (what to do)
@Configuration
public class MethodExecutionCalculationAspect {

    private static final Logger LOG = Logger.getLogger(MethodExecutionCalculationAspect.class.getName());
    
    //What kind of methods calls I would intercept
    //EXECUTION (* PACKAGE.*.*(..))
    //@Around( value = "execution(* com.in28minutes.spring.aop.springaop.business.*.*(..))")
//    @Around("com.in28minutes.spring.aop.springaop.CommonJoinPointConfig.trackTimeAnnotation()")
//    public void around(ProceedingJoinPoint joinPoint ) throws Throwable{
//        //What to do?
//        //Weaving & Weaver (Framework that implements Weaving)
//        long startTime = System.currentTimeMillis();
//        joinPoint.proceed();
//        long timeTaken = System.currentTimeMillis() - startTime;
//        LOG.log(Level.INFO, "Time taken by {0}", timeTaken);
//    }
      
}
