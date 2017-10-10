/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.spring.basics.spring5steps.cdi;

import javax.inject.Inject;
import javax.inject.Named;

/**
 *
 * @author Administrator
 */
//@Component -> @Name for CDI which defines the standars for annotation. Spring implemnts them
@Named
public class SomeCdiBusiness {
    
    //@Autowired -> @Inject for CDI
    @Inject
    SomeCdiDao someCdiDao;

    public SomeCdiDao getSomeCdiDao() {
        return someCdiDao;
    }

    public void setSomeCdiDao(SomeCdiDao someCdiDao) {
        this.someCdiDao = someCdiDao;
    }
}
