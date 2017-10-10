package com.in28minutes.spring.basics.springin5steps.basic;

import com.in28minutes.spring.basics.springin5steps.scope.SpringIn5StepsScopeApplication;
import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;


@Component
public class BinarySearchImpl {

private final Logger LOGGER = LoggerFactory.getLogger(this.getClass());

    @Autowired
    //@Qualifier("Bubble") //Autowire by Qualifier
    private SortAlgorithm SortAlgorithm;
    //The other option to select the algorithm is to use Autowire by name
    //private SortAlgorithm bubbleSortAlgorithm;

    public int binarySearch(int[] numbers, int numberToSearchFor) {

        int[] sortedNumbers = SortAlgorithm.sort(numbers);
        System.out.println(SortAlgorithm);
        // Search the array
        return 3;
    }
    @PostConstruct
    public void postConstruct(){
        LOGGER.info("PostConstruct called");
    }
    
    @PreDestroy
    public void preDestroy(){
        LOGGER.info("preDestroy has been called");
    }

}


