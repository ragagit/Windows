package com.raga.jpa;

import com.raga.jpa.entity.Personh;
import com.raga.jpa.repository.springdata.PersonSpringDataRepository;
import java.util.Date;
import java.util.List;
import java.util.logging.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class SpringDataDemoApplication implements CommandLineRunner{

    private static final Logger LOG = Logger.getLogger(SpringDataDemoApplication.class.getName());

        @Autowired
        PersonSpringDataRepository repository;
        
	public static void main(String[] args) {
		SpringApplication.run(SpringDataDemoApplication.class, args);
	}

    @Override
    public void run(String... strings) throws Exception {
        
        try{
//            Personh personh = repository.findById(10001);
//            System.out.println(personh.getName());
//            LOG.log(Level.INFO, "User Id 10001 {}", repository.findById(10001));
 //LOG.log(Level.INFO,"Inserting 10004 -> {}", 
	Personh per=repository.save(new Personh( "Tara", "Berlin", new Date()));
        List<Personh> pers = repository.findAll();
        System.out.println("Added:");
        }
        catch(Exception e){
            throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }
    }
}
