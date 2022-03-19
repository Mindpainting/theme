#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 最长公共子序列 */

const int MAX = 21;
int dp[MAX][MAX];

void LCSlength(string a, string b, int m, int n)
{
    int i, j;
    for (i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (j = 0; j <= n; j++)
        dp[0][j] = 0;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
}

void getLCS(int m, int n, string a)
{
    vector<char> s;
    int k = dp[m][n]; //k为a,b最长公共子序列的长度
    int i = m, j = n;
    while (k > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        if (dp[i][j] == dp[i][j - 1])
            j--;
        else
        {
            s.push_back(a[i - 1]);
            i--;
            j--;
            k--;
        }
    }
    vector<char>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it;
    cout << endl;
}

int main()
{
    string a, b;
    a = "abcbdb";
    b = "acbbabdbb";
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    int m, n;
    m = a.length();
    n = b.length();

    LCSlength(a, b, m, n);
    cout << "The length of longest common subsequence is: " << dp[m][n] << endl;

    cout << "The longest common subsequence is: ";
    getLCS(m, n, a);
    return 0;
}