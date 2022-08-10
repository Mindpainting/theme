

### 动态绑定

- 声明类型：一个变量必须被声明为某种类型，变量的这个类型称为它的声明类型。
- 实际类型：变量的实际类型是被变量引用的对象的实际类。  

```java
public abstract class Graphics {
    // 面积
    public abstract double area();
}
```

```java
public class Triangle extends Graphics{
    @Override
    public double area() {
        return 0;
    }
}
```

```java
public class Test {
    public static void main(String[] args) {
       Graphics graphics = new Triangle();
       graphics.area();
    }
}
```

声明类型为Graphics，实际类型为Triangle。graphics调用哪个area()方法由graphics的实际类型

决定，这称为动态绑定。若实际类型中没有该方法，则向上到其父类中去找该方法。

### 方法重写和重载

- 方法重写：  
  - 发生在具有继承关系的不同类中
  - 具有同样的签名

- 方法重载：
  - 可以发生在同一个类中，也可以发生在具有继承关系的不同类中
  - 具有同样的名字，但是不同的参数列表

----



### 匿名类

​		匿名内部类必须继承一个父类或者实现一个父接口，如果接口的实现类（或者是父类的子类）只需要【使用唯一的一次】，那么，这种情况下就可以省略掉该类的定义，改为使用【匿名内部类】

```java
new 父类名或者接口名(){
// 方法重写
@Override
public void method() {
// 执行语句
}
};
```

```java
public abstract class MyAbstractClass {
    public abstract void method();
}
```

```java
public interface MyInterface {
    void method();
}
```

```java
public class Test {

    public static void main(String[] args) {

        // 接口
        // 使用匿名内部类，但不是匿名对象，对象名称就叫 myInterface
        MyInterface myInterface = new MyInterface() {
            @Override
            public void method() {
                System.out.println("匿名内部类实现了接口方法！");
            }
        };

        myInterface.method();


        // 抽象类
        MyAbstractClass myAbstractClass = new MyAbstractClass() {
            @Override
            public void method() {
                System.out.println("匿名内部类实现了抽象类方法！");
            }
        };

        myAbstractClass.method();


        // 使用了匿名内部类，而且省略了对象名称，也是匿名对象
        // 匿名对象无法调用第二次方法，所以需要再创建一个匿名内部类的匿名对象
        new MyInterface(){
            @Override
            public void method() {
                System.out.println("匿名内部类实现了接口方法！");
            }
        }.method();

    }
}
```

另外还要注意几点问题：
1. 匿名内部类，在【创建对象】的时候，只能使用唯一一次。
如果希望多次创建对象，而且类的内容一样的话，那么就需要使用单独定义的实现类了。
2. 匿名对象，在【调用方法】的时候，只能调用唯一一次。
如果希望同一个对象，调用多次方法，那么必须给对象起个名字。
3. 匿名内部类是省略了【实现类/子类名称】，但是匿名对象是省略了【对象名称】
强调：匿名内部类和匿名对象不是一回事！！！

----



### 权限修饰符

|                        | public | protected | default（空的） | private |
| :--------------------- | :----: | :-------: | :-------------: | :-----: |
| 同一类中               |   √    |     √     |        √        |    √    |
| 同一包中(子类与无关类) |   √    |     √     |        √        |         |
| 不同包的子类           |   √    |     √     |                 |         |
| 不同包中的无关类       |   √    |           |                 |         |

----



### 抽象类和接口

一个类可以实现多个接口，但是只能继承一个父类。

- 抽象类
- 接口

---



### `StringBuilder`类和`StrigBuffer`类

- ` StringBuilder` 和` StringBuffer`类似于`String`类，区别在于`String`类是不可改变的。
- 单任务访问，使用`StringBuilder`更有效。
- 多任务并发访问，使用`StringBuffer`。因为这种情况下需要同步以防止`StringBuffer`损坏。
- `StringBuilder`和`StringBuffer`构造方法和其他方法几乎是完全一样。

```java
// 构造一个没有字符的字符串缓冲区，初始容量为16个字符
public StringBuffer() 
    
// 构造一个初始化为指定字符串内容的字符串缓冲区。 字符串缓冲区的初始容量为16加上字符串参数的长度
public StringBuffer(String str)

// 返回长度（字符数）
public int length()
    
// 返回char在指定索引在这个序列值。 第一个char值为索引0 ，下一个索引为1 ，依此类推，就像数组索引一样
public char charAt(int index) 

// 追加Object参数的字符串表示
public StringBuffer append(Object obj)
    
// 删除此序列的子字符串中的字符。 子串:[start, end)
public StringBuffer delete(int start,int end)

// 倒序输出，返回当前 stringBuffer对象
public StringBuffer reverse()
    
```

----



### 异常

- **java一个浮点数除以0不会产生异常。**
- 异常的根类是java. lang. Throwable。
- 声明异常的关键字是throws，抛出异常的关键字是throw。
- 父类的catch块必须在子类的catch块后面。

- java.lang.**Throwable**(implements java.io.Serializable)
  - java.lang.**Error**
    - java.lang.[**AssertionError**](AssertionError.html)
    - java.lang.**LinkageError**
      - java.lang.[**BootstrapMethodError**](BootstrapMethodError.html)
      - java.lang.[**ClassCircularityError**](ClassCircularityError.html)
      - java.lang.**ClassFormatError**
        - java.lang.[**UnsupportedClassVersionError**](UnsupportedClassVersionError.html)
      - java.lang.[**ExceptionInInitializerError**](ExceptionInInitializerError.html)
      - java.lang.**IncompatibleClassChangeError**
        - java.lang.[**AbstractMethodError**](AbstractMethodError.html)
        - java.lang.[**IllegalAccessError**](IllegalAccessError.html)
        - java.lang.[**InstantiationError**](InstantiationError.html)
        - java.lang.[**NoSuchFieldError**](NoSuchFieldError.html)
        - java.lang.[**NoSuchMethodError**](NoSuchMethodError.html)
      - java.lang.[**NoClassDefFoundError**](NoClassDefFoundError.html)
      - java.lang.[**UnsatisfiedLinkError**](UnsatisfiedLinkError.html)
      - java.lang.[**VerifyError**](VerifyError.html)
    - java.lang.[**ThreadDeath**](ThreadDeath.html)
    - java.lang.**VirtualMachineError**
      - java.lang.[**InternalError**](InternalError.html)
      - java.lang.[**OutOfMemoryError**](OutOfMemoryError.html)
      - java.lang.[**StackOverflowError**](StackOverflowError.html)
      - java.lang.[**UnknownError**](UnknownError.html)
  - java.lang.**Exception**
    - java.lang.[**CloneNotSupportedException**](CloneNotSupportedException.html)
    - java.lang.[**InterruptedException**](InterruptedException.html)
    - java.lang.**ReflectiveOperationException**
      - java.lang.[**ClassNotFoundException**](ClassNotFoundException.html)
      - java.lang.[**IllegalAccessException**](IllegalAccessException.html)
      - java.lang.[**InstantiationException**](InstantiationException.html)
      - java.lang.[**NoSuchFieldException**](NoSuchFieldException.html)
      - java.lang.[**NoSuchMethodException**](NoSuchMethodException.html)
    - java.lang.**RuntimeException**
      - java.lang.[**ArithmeticException**](ArithmeticException.html)
      - java.lang.[**ArrayStoreException**](ArrayStoreException.html)
      - java.lang.[**ClassCastException**](ClassCastException.html)
      - java.lang.[**EnumConstantNotPresentException**](EnumConstantNotPresentException.html)
      - java.lang.**IllegalArgumentException**
        - java.lang.[**IllegalThreadStateException**](IllegalThreadStateException.html)
        - java.lang.[**NumberFormatException**](NumberFormatException.html)
      - java.lang.[**IllegalCallerException**](IllegalCallerException.html)
      - java.lang.[**IllegalMonitorStateException**](IllegalMonitorStateException.html)
      - java.lang.[**IllegalStateException**](IllegalStateException.html)
      - java.lang.**IndexOutOfBoundsException**
        - java.lang.[**ArrayIndexOutOfBoundsException**](ArrayIndexOutOfBoundsException.html)
        - java.lang.[**StringIndexOutOfBoundsException**](StringIndexOutOfBoundsException.html)
      - java.lang.[**LayerInstantiationException**](LayerInstantiationException.html)
      - java.lang.[**NegativeArraySizeException**](NegativeArraySizeException.html)
      - java.lang.[**NullPointerException**](NullPointerException.html)
      - java.lang.[**SecurityException**](SecurityException.html)
      - java.lang.[**TypeNotPresentException**](TypeNotPresentException.html)
      - java.lang.[**UnsupportedOperationException**](UnsupportedOperationException.html)

####  throw关键字

- 可以使用throw关键字在指定的方法中抛出指定的异常
- throw new `xxxException`("异常产生的原因");          
- throw关键字后边创建的是编译异常(写代码的时候报错)，我们就必须处理这个异常，要么throws，要么try...catch
- throw关键字必须写在方法的内部
- throw关键字后边new的对象必须是Exception或者Exception的子类对象
- throw关键字抛出指定的异常对象，我们就必须处理这个异常对象
- throw关键字后边创建的是`RuntimeException`或者是 `RuntimeException`的子类对象，我们可以不处理,默认交给JVM处理(打印异常对象，中断程序)  



#### throws关键字

- 异常处理的第一种方式，交给别人处理
- 当方法内部抛出异常对象的时候，那么我们就必须处理这个异常对象
- 可以使用throws关键字处理异常对象，会把异常对象声明抛出给方法的调用者处理(自己不处理，给别人处理),最终交给JVM处理-->中断处理
- throws关键字必须写在方法声明处
- throws关键字后边声明的异常必须是Exception或者是Exception的子类
- 方法内部如果抛出了多个异常对象,那么throws后边必须也声明多个异常 如果抛出的多个异常对象有子父类关系,那么直接声明父类异常即可
- 调用了一个声明抛出异常的方法，我们就必须的处理声明的异常 要么继续使用throws声明抛出,交给方法的调用者处理，最终交给JVM 要么try...catch自己处理异常



#### try...catch

- 异常处理的第二种方式，自己处理异常

```java
    格式:
        try{
            可能产生异常的代码
        }catch(定义一个异常的变量,用来接收try中抛出的异常对象){
            异常的处理逻辑,异常异常对象之后,怎么处理异常对象
            一般在工作中,会把异常的信息记录到一个日志中
        }
        ...
        catch(异常类名 变量名){

        }
```
- try中可能会抛出多个异常对象，那么就可以使用多个catch来处理这些异常对象。
- 如果try中产生了异常，那么就会执行catch中的异常处理逻辑，执行完毕catch中的处理逻辑，继续执行try...catch之后的代码。
- 如果try中没有产生异常,那么就不会执行catch中异常的处理逻辑，执行完try中的代码，继续执行try...catch之后的代码。



> Throwable类中定义了3个异常处理的方法。
>
> - String getMessage() 返回此 throwable 的简短描述。
> -  String toString() 返回此 throwable 的详细消息字符串。
> -  void printStackTrace()  JVM打印异常对象,默认此方法，打印的异常信息是最全面的。



#### finally代码块

```java
格式:
   try{
       可能产生异常的代码
   }catch(定义一个异常的变量,用来接收try中抛出的异常对象){
       异常的处理逻辑,异常异常对象之后,怎么处理异常对象
       一般在工作中,会把异常的信息记录到一个日志中
   }
   ...
   catch(异常类名 变量名){

   }finally{
       无论是否出现异常都会执行
   }
```

- finally不能单独使用,必须和try一起使用。
- finally一般用于资源释放(资源回收)，无论程序是否出现异常,最后都要资源释放(IO)。



#### 多个异常使用捕获处理

1. 多个异常分别处理。
2. 多个异常一次捕获，多次处理。
3. 多个异常一次捕获一次处理。

一般我们是使用一次捕获多次处理方式，格式如下：

```java
try{
     // 编写可能会出现异常的代码
}catch(异常类型A  e){  // 当try中出现A类型异常,就用该catch来捕获.
    
     // 处理异常的代码
     // 记录日志/打印异常信息/继续抛出异常
}catch(异常类型B  e){  // 当try中出现B类型异常,就用该catch来捕获.
     
     // 处理异常的代码
     // 记录日志/打印异常信息/继续抛出异常
}
```

> 注意:这种异常处理方式，要求多个catch中的异常不能相同，并且若catch中的多个异常之间有子父类异常的关系，那么子类异常要求在上面的catch处理，父类异常在下面的catch处理。

* 运行时异常被抛出可以不处理。即不捕获也不声明抛出。

* 如果finally有return语句，永远返回finally中的结果,避免该情况. 

* 如果父类抛出了多个异常，子类重写父类方法时,抛出和父类相同的异常或者是父类异常的子类或者不抛出异常。

* 父类方法没有抛出异常，子类重写父类该方法时也不可抛出异常。此时子类产生该异常，只能捕获处理，不能声明抛出

----



### Java集合

- Collection
  - List（单列集合）
    - ArrayList
    - LinkedList
    - Vector
  - Set（单列集合）
    - HashSet
    - LinkedHashSet
    - TreeSet
- Map
  - HashMap
  - Hashtable
  - LinkedHashMap
  - TreeMap
  - Properties
- Collections



集合：

1. 可以动态保存任意多个对象且对象可以是不同的数据类型
2. 提供一系列方便的操作对象的方法



Collection接口实现类的特点：

1. Collection实现子类可以存放多个元素，每个元素可以是Object
2. 有些Collection的实现类，可以存放重复的元素，有些不可以



#### 遍历集合

##### Iterator迭代器

```java
Collection col = new ArrayList();
Iterator iterator = col.iterator();

// hasNext()判断是否还有数据
// 快捷键 itit + Enter 生成while循环
while (iterator.hasNext()) {
            // 返回下一个元素，类型是Object
            Object next =  iterator.next();
            System.out.println(next);
        }
// 当退出while循环后，这时iterator迭代器指向最后的元素
// 若再次遍历必须重置迭代器，即再次将Iterator iterator = col.iterator();放在while循环之前
```



##### for循环增强

```java
Collection col = new ArrayList();
col.add("Hello");
col.add("World");
// 简化版的迭代器遍历
// 快捷键 I + Enter
for (Object o :col) {
	System.out.println(o);
}
```

##### for循环

```Java
Collection col = new ArrayList();
col.add("Hello");
col.add("World");
for (int i = 0; i < col.size(); i++) {
    // ArrayList的对象通过多态向上转型成为Collection的对象，Collection的对象没有get()方法
    // 需将Collection的对象向下转型，恢复成原对象
	System.out.println(((ArrayList) col).get(i));
}
```



#### List

- List集合类中的元素有序且可重复
- List集合类中的每个元素支持索引，例 `list.get(index)`，索引从零开始



#### ArrayList

- `ArrayList`可以加入多个null

- `ArrayList`是由数组来实现数据存储的

- `ArrayList `基本等同于Vector，执行效率高，但线程不安全。多线程下不建议使用。

1. `ArrayList`中维护了一个Object类型的数组`elementData`
2. 当创建`ArrayList`对象时，如果使用的是无参构造器，则初始`elementData`容量为0，第一次添加，则扩容`elementData`为10，如需要再次扩容，则扩容`elementData`为1.5倍
3. 如果使用的是指定大小的构造器，则初始`elementData`容量为指定大小，如需要再次扩容，则直接扩容`elementData`为1.5倍时时时



#### Vector

- 底层也是一个对象数组
- 线程同步（线程安全）



#### LinkedList

- 底层实现双向链表和双端队列
- 可以添加任意元素（元素可以重复），包括null
- 线程不安全，没有实现同步

----



### 深克隆和浅克隆

**如果一个类只包含基本字段（属性或成员变量）或对不可变对象的引用，那么通常super返回的对象中没有字段。**

#### 浅克隆

- 如果原型对象的成员变量是值类型（8种基本数据类型），将复制一份给克隆对象
- 如果原型对象的成员变量是引用类型，则将引用对象的地址复制一份给克隆对象，也就是说原型对象和克隆对象的成员变量指向相同的内存地址。
- 在浅克隆中，当对象被复制时只复制它本身和其中包含的值类型的成员变量，而引用类型的成员对象并没有复制。

```java
public class Car implements Cloneable{
    // 不可变对象的引用
    String color;
    Engine engine;

    public Car() {
    }

    public Car(String color, Engine engine) {
        this.color = color;
        this.engine = engine;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public Engine getEngine() {
        return engine;
    }

    public void setEngine(Engine engine) {
        this.engine = engine;
    }
    
	// 克隆方法重写（浅克隆）
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
```

``` java
public class Engine {
    String type;

    public Engine(String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
    // 没有重写克隆方法
}
```



```java
public class ShallowClone {
    public static void main(String[] args) throws CloneNotSupportedException {

        Engine engine = new Engine("SSS");
        Car car1 = new Car("Black", engine);

        // car2对象克隆 car1对象
        Car car2 = car1.clone();

        System.out.println("car1: " + car1.getColor() + "   engine: " + car1.getEngine().getType());
        System.out.println("car2: " + car2.getColor() + "   engine: " + car2.getEngine().getType());

        // 分别修改 car1, car2的非引用和引用属性值，看两个对象之间是否有影响
        car1.setColor("Green");
        car2.setColor("White");
        car1.getEngine().setType("BBB");
//        car2.getEngine().setType("CCC");
//        engine.setType("AAA");

        System.out.println("car1: " + car1.getColor() + "   engine: " + car1.getEngine().getType());
        System.out.println("car2: " + car2.getColor() + "   engine: " + car2.getEngine().getType());

        System.out.println(car1.getEngine());
        System.out.println(car2.getEngine());

    }
```

``` java
car1: Black   engine: SSS
car2: Black   engine: SSS
car1: Green   engine: BBB
car2: White   engine: BBB
com.clone.shallowclone.Engine@12edcd21
com.clone.shallowclone.Engine@12edcd21
```

​		*由输出结果可以看出，只修改了原对象 car1 的 engine 值，克隆对象的 engine 值也随之改变了。说明浅克隆只是把原对象引用类型的 engine 对象的地址复制给了克隆对象，原对象和克隆对象的 engine 对象共用同一块内存。*

![image-20220810113739990](C:\Users\think\AppData\Roaming\Typora\typora-user-images\image-20220810113739990.png)

#### 深克隆

​		在深克隆中，无论原型对象的成员变量是值类型还是引用类型，都将复制一份给克隆对象，深克隆将原型对象的所有引用对象也复制一份给克隆对象。 简单来说，在深克隆中，除了对象本身被复制外，对象所包含的所有成员变量也将复制。

​		在Java语言中，如果需要实现深克隆，可以通过覆盖Object类的clone()方法实现，也可以通过序列化(Serialization)等方式来实现。

​		序列化就是将对象写到流的过程，写到流中的对象是原有对象的一个拷贝，而原对象仍然存在于内存中。通过序列化实现的拷贝不仅可以复制对象本身，而且可以复制其引用的成员对象，因此通过序列化将对象写到一个流中，再从流里将其读出来，可以实现深克隆。需要注意的是能够实现序列化的对象其类必须实现Serializable接口，否则无法实现序列化操作。

​		如果引用类型里面还包含很多引用类型，或者内层引用类型的类里面又包含引用类型，使用clone方法就会很麻烦。这时我们可以用序列化的方式来实现对象的深克隆。

``` java
public class Car implements Cloneable{
    String color;
    Engine engine;

    public Car() {
    }

    public Car(String color, Engine engine) {
        this.color = color;
        this.engine = engine;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public Engine getEngine() {
        return engine;
    }

    public void setEngine(Engine engine) {
        this.engine = engine;
    }

    // 克隆方法重写（深克隆）
    @Override
    protected Car clone() throws CloneNotSupportedException {
        Car car = (Car) super.clone();
        car.engine = engine.clone();
        return car;
    }

}
```

``` java
public class Engine implements Cloneable{
    String type;

    public Engine(String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    @Override
    protected Engine clone() throws CloneNotSupportedException {
        return (Engine) super.clone();
    }
}
```



``` java
public class DeepClone {
    public static void main(String[] args) throws CloneNotSupportedException {

        Engine engine = new Engine("SSS");
        Car car1 = new Car("Black", engine);

        // car2对象克隆 car1对象
        Car car2 = car1.clone();

        System.out.println("car1: " + car1.getColor() + "   engine: " + car1.getEngine().getType());
        System.out.println("car2: " + car2.getColor() + "   engine: " + car2.getEngine().getType());

        // 分别修改 car1, car2的非引用和引用属性值，看两个对象之间是否有影响
        car1.setColor("Green");
        car2.setColor("White");
        car1.getEngine().setType("BBB");
        car2.getEngine().setType("CCC");

        System.out.println("car1: " + car1.getColor() + "   engine: " + car1.getEngine().getType());
        System.out.println("car2: " + car2.getColor() + "   engine: " + car2.getEngine().getType());

        System.out.println(car1.getEngine());
        System.out.println(car2.getEngine());

    }
```

``` java
car1: Black   engine: SSS
car2: Black   engine: SSS
car1: Green   engine: BBB
car2: White   engine: CCC
com.clone.deepclone.Engine@12edcd21
com.clone.deepclone.Engine@34c45dca
```

​		*由输出结果可以看出，原对象和克隆对象不论值类型属性和引用类型属性的修改都互不影响，说明深克隆是完完全全的将原对象复制了一份给克隆对象并在内存新开辟一片空间。*	

![image-20220810113801900](C:\Users\think\AppData\Roaming\Typora\typora-user-images\image-20220810113801900.png)

- **基本类型和不可变对象的引用（如String类）深克隆等于浅克隆。**
- **引用类型。**
  - **浅克隆：将引用对象的地址复制一份给克隆对象，也就是说原型对象和克隆对象的成员变量指向相同的内存地址。**
  - **深克隆：将原型对象的所有引用对象也复制一份给克隆对象。**

----



### JAVA基本数据类型

- 整数类型：byte(1)，short(2)，int(4)，long(8)

- 浮点类型：float(4)，double(8)

- 字符类型：char(2)

- 布尔类型：boolean(1)



数据类型取值范围由小到大表示如下：

```java
byte < short < char < int < long < float < double
```



类型转换：

- 自动类型转换（隐式转换）：

  ```java
   byte、short、char‐‐>int‐‐>long‐‐>float‐‐>double
  ```

- 强制类型转换（显示转换）：将取值范围大的类型强制转换成取值范围小的类型。

- `byte/short/char`这三种类型都可以发生数学运算，运算时会被首先提升成为int类型，再计算。

- boolean类型不能发生数据类型转换。



### Java获取桌面路径

```java
package javase;

import javax.swing.filechooser.FileSystemView;
import java.io.File;

// Java 获取桌面路径
public class GetDesktopPath {
    public static void main(String[] args) {
        // FileSystemView 是 JFileChooser 的文件系统网关

        // public static FileSystemView getFileSystemView() 返回文件系统视图
        FileSystemView fileSystemView = FileSystemView.getFileSystemView();
        
        // public File getHomeDirectory() 返回主目录
        File homeDirectory = fileSystemView.getHomeDirectory();
        System.out.println("homeDirectory = " + homeDirectory);
    }
}
```

