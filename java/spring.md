

### 两大特性

----

- IOC（Inversion of Control）**（工厂模式）**
  - 是一种设计思想，DI（依赖注入）是实现IOC的一种方法
  - 控制反转是一种通过描述（XML或注解）并通过第三方去生产或获取特定对象的方式。在Spring中实现控制反转的是IOC容器，其实现方法是依赖注入（Dependency Injection，DI）
- AOP（Aspect Oriented Programming）**（代理模式）**



### IOC创建对象的方式

---

> 默认使用无参构造函数创建对象



### 从 IOC 容器中获取 bean

----

- 通过 id 取值（需要强制类型转换）

```java
public static void main(String[] args) {
    ApplicationContext applicationContext = new ClassPathXmlApplicationContext("xxx.xml");
    Student student = (Student)applicationContext.getBean("student");
    System.out.println(student);
}
```

- 通过类型取值（传什么类型，返回什么类型）

```java
public static void main(String[] args) {
    ApplicationContext applicationContext = new ClassPathXmlApplicationContext("xxx.xml");
    Student student = applicationContext.getBean(Student.class);
    System.out.println(student);
}
```



### 依赖注入（利用反射调用setter和getter方法）

---

- 构造器注入
- setter注入
- 接口注入（用的比较少）
- 注解注入（spring提供的，实际由上述注入方式达到注解注入）



### p命名空间和c命名空间注入

----

```xml
<!--p命名空间注入，可以直接注入属性的值：property-->
<bean id="user" class="com.kuang.pojo.User" p:name="黑心白莲" p:age="20"/>

<!--c命名空间注入，通过构造器注入：constructor-args-->
<bean id="user2" class="com.kuang.pojo.User" c:name="狂神" c:age="22"/>
```



### bean的作用域

------

- singleton：单例，表示通过 IOC 容器获取的 bean 是唯⼀的**（默认）**
- prototype：原型，表示通过 IOC 容器获取的 bean 是不同的
- request：请求，表示在⼀次 HTTP 请求内有效
- session：回话，表示在⼀个⽤户会话内有效

> request 和 session 只适⽤于 Web 项⽬，⼤多数情况下，使⽤单例和原型较多。
> prototype 模式当业务代码获取 IOC 容器中的 bean 时，Spring 才去调⽤⽆参构造创建对应的 bean。
> singleton 模式⽆论业务代码是否获取 IOC 容器中的 bean，Spring 在加载 spring.xml 时就会创建
> bean



### Bean的自动装配

----

- 自动装配是Spring满足bean依赖一种方式
- Spring会在上下文中自动寻找，并自动给bean装配属性

在Spring中有三种装配的方式：

1. 在xml中显式的配置；
2. 在java中显式配置；
3. 隐式的自动装配bean【重要】

```java
@Data
public class Person {
 private Integer Id;
 private String name;
 private Car car;
}
```

####  ByName自动装配

```xml
<!--byName：会自动在容器上下文中查找，和自己对象set方法后面的值对应的 bean id！-->
<bean id="person" class="com.southwind.entity.Person" autowire="byName">
 <property name="id" value="1"></property>
 <property name="name" value="张三"></property>
</bean>

<bean id="car" class="com.southwind.entity.Car">
 <constructor-arg name="num" value="1"></constructor-arg>
 <constructor-arg name="brand" value="奥迪"></constructor-arg>
</bean>
```

#### ByType自动装配

```xml
<!--byType：会自动在容器上下文中查找，和自己对象属性类型相同的 bean！-->
<bean id="person" class="com.southwind.entity.Person" autowire="byType">
 <property name="id" value="1"></property>
 <property name="name" value="张三"></property>
</bean>

<bean id="car2" class="com.southwind.entity.Car">
 <constructor-arg name="num" value="1"></constructor-arg>
 <constructor-arg name="brand" value="奥迪"></constructor-arg>
</bean>
```

> ByName的时候，需要保证所有 bean 的 id 唯一，并且这个 bean 需要和自动注入的属性的 set 方法的值一致！

> ByType的时候，需要保证所有 bean 的 class 唯一，并且这个 bean 需要和自动注入的属性的类型一致！

#### 使用注解实现自动装配

`@Autowired`可直接在属性上使用，也可以在 set 方法，构造函数上使用

`@Autowired` 默认是通过 byType 进⾏注⼊的，如果要改为 byName，需要配置 `@Qualifier` 注解来完成

如果`@Autowired`自动装配的环境比较复杂，自动装配无法通过一个注解`@Autowired`完成的时候，我们可以使用`@Qualifier(value = “xxx”)`去配置`@Autowired`的使用，指定一个唯一的bean对象注入！

```java
@Componet
public class Car {
    @Autowired
    @Qualifier(value = "eng")
    private Engine engine;
}
```

```java
@Componet
public class Car {
    @Resource
    private Engine engine;
}
```

`@Resource`和`@Autowired`的区别：

- 都是用来自动装配的，都可以放在属性字段上

- `@Autowired`通过byType的方式实现，而且必须要求这个对象存在！【常用】

- @Resource默认通过byName的方式实现，如果找不到名字，则通过byType实现！如果两个都找不到的情况下，就报错！【常用】

  

1. `@Componet`:  是一个泛化的概念，仅仅表示一个组件（Bean），可以用作任何层次
   - **该注解不能给接口加，可以给接口的实现类加，因为接口不能被实例化**
2. `@Service`：通常用于业务层，但是其功能与`@Component`相同
3. `@Controller`：通常作用在控制蹭，功能与`@Component`相同
4. `@Repository`：只能标注于dao类，同时还能将所标注的类中抛出的数据访问异常封装为Spring的数据访问异常类型

> 这四个注解功能都是一样的，都是代表将某个类注册到Spring中，装配Bean

> @Component 注解是将标注的类加载到 IOC 容器中，实际开发中可以根据业务需求分别使⽤ @Controller、@Service、@Repository 注解来标注控制层类、业务层类、持久层类。



`@Congiguration` 注解告知spring这个类是作为配置类使用
`@ComponentScan` 注解告知spring需要扫描哪个包下面的类并创建bean，默认是和该配置类同个包下面的类会被扫描到并创建为bean



### IOC底层原理

---

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd">

	<bean id="people" class="com.spring.entity.People">
		<property name="id" value="10002"/>
		<property name="name" value="Tom"/>
 	</bean>
</beans>
```

```java
package com.spring.ioc;

public interface MyApplicationContext {
    Object getBean(String id);
}
```

```java
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
```

```java
package com.spring.ioc;

import com.spring.entity.People;

public class TestIoc {
    public static void main(String[] args) {
        MyApplicationContext applicationContext = new MyClassPathXmlApplicationContext("spring-ioc.xml");
        People people = (People) applicationContext.getBean("people");
        System.out.println(people);
    }
}
```

