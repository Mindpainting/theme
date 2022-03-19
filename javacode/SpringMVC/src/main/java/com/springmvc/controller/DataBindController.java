package com.springmvc.controller;

import com.springmvc.entity.User;
import com.springmvc.entity.UserList;
import com.springmvc.entity.UserMap;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.util.Arrays;

@Controller
// 加 @ResponseBody 注解不会通过视图解析器，会直接输出到浏览器
@ResponseBody
@RequestMapping("/data")
public class DataBindController {
    // 基本数据类型绑定
    // id 必须有值且为数值，不能为空
    @RequestMapping("/baseType")
    public String baseType(int id) {
        return id + "";
    }

    // 包装类数据类型绑定，id 的值可以是空
    // value = "num"：将 HTTP 请求中名为 num 的参数与 Handler 业务⽅法中的形参 id 进⾏映射
    // required：ture 表示 id 参数必填，false 表示⾮必填。
    // defaultValue = "0"：表示当 HTTP 请求中没有 id 参数时，形参的默认值为 0
    @RequestMapping("/packageType")
    public String packageType(@RequestParam(value = "num", required = false, defaultValue = "0") Integer id) {
        return id + "";
    }

    // 数组绑定
    @RequestMapping( "/array")
    public String array(String[] str) {
        String s = Arrays.toString(str);
        System.out.println(s);
        return s;
    }

    // Spring MVC 不⽀持 List 类型的直接转换，需要包装成 Object
    // User 类必须要有无参构造函数
    @RequestMapping("/list")
    public String list(UserList userList) {
        StringBuilder str = new StringBuilder();
        for (User user : userList.getUserList()) {
            str.append(user);
        }
        return str.toString();
    }

    @RequestMapping("/map")
    public String map(UserMap userMap) {
        StringBuilder str = new StringBuilder();
        for (String key : userMap.getUserMap().keySet()) {
            User user = userMap.getUserMap().get(key);
            str.append(user);
        }
        return str.toString();
    }

    // @RequestBody 和 fastjson 将前端的 json 转换为 Java 对象
    // Java 对象通过 @ResponseBody 转换为 json
    @RequestMapping("/json")
    public User json(@RequestBody User user) {
        System.out.println(user);
        user.setUsername("Asd");
        user.setPassword(121255);
        return user;
    }
}
