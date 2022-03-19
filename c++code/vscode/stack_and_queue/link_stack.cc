/* 链栈 (带头结点)*/

#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode* next;
}LinkStack;

// 初始化链栈
void InitListStack(LinkStack* s) {
    s = (LinkStack*)malloc(sizeof(LinkStack));
    s->next = NULL;
}

// 销毁链栈
void DestoryListStack(LinkStack* s) {
    LinkStack *pre = s, *p = s->next;

    while(p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

// 判断栈是否为空
bool IsEmpty(LinkStack* s) {
    return (s->next == NULL);
}

// 进栈（链栈只有内存溢出时才会出现栈满，所以一般不考虑栈满）
void Push(LinkStack* s, int e) {
    // 新结点指针
    LinkStack* p;
    p = (LinkStack*)malloc(sizeof(LinkStack));
    p->data = e;
    p->next = s->next;
    s->next = p;
}

// 出栈（栈顶元素出栈，不在栈中了，出栈后返回其值）
bool Pop(LinkStack* s, int &e) {
    if(s->next == NULL)
        return false;
    else {
        LinkStack* q = s->next; // 指向将要出栈的元素
        e = q->data;
        s->next = q->next;
        free(q);
        return true;
    }
}

// 取栈顶元素（只是取出栈顶元素的值，栈顶元素并未出栈，还在栈顶）
bool GetElement(LinkStack* s, int &e) {
    if(s->next == NULL)
        return false;
    else {
        e = s->next->data;
        return true;
    }
}

// 不能显示，每次显示完后栈为空，后面的操作无法执行
/* void Display(LinkStack* s) {
    LinkStack* p = s->next;

    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
} */

int main() {
    LinkStack* s;
    InitListStack(s);
    for(int i = 0; i < 5; i++) {
        Push(s, i);
    }
    int e;
    Pop(s, e);
    cout << e << endl;
    return 0; 
}
