/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.aop.springaop;

import org.aspectj.lang.annotation.Pointcut;

/**
 *
 * @author Administrator
 */
public class CommonJoinPointConfig {
        @Pointcut("execution(* com.in28minutes.spring.aop.springaop.data.*.*(..))")
        public void dataLayerExecution(){}
        
        @Pointcut("execution(* com.in28minutes.spring.aop.springaop.business.*.*(..))")
        public void businessLayerExecution(){}
        
        @Pointcut("bean(*dao*)")
        public void beanContainingDao(){}
        
        //@Pointcut("within(* com.in28minutes.spring.aop.springaop.data..*)")
        //public void dataLayerWithWithinExecution(){}
        
        @Pointcut("@annotation(com.in28minutes.spring.aop.springaop.aspect.TimeTrack)")
        public void trackTimeAnnotation(){}

}
