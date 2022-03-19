#include <iostream>
using namespace std;

void display(int a[])
{
    cout << a[0] << "," << a[1] << "," << a[2] << "," << a[3] << endl;
}

int exchange(int m, int a[])
{
    static int count = 0;
    for (int i = 1; i < 10; i++)
    {
        a[0] = i;
        for (int j = 1; j < (m - 10 * i) / 5; j++)
        {
            a[1] = j;
            for (int k = 1; k <= (m - 10 * i - 5 * j) / 2; k++)
            {
                a[2] = k;
                int p = m - 10 * i - 5 * j - 2 * k;
                a[3] = p;
                if (p == 0)
                    break;
                else
                {
                    count++;
                    display(a);
                }
            }
        }
    }
    return count;
}

int main()
{
    int a[4];
    int money;
    cout << "Please enter the money: ";
    cin >> money;
    cout << "10,5,2,1:" << endl;
    cout << "total = " << exchange(money, a) << endl;
    return 0;
}