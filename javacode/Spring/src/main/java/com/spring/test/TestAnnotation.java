package com.spring.test;

import com.spring.entity.Computer;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class TestAnnotation {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring-annotation.xml");
        Computer computer = applicationContext.getBean(Computer.class);
        System.out.println(computer.getCpu().getId());
    }
}
