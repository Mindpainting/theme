#include <iostream>
#define MaxSize 10
using namespace std;

typedef struct
{
    int data;
    int next;
} StaticList[MaxSize];

void InitStaticList(StaticList &L)
{
    L[0].data = 0;
    L[0].next = -1;
}

int main()
{
    StaticList L;
    cout << sizeof(L) << endl;
    return 0;
}