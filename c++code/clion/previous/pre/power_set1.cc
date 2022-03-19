#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ps; //存放幂集

void SolvePs(int a[], int n)
{
    vector<vector<int>> ps1;
    vector<vector<int>>::iterator it;

    for (int i = 0; i < n; i++)
    {
        ps1 = ps;
        for (it = ps1.begin(); it != ps1.end(); it++) //向ps中每个元素后面插入i
            (*it).push_back(a[i]);

        for (it = ps1.begin(); it != ps1.end(); it++) //合并插入i后的幂集ps和插入i前的幂集ps1，放在ps中
            ps.push_back(*it);
    }
}

void displayps() //显示集合的幂集
{
    vector<vector<int>>::iterator it;
    vector<int>::iterator sit;
    for (it = ps.begin(); it != ps.end(); it++)
    {
        cout << "{";
        for (sit = (*it).begin(); sit != (*it).end(); sit++)
            cout << *sit;
        cout << "}";
    }
    cout << endl;
}

int main()
{
    int a[] = {3, 7, 4};
    vector<int> s;
    ps.push_back(s); //向ps中插入一个空元素来表示，空集{}

    SolvePs(a, sizeof(a) / 4);

    cout << "The power set of a collection: " << endl;
    displayps();
}

/*总结：不能在函数void SolvePs(int a[],int n)中用sizeof(a)/4代替n表示数组的元素个数，
因为，a在SolvePs函数中是一个指向数组a的一个指针*/
