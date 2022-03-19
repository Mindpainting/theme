#include <iostream>
#include <cmath>
#define MAXSIZE 50
using namespace std;

/* 三对角矩阵（带状矩阵） 主对角线 + 下三角区
1,2,0
3,4,5
0,6,7
 */

// 行优先
// 前i-1行元素个数：3(i-1)-1
// a(i,j)是第i行第j-i+2个元素
// a(i,j)是第2*i+j-2个元素，数组从0开始则，下标为2*i+j-3
int function1(int i, int j, int n) {
    int k;
    if (fabs(i-j) <= 1)
        k = 2*i + j - 3;
    else
        k = 3*n - 3;
    return k;
}

// 列优先
int function2(int i, int j, int n) {
    int k;
    if (fabs(i-j) <= 1)
        k = 2*j + i - 3;
    else
        k = 3*n - 3;
    return k;
}

int main() {
    int array[MAXSIZE];
    int n = 3;
    for (int i = 0; i < 3*n-2; ++i) {
        array[i] = i + 1;
    }
    array[3*n-3] = 0;
    int k1 = function1(2, 1, n);
    int k2 = function1(2, 2, n);
    int k3 = function1(2, 3, n);
    int k4 = function1(3, 1, n);
    cout << array[k1] << array[k2] << array[k3] << array[k4]<< endl;
    // cout << array[k2] << endl;
}