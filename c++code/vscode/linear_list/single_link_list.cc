/* 单链表 */

#include <iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode* next;
}SLinkNode;

// 初始化单链表（创建一个空链表）
void InitSingleList(SLinkNode* &L) {
    L = (SLinkNode*)malloc(sizeof(SLinkNode));
    L->next = NULL;
}

// 判断单链表是否为空
bool IsEmpty(SLinkNode* L) {
    if(L->next == NULL)
        return true;
    else
        return false;
}

// 头插法建立单链表
void HeadInsert(SLinkNode* &L, int a[], int n) {

    // 新结点指针
    SLinkNode* s;

    for(int i = 0; i < n; i++) {
        s = (SLinkNode*)malloc(sizeof(SLinkNode));
        s->data = a[i];

        // 以下两句是核心语句
        s->next = L->next;
        L->next = s;
    }
}

// 尾插法建立单链表
void TailInsert(SLinkNode* &L, int a[], int n) {

    // 表尾指针和新结点指针
    SLinkNode *r = L, *s;

    for(int i = 0; i < n; i++) {
        s = (SLinkNode*)malloc(sizeof(SLinkNode));
        s->data = a[i];

        // 以下两句是核心语句
        r->next = s;
        r = s;
    }
    r->next = NULL;

}

// 按位序查找
bool GetElement(SLinkNode* L, int i, int &e) {

    SLinkNode* p = L;

    // j=0 表示此时 p指向头结点
    int j = 0;
    if(i <= 0)
        return false;
    
    // 找到第 i个结点
    while(j < i && p != NULL) {
        p = p->next;
        j++;
    }

    // 未找到第 i个结点
    if(p == NULL)
        return false;
    else{
        e = p->data;
        return true;
    }
}

// 按值查找
int LocateElement(SLinkNode* L, int e) {
    int i = 1;
    SLinkNode* p = L->next;

    while(p != NULL && p->data != e) {
        p = p->next;
        i++;
    }
    if(p == NULL)
        return 0;
    else
        return i;
}

// 插入数据元素
bool InsertElement(SLinkNode* L, int i, int e) {
    SLinkNode *p = L, *s;

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
        s = (SLinkNode*)malloc(sizeof(SLinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

// 删除数据元素
bool DeleteElement(SLinkNode* L, int i, int &e) {
    // p 指向被删除结点的前一个结点，q 指向将要删除的结点
    SLinkNode *p = L, *q;

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
        q = p->next;
        // 不存在第 i个结点，返回 false
        if(q == NULL)
            return false;
        else{
            e = q->data;
            p->next = q->next;
            free(q);
            return true;
        }
    }
}

// 获取单链表的长度
int GetLength(SLinkNode* L) {
    int len = 0;
    SLinkNode* p = L->next;

    while(p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

// 显示单链表
void Display(SLinkNode* L) {
    SLinkNode* p = L->next;

    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 销毁单链表
void DestroyList(SLinkNode* &L) {

    // pre 指向 p的前驱结点
    SLinkNode *pre = L, *p = L->next;
    while(p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

int main() {

    SLinkNode* L;
    InitSingleList(L);
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / 4;

    // HeadInsert(L, a, n);
    // TailInsert(L, a, n);
    // Display(L);

/*     int e;
    GetElement(L, 3, e);
    cout << e << endl; */
    
    // cout << LocateElement(L, 2);

/*     InsertElement(L, 7, 7);
    Display(L);
    int e;
    DeleteElement(L, 7, e);
    cout << e << endl;
    Display(L); */

    cout << IsEmpty(L) << endl;
    cout << GetLength(L) << endl;

    return 0;
}
