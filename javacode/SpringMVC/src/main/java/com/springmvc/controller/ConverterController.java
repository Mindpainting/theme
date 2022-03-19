package com.springmvc.controller;

import com.springmvc.entity.User;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Date;

@RestController
@RequestMapping("/converter")
public class ConverterController {

    @RequestMapping("/date")
    public String date(Date date) {
        return date.toString();
    }

    @RequestMapping("/user")
    public User user(User user) {
        return user;
    }

}
