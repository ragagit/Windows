/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.in28minutes.springboot.basics.springbootin10steps;

import java.util.Arrays;
import java.util.List;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 *
 * @author Administrator
 */
@RestController
public class BooksController {
    
    @GetMapping("/books")
    public List<Book> getAllBooks(){
        return Arrays.asList(new Book( 1, "Spring", "raga"));
    } 
}
