#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ps;

void Insert(vector<int> s, int k, int i, vector<vector<int>> &ps1)
{ //s为ps的一个元素，k为插入元素a[i]，i为a[i]的下表
    vector<int> s1;
    vector<int>::iterator it;
    for (int j = 0; j < i + 1; j++) //将k插入到ps中每个元素的每个位置
    {
        s1 = s;
        it = s1.begin() + j;
        s1.insert(it, k);
        ps1.push_back(s1);
    }
}

void Perm(int a[], int n) //全排列
{
    vector<vector<int>>::iterator it;
    for (int i = 1; i < n; i++) //从a[1]开始，将a[i]插入到ps
    {
        vector<vector<int>> ps1;                    //临时存放存放子排列
        for (it = ps.begin(); it != ps.end(); it++) //遍历ps
            Insert(*it, a[i], i, ps1);              //将a[i]插入到ps的每个元素中
        ps = ps1;                                   //将插入a[i]后的新子排列保存到ps中
    }
}

void displayps() //显示全排列结果
{
    vector<vector<int>>::reverse_iterator it;
    vector<int>::iterator sit;
    for (it = ps.rbegin(); it != ps.rend(); it++)
    {
        for (sit = (*it).begin(); sit != (*it).end(); sit++)
            cout << *sit;
        cout << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {7, 2, 5};

    vector<int> s;
    s.push_back(a[0]);
    ps.push_back(s); //初始化ps={{a[0]}}

    Perm(a, sizeof(a) / 4);
    cout << "The full arrangement results are: " << endl;
    displayps();
}