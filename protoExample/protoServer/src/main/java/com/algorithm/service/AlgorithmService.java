package com.algorithm.service;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestMapping;


@RestController
public class AlgorithmService {

    @RequestMapping("plus") //http://localhost:8338/plus?x=1&y=2
    public int Addition(int x, int y ) {
        return x+y;
    }

    @RequestMapping("minus") //http://localhost:8338/minus?x=1&y=2
    public int Substraction(int x, int y ) {
        return x-y;
    }
}