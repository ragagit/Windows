/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.basics.springin5steps.scope;

import org.springframework.beans.factory.config.ConfigurableBeanFactory;
import org.springframework.context.annotation.Scope;
import org.springframework.context.annotation.ScopedProxyMode;
import org.springframework.stereotype.Component;

/**
 *
 * @author Administrator
 */
@Component
//This scope doesn't return a different bean per called as PersonDOA doesn't
//have SCOPE.Prototype. We just want to create an diff instance of Jdbc not personDOA
//@Scope(ConfigurableBeanFactory.SCOPE_PROTOTYPE)
//So we use proxyMode when one component is Prototype and the second is not
@Scope(value = ConfigurableBeanFactory.SCOPE_PROTOTYPE,
        proxyMode = ScopedProxyMode.TARGET_CLASS)
class JdbcConnection {

    public JdbcConnection() {
        System.out.println("JdbcConstructor");
    }

}
