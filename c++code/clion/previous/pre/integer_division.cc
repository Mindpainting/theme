#include <iostream>
using namespace std;

int x[50] = {0};

int partition(int n, int m)
{
    if ((n < 1) || (m < 1))
        return 0;
    if ((n == 1) || (m == 1))
        return 1;
    if (n < m)
        return partition(n, n);
    if (n == m)
        return partition(n, n - 1) + 1;
    return partition(n, m - 1) + partition(n - m, m);
}

void split(int n, int k) //k是数组中的位置，亦是递归层数
{
    void display(int k);
    int i;
    if (n == 0) //分解完成，输出结果
        display(k);
    else
        for (i = n; i > 0; i--)
            if (k == 0 || i <= x[k - 1])
            {
                x[k] = i; //写入数组
                split(n - i, k + 1);
            }
}

//输出数组前k项
void display(int k)
{
    int i;
    for (i = 0; i < k; i++)
        cout << x[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;
    split(n, 0);
    cout << "total = " << partition(n, n) << endl;
    return 0;
}
