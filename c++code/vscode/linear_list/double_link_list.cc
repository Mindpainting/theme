/* 双链表 */

#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode* prior;
    struct LNode* next;
}DLinkNode;

// 初始化双链表（创建一个空链表）
void InitDoubleList(DLinkNode* &L) {
    L = (DLinkNode*)malloc(sizeof(DLinkNode));
    L->prior = L->next = NULL;
}

// 判断双链表是否为空
bool IsEmpty(DLinkNode* L) {
    if(L->next == NULL)
        return true;
    else
        return false;
}

// 头插法建立双链表
void HeadInsert(DLinkNode* &L, int a[], int n) {

    // 新结点指针
    DLinkNode* s;

    for(int i = 0; i < n; i++) {
        s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = a[i];

        // 以下几句是核心语句
        s->next = L->next;
        // 判断头结点后面是否已有结点
        if(L->next != NULL)
            L->next->prior = s;
        L->next = s;
        s->prior = L;
    }

}

// 尾插法建立双链表
void TailInsert(DLinkNode* &L, int a[], int n) {

    // 表尾指针和新结点指针
    DLinkNode *r = L, *s;

    for(int i = 0; i < n; i++) {
        s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = a[i];

        // 以下几句是核心语句
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;

}

// 插入数据元素
bool InsertElement(DLinkNode* L, int i, int e) {
    DLinkNode *p = L, *s;

    // j=0 表示此时 p指向头结点
    int j = 0;
    if(i <= 0)
        return false;
    
    // 插入要找到位序 i的前一个结点，即找到第 i-1个结点
    while(j < i-1 && p != NULL) {
        p = p->next;
        j++;
    }

    // 未找到第 i-1个结点
    if(p == NULL)
        return false;
    else {
        s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = p->next;
        // 判断 p 结点后面是否已有结点
        if(p->next != NULL)
            p->next->prior = s;
        s->prior = p;
        p->next = s;
        return true;
    }
}

// 删除数据元素
bool DeleteElement(DLinkNode* L, int i, int &e) {
    // p 指向被删除结点的前一个结点，q 指向将要删除的结点
    DLinkNode *p = L, *q;

    // j=0 表示此时 p指向头结点
    int j = 0;
    if(i <= 0)
        return false;
    
    // 删除要找到位序 i的前一个结点，即找到第 i-1个结点
    while(j < i-1 && p != NULL) {
        p = p->next;
        j++;
    }

    // 未找到第 i-1个结点
    if(p == NULL)
        return false;
    else {
        // q 指向第 i个结点
        q = p->next;
        // 不存在第 i个结点，返回 false
        if(q == NULL)
            return false;
        else {
            e = q->data;
            p->next = q->next;
            // 若 q结点后存在后继结点，修改其前驱指针
            if(q->next != NULL)
                q->next->prior = p;  
            free(q);
            return true;
        }
    }
}

// 获取双链表的长度
int GetLength(DLinkNode* L) {
    int len = 0;
    DLinkNode* p = L->next;

    while(p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// 显示双链表
void Display(DLinkNode* L) {
    DLinkNode* p = L->next;

    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 销毁双链表
void DestroyList(DLinkNode* &L) {

    // pre 指向 p的前驱结点
    DLinkNode *pre = L, *p = L->next;
    while(p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

int main() {
    DLinkNode* L;
    InitDoubleList(L);
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / 4;
    int e;

    TailInsert(L, a, n);

    InsertElement(L, 7, 7);
    Display(L);
    cout << GetLength(L) << endl;
    DeleteElement(L, 2, e);
    Display(L);
    cout << e << endl;

}