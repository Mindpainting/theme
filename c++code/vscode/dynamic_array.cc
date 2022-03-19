#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	srand(time(NULL));  //更新随机数种子
	int row, col;
	cout << "Please enter the row and col: ";
	cin >> row >> col;
	int* *p = new int* [row];  //指针数组
	for (int i = 0; i < row; i++)
	{
		p[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			p[i][j] = rand() % 10;  //rand()返回0~RAND_MAX,输出0~9的随机数
		}
	}
	//取得a~b之间的随机数a+rand()%n;a是起始值，n是a~b之间数的个数
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << p[i][j] << " ";
			if (j == col - 1)
				cout << endl;
		}
	}

	for (int i = 0; i < row; i++)
	{
		delete[] p[i];
	}
	delete[] p;   //删除指向指针数组首地址的指针

}