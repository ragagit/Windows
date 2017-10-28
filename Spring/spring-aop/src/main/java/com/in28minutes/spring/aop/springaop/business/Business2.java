/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.aop.springaop.business;

import com.in28minutes.spring.aop.springaop.data.Dao2;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 *
 * @author Administrator
 */
@Service
public class Business2 {
    
    @Autowired
    private Dao2 dao2;
    
    public String calculateSomething(){
        //Business Logic
        String res;
        res = dao2.retrieveSomething();
       return res;
    }
}
