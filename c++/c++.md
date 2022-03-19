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

#### 指针

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

#### 引用

- 定义引用时必须初始化，否则编译无法通过。

- 通常用变量初始化引用，初始化后，它就一直引用该变量，不会再引用别的变量。

  - > **普通引用相当于指针常量，可以通过引用修改其引用的内容，不能引用别的变量，即指针常量的不能改变指针的指向。**

  - > **常引用相当于 指向常量的指针常量，既不能引用别的变量，也不能通过引用修改其引用的内容。**

- 也可以用一个引用去初始化另一个引用，这样两个引用就引用同一个变量

- **不能用常量**或表达式（除非表达式返回值是某个变量的引用）**初始化普通引用**。

- *当使用常量（字面量）对const引用进行初始化时，C++编译器会为常量值*
  *分配空间，并将引用名作为这段空间的别名*

- 常引用和普通引用的区别在于：不能**通过引用**去修改其引用的内容，可以用别的办法修改。
- **const int & e 相当于 const int * const e**
- **普通引用 相当于 int *const e**

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

----



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

