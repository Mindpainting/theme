package com.springmvc.controller;

import com.springmvc.entity.User;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.util.Map;

@Controller
@RequestMapping("/view")
public class ViewController {

    @RequestMapping("/map")
    public String map(Map<String, User> map) {
        User user = new User("YYY", 132456, null);
        map.put("user", user);
        return "view";
    }

    @RequestMapping("/model")
    public String model(Model model) {
        User user = new User("YYY", 132456, null);
        model.addAttribute("user", user);
        return "view";
    }

    @RequestMapping("/modelAndView")
    public ModelAndView modelAndView () {
        ModelAndView modelAndView = new ModelAndView();
        User user = new User();
        user.setUsername("MMM");
        user.setUsername("222");
        modelAndView.addObject("user", user);
        modelAndView.setViewName("view");
        return modelAndView;
    }

    // 需要在 pom.xml 中导入 servlet-api
    @RequestMapping("/request")
    public String request(HttpServletRequest request) {
        User user = new User("YYY", 132456, null);
        request.setAttribute("user", user);
        return "view";
    }

    @RequestMapping("/session")
    public String session(HttpSession session) {
        User user = new User("SSS", 132456, null);
        session.setAttribute("user", user);
        return "view";
    }

    @RequestMapping("session_")
    public String session_(HttpServletRequest request) {
        HttpSession session = request.getSession();
        User user = new User("SSS", 132456, null);
        session.setAttribute("user", user);
        return "view";
    }
}
