package com.spring.entity;

import lombok.Data;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
@Data
@Component
public class Cpu {
    //相当于  <property name="id" value="10001"/>
    @Value("10001")
    private Integer id;
    @Value("Intel")
    private String type;
}
