package com.algorithm.service;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestMapping;
//import org.springframework.stereotype.Service;

@RestController
public class AlgorithmService {

    @RequestMapping("/") //http://localhost:8338
    public String index() {
        return "Greetings from Spring Boot!";
    }


    @RequestMapping("plus") //http://localhost:8338/plus?x=1&y=2
    public int Addition(int x, int y ) {
        return x+y;
    }

    @RequestMapping("minus") //http://localhost:8338/minus?x=1&y=2
    public int Substraction(int x, int y ) {
        return x-y;
    }
}