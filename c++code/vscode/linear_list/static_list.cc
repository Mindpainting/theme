#include <iostream>
#define MAXSIZE 10
using namespace std;

typedef struct {
    int data;
    int next;
}StaticList[MAXSIZE];

void InitStaticList(){

}

int main(){
    StaticList L;
    cout << sizeof(L) << endl;
    return 0;
}