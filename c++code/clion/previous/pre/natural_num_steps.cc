#include <iostream>
using namespace std;

void display(int i, int m)
{
    for (int k = i; k <= m; k++)
    {
        cout << k;
        if (k != m)
            cout << "+";
    }
    cout << endl;
}

void fun(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i, sum = 0; j <= n; j++)
        {
            if (sum < n)
                sum = sum + j;
            else if (sum == n)
            {
                display(i, j - 1); //当sum中的值与n相等时，j比sum中的自然数段最后一个多一，输出j-1
                break;             //且当只有一个数和n相等时，不会输出，因为此时display中的k>m
            }
            else
                break;
        }
    }
}

int main()
{
    int n;
    cout << "Please enter a number: " << endl;
    cin >> n;
    fun(n);
    return 0;
}
