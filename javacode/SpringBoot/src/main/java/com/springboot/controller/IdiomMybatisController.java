package com.springboot.controller;

import com.springboot.entity.Idiom;
import com.springboot.repository.IdiomRepository;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/idiom")
public class IdiomMybatisController {

    @Resource
    private IdiomRepository idiomRepository;

    @GetMapping("/queryAll")
    public List<Idiom> queryAll() {
        return idiomRepository.queryAll();
    }

    @GetMapping("/queryById/{id}")
    public Idiom queryById(@PathVariable("id") Integer id) {
        return idiomRepository.queryById(id);
    }

    @PostMapping("/insert")
    public void insert(@RequestBody Idiom idiom) {
        idiomRepository.insert(idiom);
    }

    @PutMapping("/update")
    public void update(@RequestBody Idiom idiom) {
        idiomRepository.update(idiom);
    }

    @DeleteMapping("/deleteById/{id}")
    public void deleteById(@PathVariable("id") Integer id) {
        idiomRepository.deleteById(id);
    }

}
