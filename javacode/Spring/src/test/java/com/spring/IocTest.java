package com.spring;

import com.spring.entity.Student;
import com.spring.ioc.MyApplicationContext;
import com.spring.ioc.MyClassPathXmlApplicationContext;
import org.junit.Test;

public class IocTest {
    @Test
    public void test() {
        MyApplicationContext applicationContext = new MyClassPathXmlApplicationContext("spring.xml");
        Student student = (Student) applicationContext.getBean("student");
        System.out.println(student);
    }
}
