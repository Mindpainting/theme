/* 循环双链表 */

#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode* prior;
    struct LNode* next;
}CircularDLinkNode;

// 初始化循环双链表（创建一个空链表）
void InitCircularDoubleList(CircularDLinkNode* &L) {
    L = (CircularDLinkNode*)malloc(sizeof(CircularDLinkNode));
    L->prior = L->next = L;
}

// 判断循环双链表是否为空
bool IsEmpty(CircularDLinkNode* L) {
    if(L->next == L)
        return true;
    else
        return false;
}

// 头插法建立循环双链表
void HeadInsert(CircularDLinkNode* &L, int a[], int n) {

    // 新结点指针
    CircularDLinkNode* s;

    for(int i = 0; i < n; i++) {
        s = (CircularDLinkNode*)malloc(sizeof(CircularDLinkNode));
        s->data = a[i];

        // 以下几句是核心语句
        if(i == 0) {
            // 头插法的第一个结点在链表建立完成后是最后一个结点，循环链表，所以指向头结点
            s->next = L;
            L->next = s;
            L->prior = s;
            s->prior = L;
        }
        else {
            // 第一个结点之后要插入的结点，此时头结点后面必有一个结点，要修改头结点后面结点的 prior指针
            s->next = L->next;
            L->next->prior = s;
            L->next = s;
            s->prior = L;
        }

    }

}

// 尾插法建立循环双链表
void TailInsert(CircularDLinkNode* &L, int a[], int n) {

    // 表尾指针和新结点指针
    CircularDLinkNode *r = L, *s;

    for(int i = 0; i < n; i++) {
        s = (CircularDLinkNode*)malloc(sizeof(CircularDLinkNode));
        s->data = a[i];

        // 以下几句是核心语句
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = L;
    L->prior = r;

}

// 插入数据元素
bool InsertElement(CircularDLinkNode* L, int i, int e) {
    CircularDLinkNode *p = L, *s;

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
    else{
        s = (CircularDLinkNode*)malloc(sizeof(CircularDLinkNode));
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
bool DeleteElement(CircularDLinkNode* L, int i, int &e) {
    // p 指向被删除结点的前一个结点，q 指向将要删除的结点
    CircularDLinkNode *p = L, *q;

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

// 获取循环双链表的长度
int GetLength(CircularDLinkNode* L) {
    int len = 0;
    CircularDLinkNode* p = L->next;

    while(p != L) {
        len++;
        p = p->next;
    }
    return len;
}

// 显示循环双链表
void Display(CircularDLinkNode* L) {
    CircularDLinkNode* p = L->next;

    while(p != L) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

/*     // 检查是否循环，逆序输出
    CircularDLinkNode* q = p->prior;
    while(q != L){
        cout << q->data << " ";
        q = q->prior;
    }
    cout << endl; */
}

// 销毁循环双链表
void DestroyList(CircularDLinkNode* &L) {

    // pre 指向 p的前驱结点
    CircularDLinkNode *pre = L, *p = L->next;
    while(p != L) {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

int main(){
    CircularDLinkNode* L;
    InitCircularDoubleList(L);
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / 4;
    int e;

    // HeadInsert(L, a, n);
    TailInsert(L, a, n);

    // cout << GetLength(L) << endl;

    InsertElement(L, 7, 7);
    InsertElement(L, 3, 8);
    Display(L);
    cout << GetLength(L) << endl;
    DeleteElement(L, 2, e);
    Display(L);
    cout << e << endl;

    // cout << e << endl;

}