#include <iostream>
using namespace std;

int findmin(int r[])
{
    if (r[10] % 2 == r[2] % 2 && r[10] % 5 == r[5] % 5 && //检查余数冲突 10,9,8,6,4
        r[9] % 3 == r[3] % 3 &&
        r[8] % 2 == r[2] % 2 && r[8] % 4 == r[4] % 4 &&
        r[6] % 2 == r[2] % 2 && r[6] % 3 == r[3] % 3 &&
        r[2] % 2 == r[2] % 2)
    {
        for (int i = 0; i < 2520; i++) //所有余数没有冲突，2~10最小公倍数为5*7*8*9=2520
        {
            if (i % 5 == r[5] && i % 7 == r[7] && i % 8 == r[8] && i % 9 == r[9]) //检查余数是否相等
                return i;
        }
    }
    else
        return -1;
}

int main()
{
    int r[11];
    cout << "Please enter the remainder of mod10~2: " << endl;
    for (int i = 10; i > 1; i--)
        cin >> r[i];
    if (findmin(r) == -1)
        cout << "No solution!" << endl;
    else
        cout << findmin(r) << endl;
}