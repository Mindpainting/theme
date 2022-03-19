/* 循环单链表 */

#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode* next;
}LoopSLinkNode;

// 初始化循环单链表（创建一个空链表）
void InitLoopSingleList(LoopSLinkNode* &L) {
    L = (LoopSLinkNode*)malloc(sizeof(LoopSLinkNode));
    L->next = L;
}

// 判断循环单链表是否为空
bool IsEmpty(LoopSLinkNode* L) {
    if(L->next == L)
        return true;
    else
        return false;
}

// 头插法建立循环单链表
void HeadInsert(LoopSLinkNode* &L, int a[], int n) {

    // 新结点指针
    LoopSLinkNode* s;

    for(int i = 0; i < n; i++) {
        s = (LoopSLinkNode*)malloc(sizeof(LoopSLinkNode));
        s->data = a[i];

        // 以下是核心语句
        if(i == 0) {
            // 头插法的第一个结点在链表建立完成后是最后一个结点，循环链表，所以指向头结点
            s->next = L;
            L->next = s;
        }
        else {
            s->next = L->next;
            L->next = s;
        }
    }
}

// 尾插法建立循环单链表
void TailInsert(LoopSLinkNode* &L, int a[], int n) {

    // 表尾指针和新结点指针
    LoopSLinkNode *r = L, *s;

    for(int i = 0; i < n; i++) {
        s = (LoopSLinkNode*)malloc(sizeof(LoopSLinkNode));
        s->data = a[i];

        // 以下两句是核心语句
        r->next = s;
        r = s;
    }
    r->next = L;

}

// 按位序查找
bool GetElement(LoopSLinkNode* L, int i, int &e) {

    LoopSLinkNode* p = L->next;

    // j=0 表示此时 p指向头结点
    int j = 1;
    if(i <= 0)
        return false;
    
    // 找到第 i个结点
    while(j <= i && p != L) {
        p = p->next;
        j++;
    }

    // 未找到第 i个结点
    if(p == L)
        return false;
    else{
        e = p->data;
        return true;
    }
}

// 按值查找
int LocateElement(LoopSLinkNode* L, int e) {
    int i = 1;
    LoopSLinkNode* p = L->next;

    while(p != L && p->data != e) {
        p = p->next;
        i++;
    }
    if(p == L)
        return 0;
    else
        return i;
}

// 插入数据元素
bool InsertElement(LoopSLinkNode* L, int i, int e) {
    LoopSLinkNode *p = L->next, *s;

    // j=1 表示此时 p指向第一个结点
    int j = 1;
    if(i < 1)
        return false;
    
    // 插入要找到位序 i的前一个结点，即找到第 i-1个结点
    while(j < i-1 && p != L) {
        p = p->next;
        j++;
    }

    // 未找到第 i-1个结点
    if(p == L)
        return false;
    else {
        s = (LoopSLinkNode*)malloc(sizeof(LoopSLinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

// 删除数据元素
bool DeleteElement(LoopSLinkNode* L, int i, int &e) {
    // p 指向被删除结点的前一个结点，q 指向将要删除的结点
    LoopSLinkNode *p = L->next, *q;

    // j=1 表示此时 p指向第一个结点
    int j = 1;
    if(i < 1)
        return false;
    
    // 删除要找到位序 i的前一个结点，即找到第 i-1个结点
    while(j < i-1 && p != L) {
        p = p->next;
        j++;
    }

    // 未找到第 i-1个结点
    if(p == NULL)
        return false;
    else {
        q = p->next;
        // 不存在第 i个结点，返回 false
        if(q == NULL)
            return false;
        else {
            e = q->data;
            p->next = q->next;
            free(q);
            return true;
        }
    }
}

// 获取循环单链表的长度
int GetLength(LoopSLinkNode* L) {
    int len = 0;
    LoopSLinkNode* p = L->next;

    while(p != L) {
        len++;
        p = p->next;
    }
    return len;
}

// 显示循环单链表
void Display(LoopSLinkNode* L) {
    LoopSLinkNode* p = L->next;

    while(p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
/*     // 检查是否循环
    cout << p->next->data << endl; */
}

// 销毁循环单链表
void DestroyList(LoopSLinkNode* &L) {

    // pre 指向 p的前驱结点
    LoopSLinkNode *pre = L, *p = L->next;
    while(p != L) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

int main() {
    LoopSLinkNode* L;
    InitLoopSingleList(L);
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / 4;

    HeadInsert(L, a, n);
    // TailInsert(L, a, n);
    Display(L);

/*     int e;
    GetElement(L, 3, e);
    cout << e << endl; */
    
    // cout << LocateElement(L, 2);

    InsertElement(L, 7, 7);
    Display(L);
    int e;
    DeleteElement(L, 6, e);
    cout << e << endl;
    Display(L);

    // cout << GetLength(L) << endl;

    return 0;
}
