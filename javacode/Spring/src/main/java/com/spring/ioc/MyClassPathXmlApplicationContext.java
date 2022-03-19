package com.spring.ioc;

import org.dom4j.Document;

import org.dom4j.DocumentException;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

// IOC 底层原理实现
// dom4j是一个Java的 XML API
public class MyClassPathXmlApplicationContext implements MyApplicationContext {
    private final Map<String, Object> ioc = new HashMap<>();

    public MyClassPathXmlApplicationContext(String path) {
        try {
            // 解析 XML
            SAXReader saxReader = new SAXReader();
            Document document = saxReader.read("./src/main/resources/" + path);

            Element rootElement = document.getRootElement();

            // 这个是 <beans></beans> 下的迭代器，迭代每一个 bean
            Iterator<Element> rootElementIterator = rootElement.elementIterator();
            while (rootElementIterator.hasNext()) {
                Element bean = rootElementIterator.next();
                // 获取 bean 的 id
                String id = bean.attributeValue("id");
                // 获取 bean 的 class
                String className = bean.attributeValue("class");

                // 反射动态创建对象
                Class<?> clazz = Class.forName(className);
                // 获取构造函数
                Constructor<?> constructor = clazz.getConstructor();
                // 创建对象
                Object object = constructor.newInstance();

                // 这个是 <bean></bean> 下的迭代器，迭代每一个 bean 的属性
                Iterator<Element> beanIterator = bean.elementIterator();

                // 给属性赋值
                while (beanIterator.hasNext()) {
                    Element property = beanIterator.next();
                    // 获取属性值
                    String propertyName = property.attributeValue("name");
                    String propertyValue = property.attributeValue("value");

                    // 获取 setter 方法，setId，setName
                    String methodName = "set" + propertyName.substring(0, 1).toUpperCase() + propertyName.substring(1);

                    // 获取属性
                    // getDeclaredFields()获取所有的成员变量，不管修饰符
                    // field: private java.lang.Integer com.spring.entity.People.id
                    // field: private java.lang.String com.spring.entity.People.name
                    Field field = clazz.getDeclaredField(propertyName);

                    Method method = clazz.getMethod(methodName, field.getType());

                    // 类型转换
                    Object fieldType = null;
                    if ("java.lang.String".equals(field.getType().getName())) {
                        fieldType = propertyValue;
                    }
                    if ("java.lang.Integer".equals(field.getType().getName())) {
                        fieldType = Integer.parseInt(propertyValue);
                    }
                    if ("java.lang.Double".equals(field.getType().getName())) {
                        fieldType = Double.parseDouble(propertyValue);
                    }
                    method.invoke(object, fieldType);
                }
                ioc.put(id, object);
            }
        } catch (DocumentException | InstantiationException | ClassNotFoundException | NoSuchMethodException | IllegalAccessException | InvocationTargetException | NoSuchFieldException e) {
            e.printStackTrace();
        }
    }

    @Override
    public Object getBean(String id) {
        return ioc.get(id);
    }
}
