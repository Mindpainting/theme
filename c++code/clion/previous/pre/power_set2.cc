#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ps; //存放幂集

void Inserti(int i)
{
    vector<vector<int>> ps1;
    vector<vector<int>>::iterator it;
    ps1 = ps;
    for (it = ps1.begin(); it != ps1.end(); it++) //向ps中每个元素后面插入i
        (*it).push_back(i);
    for (it = ps1.begin(); it != ps1.end(); it++) //合并插入i后的幂集ps和插入i前的幂集ps1，放在ps中
        ps.push_back(*it);
}

void SolvePs(int i, int n) //递归求1~n的幂集
{
    if (i <= n)
    {
        Inserti(i);
        SolvePs(i + 1, n);
    }
}

void displayps() //显示1~n的幂集
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
    int n = 3;
    vector<int> s;
    ps.push_back(s); //向ps中插入一个空元素来表示，空集{}
    SolvePs(1, n);
    cout << "A power set of 1 to " << n << ":" << endl;
    displayps();
}