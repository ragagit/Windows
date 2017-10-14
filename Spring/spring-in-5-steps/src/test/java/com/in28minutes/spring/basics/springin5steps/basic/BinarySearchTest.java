/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.basics.springin5steps.basic;

import static org.junit.Assert.assertEquals;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringRunner;

/**
 *
 * @author Administrator
 */
//Load Context
@RunWith(SpringRunner.class)
@ContextConfiguration(classes=SpringIn5StepsBasicApplication.class)
public class BinarySearchTest {
    
    @Autowired
    BinarySearchImpl binarySearch;
        
    @Test
    public void trstBasicScenario() {
        int actualResult = binarySearch.binarySearch(new int[] {}, 5);
        assertEquals(3, actualResult);
    }
}
