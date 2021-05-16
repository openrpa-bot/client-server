package com.algorithm.service;

import com.algorithm.dto.Request;
import com.algorithm.dto.Response;
import com.google.protobuf.InvalidProtocolBufferException;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
//import org.springframework.stereotype.Service;

@RestController
public class ProtoService {

    @RequestMapping("/") //http://localhost:8338
    public Response index() {
        return Response.newBuilder().setResult(2021).build();
    }

    @RequestMapping("AR") //http://localhost:8338/AR?byteRequest=
    public Response AR(byte[] byteRequest)  {
        Request request = Request.newBuilder().setA(1).setB(1).build();
        try {
            request = Request.parseFrom(byteRequest);
        }catch(InvalidProtocolBufferException ex){

        }
        return Response.newBuilder().setResult(request.getA()+request.getB()+1).build();
    }

    @RequestMapping("AdditionRequest") //http://localhost:8338/AdditionRequest?request=
    public Response AdditionRequest(Request request ) {
        return Response.newBuilder().setResult(request.getA()+request.getB()+1).build();
    }

    @RequestMapping("AddMe") //http://localhost:8338/AddMe?x=1&y=2
    public Response AddMe(int x, int y ) {
        return Response.newBuilder().setResult(x+y).build();
    }
}