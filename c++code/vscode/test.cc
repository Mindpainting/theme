#include <iostream>
using namespace std;

int main()
{
    int a[] = {1, 6, 4, 5, 3, 2, 7};
    int n = sizeof(a) / 4 - 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        cout << a[i] << " ";
    }
}