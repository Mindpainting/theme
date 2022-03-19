package com.spring;

import com.spring.entity.Student;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SpringPTest {
    @Test
    public void test() {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring-p.xml");
        // 通过 id获取 bean
        Student student = (Student) applicationContext.getBean("student");

        System.out.println(student);
    }
}
