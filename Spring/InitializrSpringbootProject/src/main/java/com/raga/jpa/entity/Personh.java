/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.raga.jpa.entity;

//import java.io.Serializable;
import java.util.Date;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.NamedQuery;

/**
 *
 * @author Administrator
 */
@Entity
//@Table(name="personh") //We don't need this annotation because class name = table name
@NamedQuery(name="find_all_persons", query="select p from Personh p")
public class Personh {
    
    @Id
    @GeneratedValue //We are asking hibernate to generate it for us
    private int id;
    //@Column(name="name") //no need as the vars natch table columns
    private String name;
    private String location;
    private Date birth_date;

    public Personh(){
        
    }
    public Personh(int id, String name, String location, Date birth_date) {
        this.id = id;
        this.name = name;
        this.location = location;
        this.birth_date = birth_date;
    }

    public Personh(String name, String location, Date birth_date) {
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
