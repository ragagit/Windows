/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.junit;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Administrator
 */
public class MyMathTest {
    
    public MyMathTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    // TODO add test methods here.
    // The methods must be annotated with annotation @Test. For example:
    //
    @Test
    public void sum_with3numbers() {
        MyMath myMath = new MyMath();
        int result = myMath.sum(new int[] {1,2,3});
        
        assertEquals(6, result);
    }
    
        @Test
    public void sum_with1numbers() {
        MyMath myMath = new MyMath();  
        assertEquals(3, myMath.sum(new int[] {3}));
    }
}
