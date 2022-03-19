package com.spring.ioc;

import com.spring.entity.People;

public class TestIoc {
    public static void main(String[] args) {
        MyApplicationContext applicationContext = new MyClassPathXmlApplicationContext("spring-ioc.xml");
        People people = (People) applicationContext.getBean("people");
        System.out.println(people);
    }
}
