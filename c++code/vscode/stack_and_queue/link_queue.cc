/* 链式队列（带头结点） */

#include <iostream>
using namespace std;

// 链式队列结点
typedef struct LNode
{
    int data;
    struct LNode *next;
} LinkNode;

// 链式队列
typedef struct QNode
{
    LinkNode *front, *rear;
} LinkQueue;

// 初始化链式队列
void InitLinkQueue(LinkQueue &q)
{
    q.front = q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    q.front->next = NULL;
}

// 判断链式队列是否为空
bool IsEmpty(LinkQueue &q)
{
    return (q.front == q.rear);
}

// 入队
void EnQueue(LinkQueue &q, int e)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    q.rear->next = s; // 新结点插入到 rear之后
    q.rear = s;       // 修改队尾指针
}

// 出队（头结点不动，只修改头结点的 next）
bool DeQueue(LinkQueue &q, int &e)
{
    if (q.front == q.rear)
        return false;
    LinkNode *p = q.front->next;
    e = p->data;
    q.front->next = p->next; // 修改头结点的 next指针
    // 最后一个结点出队
    if (p == q.rear)
        q.rear = q.front;
    free(p);
    return true;
}

void Display(LinkQueue q)
{
    LinkNode *p = q.front;
    while (p != q.rear)
    {
        // 输出 p指向的当前结点的下一个结点的值，避免当 p指向尾结点前一个结点时的下一次循环，p指向尾结点判断条件不成立，导致尾结点不会被输出
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    LinkQueue q;
    InitLinkQueue(q);
    // cout << IsEmpty(q) << endl;
    EnQueue(q, 1);
    EnQueue(q, 2);
    EnQueue(q, 3);
    EnQueue(q, 4);
    Display(q);

    int e;
    DeQueue(q, e);
    cout << e << endl;
    Display(q);
    return 0;
}