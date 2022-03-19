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

bool testplace(int i) //测试i行的q[i]列上能否放置皇后
{
    int j = 1;
    if (i == 1)
        return true; //第一个皇后总是可以放置
    while (j < i)    //j=1...i-1是已经放置了皇后的行
    {
        if ((q[i] == q[j]) || (fabs(q[i] - q[j]) == fabs(i - j))) //新皇后与已经放置的每一个皇后是否有冲突
            return false;
        j++; //若与前一个皇后没有冲突，则与下一个皇后比较
    }
    return true; //新皇后与已放置的每一个皇后都没有冲突，则返回真
}

void queen(int n)
{
    int i = 1;     //i表示行号，也表示放置第i个皇后
    q[i] = 0;      //q[i]当前列号，每个新皇后都置初始位置为0列
    while (i >= 1) //尚未回溯到头，循环放置皇后
    {
        q[i]++;                            //原位置后移一列
        while (q[i] <= n && !testplace(i)) //试探位置(i,q[i])
            q[i]++;                        //当前列不能放置皇后，后移一列

        if (q[i] <= n) //为第i个皇后找到了合适的位置
        {
            if (i == n)         //皇后放置完
                dissolution(n); //输出一个解

            else //皇后没有放置完
            {
                i++;      //转下一行，放置新皇后
                q[i] = 0; //每个新皇后都置初始位置为0列
            }
        }
        else
            i--; //若第i个皇后找不到合适的位置，则回溯到上一个皇后(上一行)
    }
    //当i<1说明第一个皇后所有位置已回溯完毕，算法结束
}

int main()
{
    int n;
    cout << "Please enter n queen problem n=: ";
    cin >> n;
    if (n > 20)
        cout << "ERROR" << endl;
    else
        queen(n);
}
