/* 顺序表 */

#include <iostream>
#define MAXSIZE 10
using namespace std;

typedef struct {
    // 顺序表静态分配（数组实现）
    int data[MAXSIZE];
    int length;
}SqList;

// 在顺序表 L的第 i 个位置插入指定元素 e
bool ListInsert(SqList &L, int i, int e) {

    // 判断 i 的范围是否有效，存储空间是否已满
    // 当顺序表的长度为 0时，只有 i 等于 1 时才可以正常插入
    if(i < 1 || i > L.length + 1 || L.length == MAXSIZE)
        return false;

    for(int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j-1];
    }

    L.data[i-1] = e;
    L.length++;
    return true;   
}

// 删除顺序表 L中第 i 个位置的元素并返回元素 e
bool ListDelete(SqList &L, int i, int &e) {

    if(i < 1 || i > L.length)
        return false;
    e = L.data[i-1];

    for(int j = i; j < L.length; j++) {
        L.data[j-1]=L.data[j];
    }

    L.length--;
    return true;
}

// 按位查找
int GetElem(SqList L, int i) {
    return L.data[i-1];
}

// 按值查找，返回查找元素的位序
int LocateElem(SqList L, int e) {
    for(int i = 0; i < L.length; i++) {
        if(L.data[i] == e)
            return i + 1;
    }
    return 0;
}

// 顺序表初始化
void InitList(SqList &L) {
    for(int i = 0; i < MAXSIZE; i++) {
        L.data[i] = 0;
    }
    // 顺序表初始长度为零
    L.length = 0;
}

int main() {
    SqList L;
    int e = 4;
    InitList(L);
    ListInsert(L, 1, 3);
    ListInsert(L, 2, 4);
    ListInsert(L, 3, 5);
    ListDelete(L, 2, e);
    for(int i = 0; i < L.length; i++) {
        cout << L.data[i] << endl;
    }
    return 0;
}