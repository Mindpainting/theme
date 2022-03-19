/* 顺序存储的循环队列 */

// 判断队空和对满的方法三：tag变量，tag=0（tag=1） 时，若因删除（插入）导致q.front=q.rear，则队空（队满）；
// 每次出队操作成功时，都令 tag=0，每次入队操作成功时，都令 tag=1

#include <iostream>
#define MAXSIZE 5
using namespace std;

typedef struct SequenceQueue {
    int data[MAXSIZE];
    int front, rear;
    int tag;
} SqQueue;

// 初始化队列
void InitQueue(SqQueue &q) {
    q.front = q.rear = q.tag = 0;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue &q) {
    if(q.front == q.rear && q.tag == 0)
        return true;
    else
        return false;
}

// 入队 rear
bool EnQueue(SqQueue &q, int e) {
    // 队满，返回false
    if(q.front == q.rear && q.tag == 1)
        return false;
    q.data[q.rear] = e;
    q.tag = 1;

    // 让队尾指针环形移动
    q.rear = (q.rear + 1) % MAXSIZE;
    return true;
}

// 出队 front
bool DeQueue(SqQueue &q, int &e) {
    // 队空，返回false
    if(q.front == q.rear && q.tag == 0)
        return false;
    e = q.data[q.front];
    q.tag = 0;

    // 让队头指针环形移动
    q.front = (q.front + 1) % MAXSIZE;
    return true;
}

// 获取队头元素的值
bool GetHead(SqQueue q, int &e) {
    if(q.front == q.rear && q.tag == 0)
        return false;
    e = q.data[q.front];
    return true;
}

// 获取队列元素个数
int GetLength(SqQueue &q) {
    // 队尾指针指向的地方还没有元素
    if(q.front == q.rear && q.tag == 0)
        return 0;
    else if(q.front == q.rear && q.tag == 1)
        return MAXSIZE;
    else
        return (q.rear + MAXSIZE - q.front) % MAXSIZE;
}

void Display(SqQueue &q) {
    if(q.front == q.rear && q.tag == 1) {
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
    // EnQueue(q, 5);
    // cout << EnQueue(q, 6) << endl;// 队满，输出 0

    int e;
    // DeQueue(q, e);
    GetHead(q, e);
    cout << e << endl;
    cout << GetLength(q) << endl;
    Display(q);
}