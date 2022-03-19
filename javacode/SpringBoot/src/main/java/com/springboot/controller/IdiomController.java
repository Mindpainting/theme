package com.springboot.controller;

import com.springboot.entity.Idiom;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.ArrayList;
import java.util.List;

@Controller
@RequestMapping("/index")
public class IdiomController {

    @GetMapping("/idiom")
    public String idiom(Model model) {
        List<Idiom> idiomList = new ArrayList<>();
        idiomList.add(new Idiom(1, "花好月圆", "flower"));
        idiomList.add(new Idiom(2, "龙争虎斗", "dragon"));
        idiomList.add(new Idiom(3, "老人与海", "sea"));
        model.addAttribute("idiomList", idiomList);
        return "idiomMybatis";
    }
}
