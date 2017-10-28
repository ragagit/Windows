/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.aop.springaop.data;

import org.springframework.stereotype.Repository;

/**
 *
 * @author Administrator
 */
@Repository
public class Dao2 {
    public String retrieveSomething(){
        return "Dao2";
    }
}
