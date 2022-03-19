#include <iostream>
#include <queue>
using namespace std;

bool Enter(queue<int> q[], int m, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (q[i].empty() ||
			(!q[i].empty() &&
				q[i].back() < m)) // 队空或队不空，队尾元素小于将要进队的元素
		{
			cout << m << " Enter buffer rail " << i << endl;
			q[i].push(m);
			return true;
		}
	}
	return false;
}

void Output(queue<int> q[], int n, int& min)
{
	for (int i = 0; i < n; i++)
	{
		if (!q[i].empty() && q[i].front() == min)
		{
			cout << "output " << q[i].front() << " from buffer rail " << i << endl;
			q[i].pop(); //队头出队
			min++;
			i = -1; //继续在同一缓冲轨找下一个输出车厢，找不到，则换下一个缓冲轨
		}
	}
}
int main()
{
	int nums, min = 1;
	const int q_num = 2; //队列数
	cout << "Please enter the number of train carriages:" << endl;
	cin >> nums; //读入火车车厢总数
	queue<int> q[q_num];
	int SerNum[100]; //每节车厢的编号
	cout << "Please enter the number of each carriage:" << endl;
	for (int i = 0; i < nums; i++)
		cin >> SerNum[i];
	for (int i = nums - 1; i >= 0; i--)
	{
		if (SerNum[i] == min)
		{
			cout << "output " << SerNum[i] << endl;
			min++;
			Output(q, q_num, min);
		}
		else
		{
			if (Enter(q, SerNum[i], q_num) == 0)
			{
				cout << "Not enough buffer rail!"
					 << endl; // 队不空且队尾元素大于将要进队的元素
				break;
			}
		}
	}
}
