package com.spring.test;

import com.spring.entity.User;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/*
Spring 管理的 bean 是根据 scope 来⽣成的，表示 bean 的作⽤域，共4种，默认值是 singleton。
singleton：单例，表示通过 IoC 容器获取的 bean 是唯⼀的。
prototype：原型，表示通过 IoC 容器获取的 bean 是不同的。
request：请求，表示在⼀次 HTTP 请求内有效。
session：回话，表示在⼀个⽤户会话内有效。

request 和 session 只适⽤于 Web 项⽬，⼤多数情况下，使⽤单例和原型较多。
prototype 模式当业务代码获取 IoC 容器中的 bean 时，Spring 才去调⽤⽆参构造创建对应的 bean。
singleton 模式⽆论业务代码是否获取 IoC 容器中的 bean，Spring 在加载 spring.xml 时就会创建
bean
*/
public class TestScope {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring-scope.xml");
        User user1 = (User)applicationContext.getBean("user2");
        User user2 = (User)applicationContext.getBean("user2");
        System.out.println((user1 == user2));
    }
}
