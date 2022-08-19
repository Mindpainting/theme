### 变量，指针，引用

```c++
#include <iostream>
using namespace std;

int main()
{
	
	int a = 7;
	int& b = a;
	int* p = &a;

	cout << "变量类型" << "    变量地址" << "    变量值" << endl;
	cout << "普通变量" << "    " << &a << "    " << a << endl;
	cout << "指针变量" << "    " << &b << "    " << b << endl;
	cout << "引用变量" << "    " << &p << "    " << p << endl;

	
	// 指向指针的引用,不能使用指向引用的指针
	int* & c = p;
	
	cout << "p: " << p << "    " << *p << endl;
	cout << "c: " << c << "    " << *c << endl;

}
```

```c++
变量类型    变量地址    变量值
普通变量    00EFFC1C    7
指针变量    00EFFC1C    7
引用变量    00EFFC04    00EFFC1C

p: 00EFFC1C    7
c: 00EFFC1C    7
```

-----



### const

#### const修饰普通类型的变量

#### const修饰指针

指针是一个变量，其值为另一个变量的地址

- **“左定值”，const 位于 * 左边，不能改变指针指向内存中的值，可以改变指针的指向。**
- **“右定向”，const 位于 * 右边，不能改变指针的指向，可以改变指针指向内存中的值。**

```c++
	int a = 10, b = 20;
	// 常量指针(不能通过指针改变值,可以改变指针的指向)
	const int* p = &a;
	p = &b; // 正确
	*p = 30; // 错误

	int a = 10, b = 20;
	// 指针常量(能通过指针改变值,不可以改变指针的指向)
	int* const p = &a;
	*p = 30; // 正确
	p = &b; // 错误

	int a = 10, b = 20;
	// 指向常量的指针常量(既不能通过指针改变值,也不能改变指针的指向)
	const int* const p = &a;
	p = &b;
	*p = 30;const* const p
```



#### const修饰引用

- 定义引用时必须初始化，否则编译无法通过。

- 通常用变量初始化引用，初始化后，它就一直引用该变量，不会再引用别的变量。

  - > **普通引用相当于指针常量，可以通过引用修改其引用的内容，不能引用别的变量，即指针常量的不能改变指针的指向。**

  - > **常引用相当于指向常量的指针常量，既不能引用别的变量，也不能通过引用修改其引用的内容。**

- 也可以用一个引用去初始化另一个引用，这样两个引用就引用同一个变量

- **不能用常量**或表达式（除非表达式返回值是某个变量的引用）**初始化普通引用**。

- *当使用常量（字面量）对 const 引用进行初始化时，C++编译器会为常量值*
  *分配空间，并将引用名作为这段空间的别名*

- 常引用和普通引用的区别在于：不能**通过引用**去修改其引用的内容，可以用别的办法修改。
- **const int & e 相当于 const int * const e**
- **普通引用 相当于 int * const e**

```c++
    // 常量初始化常引用
    const int &a = 10;
    a = 20; // 错误，不能通过引用去修改其引用的内容

    int t = 100;
    int &b = t;
    // 普通变量可以初始化常引用
    const int &c = t;
    // 普通变量的引用可以初始化常引用
    const int &c = b;
    // 常引用可以初始化常引用
    const int &d = c;

    // 常量 x
    const int x = 30;
    // 常引用 t
    const int &e = t;
    // 不能用常量和常引用初始化普通类型的引用
    // 可以强制类型转换后，再初始化
    int &f = x; // 错误
    int &g = e; // 错误

    int m = 50;
    const int &h = m;
    h = 60; // 错误
    m = 70; // 正确，通过修改原变量值，实现引用内容的修改
```



#### const参数传递和函数返回值

##### const 修饰函数参数

case1：值传递的 const 修饰传递，一般这种情况不需要 const 修饰，因为函数会自动产生临时变量复制实参值。

case2：当 const 参数为指针时，可以防止指针被意外篡改。

case3：自定义类型的参数传递，需要临时对象复制参数，对于临时对象的构造，需要调用构造函数，比较浪费时间，因此我们**采取 const 外加引用传递的方法**。并且对于一般的 int、double 等内置类型，我们不采用引用的传递方式。

```c++
#include <iostream>

using namespace std;

class A
{
public:
	// 这里使用 const& 避免调用复制构造函数，提升效率
	void test_a(const A& a) {
		cout << a.n << endl;
	}

private:
	int n = 1;
};

int main() {
	A a = A();
	a.test_a(a);
	return 0;
}
```



##### **const 修饰函数的返回值**

case1：const 修饰内置类型的返回值，修饰与不修饰返回值作用一样。

case2：const 修饰自定义类型的作为返回值，此时返回的值不能作为左值使用，既不能被赋值，也不能被修改。

case3：const 修饰返回的指针或者引用，是否返回一个指向 const 的指针，取决于我们想让用户干什么。

#### const修饰类成员函数

const 修饰类成员函数，其目的是防止成员函数修改调用对象的值，如果我们不想修改一个调用对象的值（this指向的对象），所有的成员函数都应当声明为 const 成员函数。

如果有个成员函数想修改对象中的某一个成员，这时我们可以使用 mutable 关键字修饰这个成员，mutable 的意思也是易变的，容易改变的意思，被 mutable 关键字修饰的成员可以处于不断变化中。

```c++
#include <iostream>

using namespace std;

class A
{
public:
	int get_n1(const A& a) const {

		// 常函数不允许修改调用对象的值
		// n = 2; // error

		// a为常对象，不可修改 n
		// a.n = 2; // error

		// 添加 mutable 后可以修改调用对象的值
		n_++;
		return n;
	}

	int get_n2(A& a) const {

		// 常函数不允许修改调用对象的值
		// n = 3;
		
		// a为普通对象可以修改 n
		// a.n = 3; // correct
		return n;
	}

private:
	int n = 1;
	mutable int n_ = 0;
};

int main() {
	A a = A();
	const A a1 = A();

	cout << a.get_n1(a) << endl;
	cout << a.get_n2(a) << endl;

	return 0;
}
```
##### 常函数

一个类中的成员函数为常函数，则该类的**普通对象**可以调用**普通函数**和**常函数**，**常对象**只可以调用**常函数**。

```c++
#include <iostream>

using namespace std;

class A {
private:
	class B {
	public:
		// 不加后面的const，报错二进制“ == ” : 没有找到接受“const A::B”类型的左操作数的运算符(或没有可接受的转换)
		// 不加后面的const，== 只接受左侧为非 const 对象的比较，加上后，== 左右无论是否是const对象都能比较
		bool operator==(const B& that) const {
			return n == that.n;
		}

	private:
		int n{10};
	};

public:
	bool fun(const B& b1, const B& b2) {
		return b1 == b2;
	}

	// 普通函数和常函数是重载关系
	// 普通函数
	B& getB() {
		cout << "getB()" << endl;
		return B();
	}
	// 常函数
	B& getB() const {
		cout << "getB() const" << endl;
		return B();
	}
};

int main() {
	A a1 = A();
	const A a2 = A();
	a1.getB(); // getB() 
	a2.getB(); // getB() const
	return 0;
}
```



------



### typedef struct 

```c++
// struct 关键字和 Test 一起构成了这个结构类型，无论是否存在 typedef 关键字，这个结构都存在
// 定义一个结构类型 struct Test，并为其定义新的名字为 T，即 struct Test等价于 T
typedef struct Test {
    int num;
} T;

// 在下面的代码中，新结构建立的过程中遇到了 next 声明，其类型是 pTest。这里要特别注意的是，pTest 表示的是该结构体的新别名。于是问题出现了，在结构体类型本身还没有建立完成的时候，编译器根本就不认识 pTest，因为这个结构体类型的新别名还不存在，所以自然就会报错。
typedef struct Test {
    int num;
    pTest next;
} *pTest;

// 1.（推荐）
typedef struct Test {
    int num;
    struct Test* next;
} *pTest;

// 2.（不推荐）
typedef struct Test* pTest;
struct Test {
    int num;
    pTest next;
};

// 定义了结构类型 Test且定义了两个结构类型的变量 T1,T2，还可以再定义结构类型变量，如 struct Test T;
struct Test {
    int num;
} T1, T2;

// 匿名结构体，只能使用结构类型变量 T3,T4，且不能再定义结构类型变量
struct {
    int num;
} T3, T4;
```

----



### 传值和传引用

- 传值是指，函数的形参是实参的一个拷贝，在函数执行的过程中，形参的改变不会影响实参。
- 传引用是指，形参是对应实参的引用，也就是说形参和对应的实参是一回事，形参的改变会影响实参。

1. ***指针传递参数本质上是值传递的方式，它所传递的是一个地址值。***值传递过程中，被调函数的形式参数作为被调函数的局部变量处理，即在栈中开辟了内存空间以存放由主调函数放进来的 实参的值，从而成为了实参的一个副本。值传递的特点是被调函数对形式参数的任何操作都是作为局部变量进行，不会影响主调函数的实参变量的值。
2. 而在引用传递过程中， 被调函数的形式参数虽然也作为局部变量在栈中开辟了内存空间，但是这时存放的是由主调函数放进来的实参变量的地址。被调函数对形参的任何操作都被处理成间 接寻址，即通过栈中存放的地址访问主调函数中的实参变量。正因为如此，被调函数对形参做的任何操作都影响了主调函数中的实参变量。
3. 引用传递和指针传递是不同的，虽然***它们都是在被调函数栈空间上的一个局部变量***，但是任何对于引用参数的处理都会通过一个间接寻址的方式操作到主调函数中的相关变量。而对于指针传递的参数，如果改变被调函数中的指针地址，它将影响不到主调函数的相关变量。如果想通过指针参数传递来改变主调函数中的相关变量，那就得使用指向指针的指针，或者指针引用。

```c++
#include <iostream>
using namespace std;

void swap(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 10, b = 20;
    swap(a, b);
    cout << a << "    " << b<< endl;
    return 0;
}

10    20
```

<img src="C:\Users\think\AppData\Roaming\Typora\typora-user-images\image-20210406142021958.png" alt="image-20210406142021958"  />

```c++
#include <iostream>
using namespace std;

void swap(int& x, int& y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 10, b = 20;
    swap(a, b);
    cout << a << "    " << b<< endl;
    return 0;
}

20    10
```

![image-20210406143024349](C:\Users\think\AppData\Roaming\Typora\typora-user-images\image-20210406143024349.png)

指针也可以实现

```c++
#include <iostream>
using namespace std;

void swap(int* x, int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 10, b = 20;
    swap(&a, &b);
    cout << a << "    " << b<< endl;
    return 0;
}
```

下面这个例子说明指针传递参数本质上是值传递的方式，它所传递的是一个地址值。

``` c++
#include <iostream>
using namespace std;

void swap(int* x, int* y){
    int *temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 10, b = 20;
    int *x = &a;
    int *y = &b;
    cout << x << "    " << y << endl;
    swap(x, y);
    cout << x << "    " << y << endl;
    return 0;
}
```

```c++
0x61ff04    0x61ff00
0x61ff04    0x61ff00
```

可以通过指向指针的引用，交换两个指针。
```c++
#include <iostream>
using namespace std;

void swap(int* &x, int* &y){
    int *temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 10, b = 20;
    int *x = &a;
    int *y = &b;
    cout << x << "    " << y << endl;
    swap(x, y);
    cout << x << "    " << y << endl;
    return 0;
}
```

```c++
0x61ff0c    0x61ff08
0x61ff08    0x61ff0c
```

也可以通过当前指针的下一级指针交换两个指针。

```c++
#include <iostream>
using namespace std;

void swap(int* *x, int* *y){
    int* temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 10, b = 20;
    int *x = &a;
    int *y = &b;
    cout << x << "    " << y << endl;
    swap(&x, &y);
    cout << x << "    " << y << endl;
    return 0;
}
```

```c++
0x61ff0c    0x61ff08
0x61ff08    0x61ff0c
```



### 浅拷贝和深拷贝

```c++

```

### 自增（++）运算符重载

```c++
#include <iostream>
using namespace std;

class Test {
    private:
        int n;
    public:
        Test(int i = 0):n(i) {};
        Test& operator ++(); // 用于前置形式
        Test operator ++(int); // 用于后置形式，调用时编译器自动以 0 作为实参

        // C++ 转换函数，将对象转换为 int 类型
        operator int() {return n;};
};

Test& Test::operator ++() {
    n = n + 1;
    return *this;
}

Test Test::operator ++(int k) {
    // 记录修改前的对象
    Test previous(*this);
    n = n + 1;
    // 返回修改前的对象
    return previous;
}

int main() {
    Test test(5);

    // 等价于 test.operator ++(0);
    cout << (test++) << " ";
    cout << test << " ";

    // 等价于 test.operator ++();
    cout << (++test) << " ";
    cout << test << endl;
}
```
```
5 6 7 7
```

- **前置  "++" 运算符的返回值类型是 Test&**
- **后置  "++" 运算符的返回值类型是 Test**
- **C++ 固有的前置  "++" 运算符的返回值本来就是操作数的引用，而后置  "++" 运算符的返回值则是操作数值修改前的复制品**

```c++
int main() {
    int x = 1, y =2;
    // 前置 "++"运算符的返回值是 x的引用，可以作为左值
    ++x = 10; // 正确
    // 后置 "++"运算符的返回值不是 y的引用，不能作为左值
    y++ = 20; // 错误
    cout << x << " " << y << endl; // x = 10
}
```

#### C++转换函数

- 要将类对象转换为其他类型，必须定义转换函数，指出如何进行转换。

```c++
operator type_name(); // 将对象转换为 type_name 类型

operator int();
operator double();
```

- 转换函数必须是类方法
- 转换函数不能指定返回类型
- 转换函数不能有参数

#### 前置  "++"  VS 后置  "++"  

- **后置  "++" 运算符的执行效率比前置的低。因为后置方式的重载函数中要多生成一个局部对象，而对象的生成会引发构造函数调用，需要耗费时间。**



### 实例化对象方式

```c++
// 显示调用构造函数初始化对象，对象在栈中，对象过期时系统自动调用析构函数释放内存
Book book1 = Book("B1", "A1", "C1", 0.0);

// 隐式调用构造函数初始化对象，对象在栈中，对象过期时系统自动调用析构函数释放内存
Book book2("B2", "A2", "C2", 0.0);

// new，对象在堆中，需要使用 delete 回收内存
Book *book3 = new Book("B3", "A3", "C3", 0.0);
```



### 用 constexpr 表达式替代宏

C 和 C++ 中的宏是指编译之前由预处理器处理的标记。 在编译文件之前，宏标记的每个实例都将替换为其定义的值或表达式。 C 样式编程通常使用宏来定义编译时常量值。 但宏容易出错且难以调试。 在现代 C++ 中，应优先使用 `constexpr`变量定义编译时常量：

```c++
#define SIZE 10 // C-style
constexpr int SIZE = 10; // modern C++
```



### 成员初始化列表

成员初始化列表只能用于构造函数。

```c++
#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	Animal(const string& name, const int& age);
	virtual ~Animal() {};
protected:
	string name;
	int age;
};
Animal::Animal(const string& name, const int& age)
{
	this->name = name;
	this->age = age;
}

class Cat : public Animal
{
public:
	// 派生类构造函数和成员变量均可使用成员列表初始化
	Cat(const string& name, const int& age, const string& _color, const string& breed) : Animal(name, age), color(_color) { this->breed = breed; };
	virtual ~Cat() {};
	void out();
private:
	string color;
	string breed; // 品种
};
void Cat::out()
{
	cout << "Cat: " << this->name << " " << this->age << " " << this->color << " " << this->breed << endl;
}

int main()
{
	Animal* animal;
	Cat* cat = new Cat("白老师", 2, "金渐层", "英国短毛猫");
	cat->out();
	return 0;
}
```

### 头文件预处理指令

`#pragma once`是一个比较常用的C/C++预处理指令，只要在头文件的最开始加入这条预处理指令，就能够保证头文件只被编译一次。

`#pragma once`是编译器相关的，有的编译器支持，有的编译器不支持，具体情况请查看编译器API文档，不过大部分编译器都有这个预处理指令了。

`#ifndef，#define，#endif`是C/C++语言中的宏定义，通过宏定义避免文件多次编译。所以在所有支持C++语言的编译器上都是有效的，如果写的程序要跨平台，最好使用这种方式。

```c++
#ifndef _TIMEDIALOG_H // 加下划线防止名字冲突
#define _TIMEDIALOG_H
...
#endif // TIMEDIALOG_H
```

### typeid ,size_t and  sizeof 

`typeid`和`sizeof`均为C++运算符

```c++
#include <iostream>
#include <typeinfo>

using namespace std;

class Knot {
    public:
    	inline int get_dot() {
        	return dot;
        }

    private:
    	int dot;
};

int main()
{
    int a = 0, b = 0;
    double* p;
    size_t st = 0;

    // 前面必须加上const，因为"array"为常量字符串不能赋值给不是常量类型的arr
    const char *arr = "array";

    int int_arr[] = { 1, 2, 3, 4, 5, 6 };

    Knot knot;

    cout << typeid(a).name() << endl; // int

    cout << typeid(p).name() << endl; // double * __ptr64

    cout << typeid(st).name() << endl; // unsigned __int64

    // 使用 typeid() 判断两个变量类型是否相同
    cout << (typeid(a)==typeid(b)) << endl; // 1

    cout << typeid(knot).name() << endl; // class Knot

    clog << sizeof(int) << endl; // 4
    clog << sizeof(arr) << endl; // 8
    clog << sizeof(knot) << endl; // 4
    clog << sizeof(int_arr) << endl; // 24

    return 0;
}
```

### const_cast运算符

```c++
#include<iostream>

int main() {
	// const_cast <type-id> (expression) 去除const，volatile 和__unaligned 属性
	// <>中的类型必须是指针，引用或指向对象类型成员的指针

	int a = 1;
	const int &b = a;
	const_cast<int&>(b) = 2;
	std::cout << a << " " << b << std::endl;
	return 0;
}
```

### 内嵌类作用域

本例为私有嵌套类

```c++
#include <iostream>

using namespace std;

class A {
public:
	// 在 A 类的成员函数内部可以使用嵌套类类型定义对象和指针等
	void fun1() {
		B b2(2);
		B* p2 = nullptr;
		cout << "b2: " << b2.m_num << endl;
	}

	// 由于嵌套类 B 类在后面定义的，所以这里的 A 类成员函数返回值类型和参数类型均不可使用嵌套类类型
	// 可以在 B 类定义的后面定义此函数
	//B& fun2(B& b) {
	//	B b3(3);
	//	return b3;
	//}

	// 这里在嵌套类定义之前，不可使用嵌套类类型定义对象和指针
	// B b5 = B(5);
	// B* p5;

private:
	// 这里在嵌套类定义之前，不可使用嵌套类类型定义对象和指针
	// B b4 = B(4); // error
	// B* p4; // error

	class B {
	public:
		B(int num):m_num(num) {}
		
		// 便于测试将 m_num 声明为公有
		int m_num;
	};

	// 这里写 B b1(1); 会把 b1 当做 A 类的函数，不会调用嵌套类的构造函数，而没有定义 b1 函数，所以报错
	B b1 = B(1);
	
	// 允许定义 B* 类型指针
	B* p1;

public:
	B& fun2(/*B& b*/) {
		B b3(3);
		return b1;
	}

};

int main() {
	A a = A();
	a.fun1();
	cout << "b1: " << a.fun2().m_num << endl;
	return 0;
}
```

**私有嵌套类的作用域为被嵌套类内部，具体为被嵌套类的成员函数内部和嵌套类声明之后**

### STL

#### vector

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void display(const string& explain, const vector<T>& ve) {
	// auto 在c++11之后用于自动类型推断
	cout << explain << "-->";
	for (auto it = ve.begin(); it != ve.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	// 容器有 10 个元素，默认初始值都为 0
	vector<int> ve1(10);

	// 容器有 10 个元素，默认初始值都为 8
	vector<int> ve2(10, 8);

	vector<char> ve3{ 'v', 'e', 'c', 't', 'o', 'r' };

	// 容器作为 begin/end 的参数时，begin()内部会调用 ve3.begin()，返回容器的迭代器
	// 等价于 vector<char> sve(ve3.begin(), ve3.begin() + 3);
	vector<char> sve(begin(ve3), begin(ve3) + 3);
	display<char>("sve", sve);

	int m1 = 10;
	double m2 = 1.1;
	// 参数也可以是变量
	vector<double> ve4(m1, m2);

	// 可以用容器创建容器
	vector<double> ve5(ve4);

	display<int>("ve1", ve1);
	display<int>("ve2", ve2);
	display<char>("ve3", ve3);
	display<double>("ve4", ve4);
	display<double>("ve5 copy ve4", ve5);

	vector<int> ve6;
	// 设置容器的容量
	ve6.reserve(20);
	cout << "ve6-->" << ve6.capacity() << endl;

	// find() 为全局函数，需要添加头文件 #include <algorithm>
	// 找到返回指向所查找数据的迭代器，未找到返回的迭代器和第二个参数指向相同
	
	auto fit = find(ve3.begin(), ve3.end(), '2');
	if (fit != ve3.end()) {
		clog << "find success-->" << *fit << endl;
	}
	else {
		clog << "find fail" << endl;
	}
	return 0;
}
```

#### list

```c++
#include <iostream>
#include <list>

using namespace std;

template<typename T>
void display(const string& explain, const list<T>& ls) {
	// auto 在c++11之后用于自动类型推断
	cout << explain << "-->";
	for (auto it = ls.begin(); it != ls.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	list<int> ls;
	for (auto i = 1; i <= 5; ++i)
		ls.push_back(i);
	for (auto j = 1; j <= 5; ++j)
		ls.push_front(j);
	display<int>("list唯一化前", ls);

	// unique() 将连续重复的元素唯一化
	ls.unique();

	display<int>("list唯一化后", ls);

	// 链表的排序比较特殊，只需更改指针指向即可，不需交换数据位置，链表提供两个成员函数 sort()，整个链表所有数据参与排序
	ls.sort();
	display<int>("list排序后", ls);

	// 列表拆分
	list<int> lss{ 10, 11, 12, 13, 14, 15 };

	// 裁剪全部，将 lss 的全部元素裁剪到 ls，之后 lss 为空
	// ls.splice(ls.begin(), lss);
	
	// 裁剪一个，将 lss 的第一个元素裁剪到 ls
	// ls.splice(ls.begin(), lss, lss.begin());

	// 裁剪部分，
	ls.splice(ls.begin(), lss, ++lss.begin(), --lss.end());

	display<int>("ls", ls);
	display<int>("lss", lss);
	
	return 0;
}
```

#### map and set

```c++
#include <iostream>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main() {
	map<string, int> game_team;

	// 三种插入数据的方式
	game_team.insert(make_pair("XYG", 26124559));
	game_team.insert(pair<string, int>("LGD", 4654651));

	// 使用下标插入的方式，如果没有键值，则会新创建一个节点
	game_team["BLG"] = 165152;

	for (auto it = game_team.begin(); it != game_team.end(); ++it)
	{
		cout << (*it).first << "---->" << (*it).second << endl;
	}

	// set 集合自动去重
	set<int> set;
	set.insert(1);
	set.insert(1);
	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(3);
	for (auto it = set.begin(); it != set.end(); ++it)
	{
		cout << (*it) << " ";
	}
	cout << endl;
	return 0;
}
```

### 栈求表达式

```c++
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <stdexcept>

using namespace std;

// 除数为零异常类
class zero_divisor: public exception {
public:
    const char* what(void) const throw() {
        return "a divisor is zero";
    }  
};

// 中缀表达式：A + B * (C - D) - E / F

/*
"左优先"原则：只要左边的运算符能先计算，就优先算左边的
后缀表达式：

"左优先"，使用，表达式中从左到右运算符出现的顺序和中缀表达式的运算符生效的顺序一致，适合计算机计算使用，计算效率高
A B C D - * + E F / -

不是"左优先"原则，计算机计算不使用
A B C D - * E F / - +

算法实现是从左向右扫描后缀表达式
*/

/*
"右优先"原则：只要右边的运算符能先计算，就优先算右边的
前缀表达式：
"右优先"，使用，表达式中运算符从右到左出现的顺序和中缀表达式的运算符生效的顺序一致，适合计算机计算使用，计算效率高
+ A - * B - C D / E F

不是"左右先"原则，计算机计算不使用
- + A * B - C D / E F

算法实现是从右向左扫描前缀表达式
*/

// operator（运算符），operand（操作数）

// 判断运算符优先级
int precede(char a, char b) // a 为当前扫描到的运算符，b 为栈顶运算符
{
    /*
    1：当前扫描的运算符比栈顶运算符优先级高
    0：当前扫描的运算符和栈顶运算符优先级相同
    -1：当前扫描的运算符比栈顶运算符优先级低

              s2  (  +  -   *   /   栈顶
            s1 +  1  0, 0, -1, -1,
               -  1  0, 0, -1, -1,
               *  1  1, 1,  0,  0,
               /  1  1, 1,  0,  0,
    */

    string s1 = "+-*/", s2 = "(+-*/";
    int m = 0, n = 0, PriM[4][5] = {   // 运算符优先级矩阵
        {1, 0, 0, -1, -1},
        {1, 0, 0, -1, -1},
        {1, 1, 1,  0,  0},
        {1, 1, 1,  0,  0},
    };
    while (s1[m] != a)  // 找到在s1中和当前扫描的运算符相等的运算符的序号，即为当前扫描的运算符在矩阵中的行号
        m++;
    while (s2[n] != b)  // 找到在s2中和栈顶运算符相等的运算符的序号，即为栈顶运算符在矩阵中的列号
        n++;
    return PriM[m][n];  // 输出行列号在矩阵中所对应的数值，即为当前扫描的运算符和栈顶运算符优先级的比较结果
}

// 判断是否输入的是合法的表达式
bool judge_exp_legality(string exp) {
    string::iterator it;
    int flag = 1;
    for (it = exp.begin(); it != exp.end(); ++it) {
        if (*it != '(' && *it != ')' && *it != '+' && *it != '-' && *it != '*' && *it != '/' && *it < '0' || *it > '9') {
            flag = 0;
            break;
        }
    }
    return flag == 1;
}

void calculate(stack<char>& opr, stack<int>& opd) throw(zero_divisor) {
    char ch; // 记录运算符栈出栈的运算符
    ch = opr.top();
    opr.pop();

    int a, b; // a记录运算符前面的操作数，b记录运算符后面的操作数
    b = opd.top();
    opd.pop();
    a = opd.top();
    opd.pop();

    int c = 0; // 记录每次出栈的两个操作数的运算结果
    switch (ch) {
    case '+':
        c = a + b;
        opd.push(c);
        break;
    case '-':
        c = a - b;
        opd.push(c);
        break;
    case '*':
        c = a * b;
        opd.push(c);
        break;
    case '/':
        if (b == 0) {
            throw zero_divisor();
        }
        else {
            // 这里小小的优化使计算结果四舍五入
            // 將 a 强制转为 double 类型，以得到 double 类型的计算结果
            double t1 = static_cast<double>(a) / b;
            int t2 = a / b;
            if ((t1 - t2) >= 0.5)
                c = t2 + 1;
            else
                c = t2;
            opd.push(c);
            break;
        }
    default:
        break;
    }
}

// 计算中缀表达式的值，将中缀表达式转后缀表达式算法和后缀表达式求值算法结合
int evaluate_infix_expression(string exp) throw(zero_divisor) {
    stack<char> opr; // 运算符栈
    stack<int> opd; // 操作数栈

    stack<char> temp; // 将中缀表达式中的数字字符转换为整数
    string::iterator it_exp;
    for (it_exp = exp.begin(); it_exp != exp.end(); ++it_exp) {

        if (*it_exp >= '0' && *it_exp <= '9') {
            while (*it_exp >= '0' && *it_exp <= '9') {
                temp.push(*it_exp);
                it_exp++;
                if (it_exp == exp.end())
                    break;
            }
            it_exp--; // 防止it_exp向后移动两位，直接跳过了一个字符

            int num = 0; // num 存放计算后多位操作数的整数形式
            int size = temp.size(); // 若直接将 temp.size()写在for循环中，则每执行一次i会增加，temp.size()会减少
            for (int i = 0; i < size; ++i) {
                num = num + (temp.top() - '0') * pow(10, i);
                temp.pop();
                if (temp.empty())
                    opd.push(num);
            }
        }
        else {
            if (opr.empty())
                opr.push(*it_exp);
            else {
                // 左括号，直接进栈
                if (*it_exp == '(')
                    opr.push(*it_exp);

                // 右括号，直到左括号前的运算符出栈，最后左括号出栈
                else if (*it_exp == ')') {
                    while (opr.top() != '(') {
                        calculate(opr, opd);
                    }
                    opr.pop(); // 左括号出栈
                }
                // 加减乘除运算符
                else {
                    if (precede(*it_exp, opr.top()) == 1) // 当前扫描的运算符优先级高
                        opr.push(*it_exp);

                    else { // 当前扫描的运算符比栈顶运算符优先级低或者相同
                        calculate(opr, opd);
                        opr.push(*it_exp); // 栈顶优先级高的运算符出栈后，优先级低的进栈
                    }
                }
            }
        }

    }
    // 所有表达式扫描完后 opr栈中所有剩余的运算符出栈
    while (!opr.empty()) {
        calculate(opr, opd);
    }

    return opd.top();
}

int main()
{
    string exp;
    cout << "Please enter a positive integer expression:" << endl;
    cin >> exp;
    if (judge_exp_legality(exp) == true) {
        try
        {
            cout << evaluate_infix_expression(exp) << endl;
        }
        catch (const exception& ex)
        {
            cout << ex.what() << endl;
        }   
    }
    else {
        cout << "Please enter a valid expression:" << endl;
        cin >> exp;
    }
    return 0;
}
```

### size_t和int比较

```c++
#include <iostream>
using namespace std;

int main() {
    // size_t类型在64位系统中为long long unsigned int，非64位系统中为long unsigned int
    // 这里为 long long unsigned int类型和__int64类型等价 

    cout << sizeof(int) << endl; // 4
    cout << sizeof(long) << endl; // 4
    cout << sizeof(size_t) << endl; // 8

    size_t x1 = 10;
    int y1 = 8;
    cout << (x1 > y1) << endl; // 1

    size_t x2 = 0;
    int y2 = 0;
    cout << (x2 == y2) << endl; // 1

    // 这里size_t类型的数值范围比int大，比较时int类型自动转换为size_t类型
    // 由于int有符号，转换时连符号位一起当作数值
    size_t x3 = 7;
    int y3 = -7; // -7 转换为 18446744073709551609
    cout << static_cast<size_t>(y3) << endl; // 18446744073709551609
    cout << (x3 > y3) << endl; //  输出结果为x3 < y3，明显由于自动转换导致不是预期的结果
    return 0;
}
```

在size_t类型和int类型进行比较时，size_t类型的表示范围比int类型大，比较过程中int类型自动扩展为size_t类型，然后进行比较。在两个数都是0或正数时比较结果没有问题，但当int类型的数为负数时，转换后和size_t类型的另一个数的比较结果将出现意外的结果。

**c++强制类型转换**

有符号数向无符号数转：不改变数据的内容，只改变数据的解释方式。

长数据类型向短数据类型转换：高位截断，保留低位。

短数据类型向长数据类型转换：符号扩展。
