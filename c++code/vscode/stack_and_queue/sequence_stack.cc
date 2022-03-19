/* 顺序栈 */

#include <iostream>
#define MAXSIZE 10
using namespace std;

typedef struct {
    int data[MAXSIZE];
    int top;
}SqStack;

// 初始化栈
void InitStack(SqStack &s) {
    s.top = -1;
}

// 判断栈是否为空
bool StackEmpty(SqStack &s) {
    return (s.top == -1);
}

// 进栈
bool Push(SqStack &s, int x) {
    // 栈满，返回 false
    if(s.top == MAXSIZE-1)
        return false;
    else {
        s.top++;
        s.data[s.top] = x;
        return true;
    }
}

// 出栈
bool Pop(SqStack &s, int &x) {
    if(s.top == -1)
        return false;
    else {
        x = s.data[s.top];
        s.top--;
        return true;
    }
}

// 读栈顶元素
bool GetTop(SqStack &s, int &x) {
    if(s.top == -1)
        return false;
    else {
        x = s.data[s.top];
        return true;
    }
} 

void Display(SqStack &s) {
    // 防止输出一次 s.top指向 -1
    int i = s.top;

    while(i != -1) {
        cout << s.data[i] << " ";
        i--;
    }
    cout << endl;
}

int main() {
    SqStack s;
    InitStack(s);
    for(int i = 0; i < 5; i++) {
        Push(s, i);
    }
    Display(s);
    int e;
    Pop(s, e);
    Display(s);
    return 0;
}
