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
public class AssertTest {

    public AssertTest() {
        //System.out.println("AssertTest");
    }

    @BeforeClass
    public static void setUpClass() {
        System.out.println("setUpClass@BeforeClass");
    }

    @AfterClass
    public static void tearDownClass() {
        System.out.println("tearDownClass@AfterClass");
    }

    @Before
    public void setUp() {
        System.out.println("setUp@Before");
    }

    @After
    public void tearDown() {
        System.out.println("tearDown@After");
    }

    // TODO add test methods here.
    // The methods must be annotated with annotation @Test. For example:
    //
    @Test
    public void test() {
        boolean condn = true;
        System.out.println("test");
        assertEquals(true, condn);
        assertTrue(condn);
        //assertFalse(condn);
        //assertNotNull(null);
        //assertArrayEquals(expecteds, actuals);
    }
    @Test
    public void test1() {
        boolean condn = false;
        System.out.println("test1");
        assertEquals(false, condn);
        assertFalse(condn);
        //assertFalse(condn);
        //assertNotNull(null);
        //assertArrayEquals(expecteds, actuals);
    }
}
