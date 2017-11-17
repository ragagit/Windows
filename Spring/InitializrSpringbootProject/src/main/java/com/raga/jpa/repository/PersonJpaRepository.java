/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.raga.jpa.repository;

import com.raga.jpa.entity.Personh;
import java.util.List;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.TypedQuery;
import javax.transaction.Transactional;
import org.springframework.stereotype.Repository;

/**
 *
 * @author Administrator
 */
//Repository
@Repository
//Transaction
@Transactional
public class PersonJpaRepository {

    //Connect to database
    @PersistenceContext
    EntityManager entityManager;

    public List<Personh> findAll() {
        TypedQuery<Personh> namedQuery = entityManager.createNamedQuery("find_all_persons", Personh.class);
        return namedQuery.getResultList();
    }

    public Personh findById(int Id) {
        return entityManager.find(Personh.class, Id);
    }

    public Personh update(Personh person) {
        return entityManager.merge(person);
    }

    public Personh insert(Personh person) {
        return entityManager.merge(person);
    }

    public void deletById(int Id) {
        Personh person = findById(Id);
        entityManager.remove(person);
    }
}
