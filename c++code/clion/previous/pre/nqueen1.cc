#include <iostream>
#include <cmath>
using namespace std;

const int N = 20;
int q[N];

void dissolution(int n) //输出n 皇后的一个解
{
    static int count = 1;
    cout << "The " << count << " solution:" << endl;
    count++;

    char **p = new char *[n + 1];
    for (int i = 1; i <= n; i++)
        p[i] = new char[n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            p[i][j] = '*';
        }
    }

    for (int i = 1; i <= n; i++)
        p[i][q[i]] = 'Q';

    for (int i = 1; i <= n; i++)
    {
        cout << "               ";
        for (int j = 1; j <= n; j++)
        {
            cout << p[i][j] << " ";
            if (j == n)
                cout << endl;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        delete[] p[i];
    }
    delete[] p;
}

bool testplace(int i, int j) //测试(i,j)位置能否放置皇后
{
    if (i == 1)
        return true; //第一个皇后总是可以放置
    int k = 1;
    while (k < i) //k=1...i-1是已经放置了皇后的行
    {
        if ((q[k] == j) || (fabs(q[k] - j) == fabs(i - k)))
            return false;
        k++;
    }
    return true;
}

void queen(int i, int n) //放置1...i个皇后
{
    if (i > n) //所有皇后放置结束
        dissolution(n);
    else
    {
        for (int j = 1; j <= n; j++)
        {
            if (testplace(i, j)) //在i 行上试探每一个列 j
            {
                q[i] = j;
                queen(i + 1, n);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Please enter n queen problem n=: ";
    cin >> n;
    if (n > 20)
        cout << "ERROR" << endl;
    else
        queen(1, n);
}