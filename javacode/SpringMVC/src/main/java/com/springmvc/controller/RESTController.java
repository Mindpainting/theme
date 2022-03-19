package com.springmvc.controller;

import com.springmvc.entity.User;
import com.springmvc.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletResponse;
import java.util.Collection;

@RestController
@RequestMapping("/rest")
public class RESTController {

    @Resource
    private UserRepository userRepository;

    @GetMapping("/queryAll")
    public Collection<User> queryAll(HttpServletResponse response) {
        response.setContentType("text/json;charset=UTF-8");
        return userRepository.queryAll();
    }

    @GetMapping("/queryById/{id}")
    public User findById(@PathVariable("id") int id) {
        return userRepository.queryById(id);
    }

    @PostMapping("/save")
    public void save(@RequestBody User user) {
        userRepository.saveOrUpdate(user);
    }

    @PutMapping("/update")
    public void update(@RequestBody User user) {
        userRepository.saveOrUpdate(user);
    }

    @DeleteMapping("/deleteById/{id}")
    public void deleteById(@PathVariable("id") int id) {
        userRepository.deleteById(id);
    }
}
