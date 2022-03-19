/* 顺序存储的循环队列 */

// 注意：要明确队尾指针是指向队尾元素还是队尾元素的下一个位置，本例是指向队尾元素的下一个位置

// 判断队空和队满的方法一：牺牲一个存储单元，即当判断队满的条件(q.rear + 1)%MAXSIZE == q.front成立时
// 当前尾指针指向的存储单元还未放置元素

#include <iostream>
#define MAXSIZE 5
using namespace std;

typedef struct SequenceQueue
{
    int data[MAXSIZE];
    int front, rear;
} SqQueue;

// 初始化队列
void InitQueue(SqQueue &q)
{
    q.front = q.rear = 0;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue &q)
{
    return (q.front == q.rear);
}

// 入队 rear
bool EnQueue(SqQueue &q, int e)
{
    // 队满，返回false
    if ((q.rear + 1) % MAXSIZE == q.front)
        return false;
    q.data[q.rear] = e;

    // 让队尾指针环形移动
    q.rear = (q.rear + 1) % MAXSIZE;
    return true;
}

// 出队 front
bool DeQueue(SqQueue &q, int &e)
{
    // 队空，返回false
    if (q.front == q.rear)
        return false;
    e = q.data[q.front];

    // 让队头指针环形移动
    q.front = (q.front + 1) % MAXSIZE;
    return true;
}

// 获取队头元素的值
bool GetHead(SqQueue q, int &e)
{
    if (q.front == q.rear)
        return false;
    e = q.data[q.front];
    return true;
}

// 获取队列元素个数
int GetLength(SqQueue &q)
{
    // 队尾指针指向的地方还没有元素
    return (q.rear + MAXSIZE - q.front) % MAXSIZE;
}

void Display(SqQueue &q)
{
    int i = q.front;
    while (i != q.rear)
    {
        cout << q.data[i] << " ";
        i = (i + 1) % MAXSIZE;
    }
    cout << endl;
}

int main()
{
    SqQueue q;
    InitQueue(q);
    // cout << QueueEmpty(q) << endl;

    EnQueue(q, 1);
    EnQueue(q, 2);
    EnQueue(q, 3);
    EnQueue(q, 4);
    // cout << EnQueue(q, 5) << endl;// 队满，输出 0

    int e;
    // DeQueue(q, e);
    GetHead(q, e);
    cout << e << endl;
    cout << GetLength(q) << endl;
    Display(q);
}