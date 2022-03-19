package com.spring.entity;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class User {
    private Integer id;
    private String name;

    public User() {
        System.out.println("无参构造函数被调用");
    }
}
