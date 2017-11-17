/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.raga.msql.repository;

import com.raga.msql.entity.Person;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.transaction.Transactional;
import org.springframework.stereotype.Repository;

/**
 *
 * @author Administrator
 */
@Repository
@Transactional
public class PersonRepository {

    @PersistenceContext
    EntityManager entityManager;
    
    public Person updatePerson( Person person ){       
       return  entityManager.merge(person);
    }
    
    public void addPerson( Person person ){
        entityManager.persist(person);
    }
    
}
