#include <iostream>
using namespace std;

bool detection(int x, int y, int z)
{
    int ct[10] = {0}; //记录0~9每一个数字使用的情况
    ct[x / 10] = ct[x / 10] + 1;
    ct[x % 10] = ct[x % 10] + 1;
    ct[y / 100] = ct[y / 100] + 1;
    ct[y / 10 % 10] = ct[y / 10 % 10] + 1;
    ct[y % 10] = ct[y % 10] + 1;
    ct[z / 1000] = ct[z / 1000] + 1;
    ct[z / 100 % 10] = ct[z / 100 % 10] + 1;
    ct[z % 100 / 10] = ct[z % 100 / 10] + 1;
    ct[z % 10] = ct[z % 10] + 1;
    if (ct[0] == 0) //为真，则说明有一个数字零，不符合条件，返回false
    {
        int count = 0;
        for (int i = 1; i < 10; i++)
        {
            if (ct[i] == 1)
                count++;
        }
        if (count == 9) //为真，则说明1~9每一个数字都出现了，且无重复
            return true;
    }
    return false;
}

int main()
{
    for (int x = 12; x < 99; x++)
    {
        for (int y = 123; y < 987; y++)
        {
            int z = x * y; //确定好x,y后，z已固定
            if (z > 9999)
                break;
            if (detection(x, y, z))
                cout << x << "*" << y << "=" << z << endl;
        }
    }
}