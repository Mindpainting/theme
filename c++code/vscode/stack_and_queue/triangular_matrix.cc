#include <iostream>
#define MAXSIZE 50
using namespace std;

/* 三角矩阵 主对角线 + 下三角区
1,0,0
2,3,0
4,5,6
 */

// 行优先
// 行：  1    2    3    i-1
// 个数：1    2    3    i-1
int function1(int i, int j, int n) {
    int k;
    if (i >= j)
        k = i*(i - 1)/2 + j - 1;
    else
        k = n*(n + 1)/2;
    return k;
}

// 列优先
// 列：  1    2    3    j-1
// 个数：n    n-1  n-2  n-j+2
int function2(int i, int j, int n) {
    int k;
    if (i >= j)
        k = (j-1)*(2*n-j+2)/2 + i - j;
    else
        k = n*(n + 1)/2;
    return k;
}

int main() {
    int array[MAXSIZE];
    int n = 3;
    for (int i = 0; i < 6; ++i) {
        array[i] = i + 1;
    }
    array[6] = 0;
    int k1 = function1(3, 2, n);
    int k2 = function2(3, 2, n);
    cout << array[k1] << endl;
    cout << array[k2] << endl;
}