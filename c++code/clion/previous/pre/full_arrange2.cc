#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ps;

void Insert(vector<int> s, int i, vector<vector<int>> &ps1)
{
    vector<int> s1;
    vector<int>::iterator it;
    for (int j = 0; j < i; j++)
    {
        s1 = s;
        it = s1.begin() + j;
        s1.insert(it, i);
        ps1.push_back(s1);
    }
}

void Perm(int i, int n)
{
    vector<vector<int>>::iterator it;
    if (i <= n)
    {
        vector<vector<int>> ps1;
        for (it = ps.begin(); it != ps.end(); ++it)
            Insert(*it, i, ps1);
        ps = ps1;
        Perm(i + 1, n);
    }
}

void displayps()
{
    vector<vector<int>>::reverse_iterator it;
    vector<int>::iterator sit;
    for (it = ps.rbegin(); it != ps.rend(); ++it)
    {
        for (sit = (*it).begin(); sit != (*it).end(); ++sit)
            cout << *sit;
        cout << " ";
    }
    cout << endl;
}

int main()
{
    int n = 4;
    cout << "1~" << n << "全排列: " << endl;
    vector<int> s;
    s.push_back(1);
    ps.push_back(s);
    Perm(2, n);
    displayps();
}
