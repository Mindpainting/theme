package com.springmvc.controller;

import com.springmvc.entity.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@Controller
@RequestMapping("/hello")
public class HelloController {

    // 普通风格
    @RequestMapping(value = "/index", method = RequestMethod.GET, params = {"username", "password"})
    public String index(@RequestParam("username") String param1, @RequestParam("password") Integer param2) {
        System.out.println(param1 + " " + param2);
        return "index";
    }

    // rest 风格
    @RequestMapping("/rest/{username}/{password}")
    public String rest(@PathVariable("username") String p1, @PathVariable("password") Integer p2) {
        System.out.println(p1 + " " + p2);
        return "index";
    }

    // 级联对象自动绑定
    @RequestMapping(value = "/save", method = RequestMethod.POST)
    @ResponseBody
    public String save(User user) {
        System.out.println(user);
//        return "index";
        return user.toString();
    }


    // 转发
    @RequestMapping("/forward")
    public String forward() {
        return "forward:/index.jsp";
    }

    // 重定向
    @RequestMapping("/redirect")
    public String redirect() {
        return "redirect:/index.jsp";
    }

}
