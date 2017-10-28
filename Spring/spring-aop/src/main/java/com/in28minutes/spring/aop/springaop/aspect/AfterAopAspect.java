/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.aop.springaop.aspect;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.AfterThrowing;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.context.annotation.Configuration;


/**
 *
 * @author Administrator
 */
//AOP 
//Configuration
@Aspect // What methods to intercept (PointCut) and Advice (what to do)
@Configuration
public class AfterAopAspect {

    private static final Logger LOG = Logger.getLogger(AfterAopAspect.class.getName());
    
    //What kind of methods calls I would intercept
    //EXECUTION (* PACKAGE.*.*(..))
    @AfterReturning( value = "execution(* com.in28minutes.spring.aop.springaop.business.*.*(..))",
            returning = "result")
    public void afterReturning(JoinPoint joinPoint, Object result ){
        //What to do?
        //Weaving & Weaver (Framework that implements Weaving)
        LOG.log(Level.INFO, "Returned with value:" + result);
    }
    @AfterThrowing( value = "execution(* com.in28minutes.spring.aop.springaop.business.*.*(..))",
            throwing = "exception")
    public void afterThrowing(JoinPoint joinPoint ){
        //What to do?
        //Weaving & Weaver (Framework that implements Weaving)
        LOG.log(Level.INFO, "threw exception {0}", joinPoint);
    }
@After( "com.in28minutes.spring.aop.springaop.CommonJoinPointConfig.dataLayerExecution()")
    public void after(JoinPoint joinPoint ){
        //What to do?
        //Weaving & Weaver (Framework that implements Weaving)
        LOG.log(Level.INFO, "After execution {0}", joinPoint);
    }        
}
