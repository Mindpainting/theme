package com.spring;

import com.spring.entity.Student;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class EntityTest {
    @Test
    public void test() {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring.xml");
        // 通过 id获取 bean
        Student student = (Student) applicationContext.getBean("student");

        /*// 通过运行时类获取 bean
        Address address = applicationContext.getBean(Address.class);*/

        System.out.println(student);
    }
}
