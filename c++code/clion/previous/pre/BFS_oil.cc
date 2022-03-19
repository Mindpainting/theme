#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int cap[] = {10, 7, 3};

vector<int> transform(vector<int> state, int a, int b)
{
    if (state[a] > cap[b] - state[b])
    {
        state[a] -= cap[b] - state[b];
        state[b] = cap[b];
    }
    else
    {
        state[b] += state[a];
        state[a] = 0;
    }
    return state;
}

bool fun(vector<int> check, int num) //检验当前三个容器中的状态量是否有重复
{
    for (int i = 0; i < check.size(); i++)
    {
        if (check[i] == num)
            return false;
    }
    return true;
}

void display(vector<vector<int>> solution) //输出分油次数最少的详细操作过程
{
    for (int i = 0; i < solution.size(); i++)
    {
        for (int j = 0; j < solution[i].size(); j++)
        {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(vector<int> start) //盲目BFS搜索
{
    vector<vector<int>> solution;
    int num;
    num = start[0] * 100 + start[1] * 10 + start[2] * 1;
    vector<int> check;
    check.push_back(num);

    queue<vector<int>> q;
    q.push(start);

    while (!q.empty())
    {
        vector<int> f;
        f = q.front();

        if (f[0] == 5 && f[1] == 5)
        {
            solution.push_back(f);
            break;
        }

        solution.push_back(f);
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            if (f[i] != 0)
            {
                for (int j = 1; j < 3; j++)
                {
                    vector<int> c;
                    c = transform(f, i, (i + j) % 3);
                    num = c[0] * 100 + c[1] * 10 + c[2] * 1;
                    if (fun(check, num))
                    {
                        check.push_back(num);
                        q.push(c);
                    }
                }
            }
            else
                continue;
        }
    }

    display(solution);
}

int main()
{
    int s[] = {10, 0, 0};
    vector<int> start(s, s + 3);
    bfs(start);
}