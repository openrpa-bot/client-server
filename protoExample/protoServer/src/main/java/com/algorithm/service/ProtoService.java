package com.algorithm.service;

import com.algorithm.dto.Request;
import com.algorithm.dto.Response;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
//import org.springframework.stereotype.Service;

@RestController
public class ProtoService {

    @RequestMapping("/") //http://localhost:8338
    public Response index() {
        return Response.newBuilder().setResult(2021).build();
    }


    @RequestMapping("AdditionRequest") //http://localhost:8338/AdditionRequest?x=1&y=2
    public Response AdditionRequest(Request request ) {
        return Response.newBuilder().setResult(request.getA()+request.getB()).build();
    }

}