#include <iostream>

using namespace std;
#define Size 100

typedef struct Seum //Seum 和 SerialNum交换则会报错不允许使用不完整的类型说明
{
    int Serial_number;
    struct Seum *next;
} SerialNum;

void CreateList(Seum *&L, int n) //尾插法建立链表
{
    Seum *s, *r;
    L = (Seum *) malloc(sizeof(Seum));
    r = L;
    for (int i = 1; i <= n; i++) {
        s = (Seum *) malloc(sizeof(Seum));
        s->Serial_number = i;
        r->next = s;
        r = s;
    }
    r->next = L->next; //最后一个节点指向第一个节点，而不是头节点
}

//约瑟夫环模拟过程
void Sim_process(Seum *&L, int n, int m, int a[]) {
    Seum *p, *q, *t;
    p = L->next;
    q = L;
    int count = 1, i = 0;
    while (p != q) //分析知还剩一个人的时候p=q,所以p!=q进入循环
    {
        while (count != m) {
            p = p->next;
            q = q->next;
            count++;
        }
        a[i++] = p->Serial_number; //当找到要出列人时p指向所对相应的节点，将编号保存至数组
        t = p;
        p = p->next;
        q->next = p;
        if (p != q)
            free(t);
        count = 1; //count重置为1，开始下一轮循环
    }
    a[i] = p->Serial_number; //两个循环结束后，此时只剩最后一人，将其编号保存至数组
    free(p);
}

int main() {
    int m, n, a[Size]; //数组用来存放出列人的编号数
    Seum *L;
    cout << "请输入总编号数：";
    cin >> n;
    cout << "请输入报停时的数：";
    cin >> m;
    if (n <= 0 || m <= 0)
        cout << "ERROR" << endl;
    else {
        CreateList(L, n);
        Sim_process(L, n, m, a);
        cout << "依次出列的顺序为: ";
        for (int i = 0; i < n; i++) //输出出列人的编号的次序
            cout << a[i] << " ";
        cout << endl;
        free(L);
    }
    return 0;
}