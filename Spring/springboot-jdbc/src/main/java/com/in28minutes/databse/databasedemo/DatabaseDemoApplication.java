package com.in28minutes.databse.databasedemo;

import com.in28minutes.databse.databasedemo.entity.Person;
import com.in28minutes.databse.databasedemo.jdbc.PersonJdbcDao;
import java.util.Date;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class DatabaseDemoApplication implements CommandLineRunner{

    private static final Logger LOG = Logger.getLogger(DatabaseDemoApplication.class.getName());

    @Autowired
    PersonJdbcDao dao;
    
	public static void main(String[] args) {
		SpringApplication.run(DatabaseDemoApplication.class, args);
	}

    @Override
    public void run(String... strings) throws Exception {
        
        try{
            List<Person> persons;
            persons = dao.findAll();
            persons.forEach((person) -> {
                System.out.println(person.getName());
            });
            
            List<Person> persons1;
            persons1 = dao.findAll_();
            persons1.forEach((person) -> {
                System.out.println(person.getName());
            });
            
//            Person person;
//            person = dao.findById(10001);
//            System.out.println("Users with id 10001:" + person.getName());
            
            //int rowsDeleted = dao.deleteById(10003);
            //System.out.println("Rows deleted id 10003:" + rowsDeleted);
            
            //LOG.log(Level.INFO,"Inserting 10004 -> {}", 
				//dao.insert(new Person(10004, "Tara", "Berlin", new Date())));
		
		//LOG.log(Level.INFO, "Update 10003 -> {}", 
		//		dao.update(new Person(10003, "Pieter", "Utrecht", new Date())));
        }
        catch( Exception e){
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }
    }
}
