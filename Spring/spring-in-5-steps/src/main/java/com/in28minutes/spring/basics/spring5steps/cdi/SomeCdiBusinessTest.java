/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.basics.spring5steps.cdi;

//import com.in28minutes.spring.basics.springin5steps.basic.BinarySearchImpl;
import static org.junit.Assert.assertEquals;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.mockito.runners.MockitoJUnitRunner;

/**
 *
 * @author Administrator
 */
//Load Context
//@RunWith(SpringRunner.class)
//@ContextConfiguration(classes=SpringIn5StepsBasicApplication.class)
@RunWith(MockitoJUnitRunner.class)
public class SomeCdiBusinessTest {
    
    //Create the mock
    @Mock
    SomeCdiDao daoMock;
    
    @InjectMocks
    SomeCdiBusiness business;
        
    @Test
    public void trstBasicScenario() {
        Mockito.when(daoMock.getData()).thenReturn(new int[] {2,4});
        int actualResult = business.findGreatest();
        assertEquals(4, actualResult);
//        int actualResult;
//        actualResult = business.findGreatest();
//        assertEquals(100, actualResult);
    }
}
