package com.spring.entity;

import lombok.Data;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

@Data
@Component
public class Computer {
    @Resource
    private Cpu cpu;
}
