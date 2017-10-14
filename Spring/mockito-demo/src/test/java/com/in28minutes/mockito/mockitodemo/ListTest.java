/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.mockito.mockitodemo;

import java.util.List;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.mockito.Mockito;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

/**
 *
 * @author Administrator
 */
public class ListTest {
    
    public ListTest() {
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
     public void test() {
         List listMock = mock(List.class);
         when(listMock.size()).thenReturn(10).thenReturn(20);
         Assert.assertEquals(10, listMock.size());
         Assert.assertEquals(20, listMock.size());
     }
     @Test
     public void testGet() {
         List listMock = mock(List.class);
         when(listMock.get(0)).thenReturn("Something");
         Assert.assertEquals("Something", listMock.get(0));
         Assert.assertEquals(null, listMock.get(1));
     }
     @Test
     public void testGenericParameter() {
         List listMock = mock(List.class);
         when(listMock.get(Mockito.anyInt())).thenReturn("Something");
         Assert.assertEquals("Something", listMock.get(0));
         Assert.assertEquals(null, listMock.get(1));
     }
}
