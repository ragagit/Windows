/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.mockito.mockitodemo;

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;
import org.mockito.runners.MockitoJUnitRunner;

/**
 *
 * @author Administrator
 */
@RunWith(MockitoJUnitRunner.class)
public class SomeBusinessMockAnnotationsTest {

    @Mock
    DataService dataServiceMock;

    @InjectMocks
    SomeBusinessImpl businessImpl;

    @Test
    public void testFindTheGreatestFromAllData() {
        when(dataServiceMock.retrieveAllData()).thenReturn(new int[]{24, 5, 14});
        Assert.assertEquals(24, businessImpl.findTheGreatestFromAllData());
    }

    @Test
    public void testFindTheGreatestFromNoneData() {
        when(dataServiceMock.retrieveAllData()).thenReturn(new int[]{});
        Assert.assertEquals(Integer.MIN_VALUE, businessImpl.findTheGreatestFromAllData());
    }
//    @Test
//    public void testFindTheGreatestFromOneData() {
//
//        DataService dataServiceMock = mock(DataService.class);
//        when(dataServiceMock.retrieveAllData()).thenReturn(new int[]{27});
//        SomeBusinessImpl businessImpl = new SomeBusinessImpl(dataServiceMock);
//        int result = businessImpl.findTheGreatestFromAllData();
//
//        Assert.assertEquals(27, result);
//    }
}
