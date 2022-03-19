package com.springboot.controller;

import com.springboot.entity.Merchandise;
import com.springboot.entity.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.servlet.ModelAndView;

import java.util.ArrayList;
import java.util.List;

@Controller
public class ThymeleafController {

    @GetMapping("/thymeleaf1")
    public ModelAndView fun1(){
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("thymeleaf");
        modelAndView.addObject("name", "泠鸢");

        modelAndView.addObject("welcome", "Welcome to our <b>fantastic</b> grocery store!");

        modelAndView.addObject("user", new User("竹叶青", "123456"));

        List<Merchandise> merchandise = new ArrayList<>();
        merchandise.add(new Merchandise(1001, "生活", 39.9, 10000));
        merchandise.add(new Merchandise(1002, "手机", 2999.9, 8000));
        merchandise.add(new Merchandise(1003, "电脑", 5999.9, 5000));
        modelAndView.addObject("merchandise", merchandise);

        modelAndView.addObject("score", 85);
        modelAndView.addObject("score");
        return modelAndView;
    }

    @GetMapping("/thymeleaf2")
    public String fun2(){
        return "index";
    }

    // 为直接访问静态资源做映射
    // 访问 thymeleaf.html 路径
    @GetMapping("/action/{url}")
    public String fun3(@PathVariable("url") String url){
        return url;
    }

    @PostMapping("/action")
    public String action(){
        return "action";
    }
}
