/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.databse.databasedemo.entity;

import java.util.Date;

/**
 *
 * @author Administrator
 */
public class Person {
    private int id;
    private String name;
    private String location;
    private Date birth_date;

    public Person(){
        
    }
    public Person(int id, String name, String location, Date birth_date) {
        this.id = id;
        this.name = name;
        this.location = location;
        this.birth_date = birth_date;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public Date getBirth_date() {
        return birth_date;
    }

    public void setBirth_date(Date birth_date) {
        this.birth_date = birth_date;
    }

    @Override
    public String toString() {
        return "\nPerson{" + "id=" + id + ", name=" + name + ", location=" + location + ", birth_date=" + birth_date + '}';
    }
    
    
}
