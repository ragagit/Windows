package com.raga.msql;

import com.raga.msql.entity.Person;
import com.raga.msql.repository.PersonRepository;
import java.util.Date;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class HmsqlApplication implements CommandLineRunner {

    @Autowired
    PersonRepository repository;
    
	public static void main(String[] args) {
		SpringApplication.run(HmsqlApplication.class, args);
	}

    @Override
    public void run(String... strings) throws Exception {
        
        try{           
            Person person = repository.updatePerson( new Person("Laura", "Hamilton", new Date()) );
            repository.addPerson( new Person("Donna", "Wisconsin", new Date()) );
        }
        catch( Exception e){
            throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }
    }
}
