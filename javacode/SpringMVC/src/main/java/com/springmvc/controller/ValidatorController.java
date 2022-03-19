package com.springmvc.controller;

import com.springmvc.entity.Person;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.validation.Valid;

@Controller
@RequestMapping("/validator")
public class ValidatorController {

    @GetMapping("/enroll")
    public String enroll(Model model) {
        model.addAttribute("person", new Person());
        return "enroll";
    }

    @PostMapping("/enroll")
    public String enroll(@Valid Person person, BindingResult bindingResult) {
        if (bindingResult.hasErrors()) {
            return "enroll";
        }
        return "index";
    }
}
