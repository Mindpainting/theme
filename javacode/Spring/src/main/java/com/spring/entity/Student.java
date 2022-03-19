package com.spring.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
/*
    所有交给 IoC 容器来管理的类必须有⽆参构造函数，因为 Spring 底
    层是通过反射机制来创建对象，调⽤的是⽆参构造函数
*/
public class Student {
    private Integer id;
    private String name;
    private Integer age;
    private List<Address> addresses;
}
