/* 顺序存储的循环队列 */

// 判断队空和对满的方法二：设置一个记录队列当前长度的变量

#include <iostream>
#define MAXSIZE 5
using namespace std;

typedef struct SequenceQueue {
    int data[MAXSIZE];
    int front, rear;

    // 记录队列当前长度
    int size;
} SqQueue;

// 初始化队列
void InitQueue(SqQueue &q) {
    q.front = q.rear = q.size = 0;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue &q) {
    return (q.size == 0);
}

// 入队 rear
bool EnQueue(SqQueue &q, int e) {
    // 队满，返回false
    if(q.size == MAXSIZE)
        return false;
    q.data[q.rear] = e;
    q.size++;

    // 让队尾指针环形移动
    q.rear = (q.rear + 1) % MAXSIZE;
    return true;
}

// 出队 front
bool DeQueue(SqQueue &q, int &e) {
    // 队空，返回false
    if(q.size == 0)
        return false;
    e = q.data[q.front];
    q.size--;

    // 让队头指针环形移动
    q.front = (q.front + 1) % MAXSIZE;
    return true;
}

// 获取队头元素的值
bool GetHead(SqQueue q, int &e) {
    if(q.size == 0)
        return false;
    e = q.data[q.front];
    return true;
}

// 获取队列元素个数
int GetLength(SqQueue &q) {
    // 队尾指针指向的地方还没有元素
    return q.size;
}

void Display(SqQueue &q) {
    if(q.size == MAXSIZE) {
        for(int i = 0; i < MAXSIZE; i++) {
            cout << q.data[i] << " ";
        }
        cout << endl;
    } else {
        int i = q.front;
        while(i != q.rear) {
            cout << q.data[i] << " ";
            i = (i + 1) % MAXSIZE;
        }
        cout << endl;
    }
}

int main() {
    SqQueue q;
    InitQueue(q);
    // cout << QueueEmpty(q) << endl;

    EnQueue(q, 1);
    EnQueue(q, 2);
    EnQueue(q, 3);
    EnQueue(q, 4);
    EnQueue(q, 5);
    // cout << EnQueue(q, 6) << endl;// 队满，输出 0

    int e;
    // DeQueue(q, e);
    GetHead(q, e);
    cout << e << endl;
    cout << GetLength(q) << endl;
    Display(q);
}