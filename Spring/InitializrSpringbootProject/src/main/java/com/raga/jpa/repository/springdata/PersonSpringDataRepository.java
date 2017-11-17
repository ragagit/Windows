/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.raga.jpa.repository.springdata;

import com.raga.jpa.entity.Personh;
import org.springframework.data.jpa.repository.JpaRepository;

/**
 *
 * @author Administrator
 */
public interface PersonSpringDataRepository extends JpaRepository<Personh, Integer>{
    
}
