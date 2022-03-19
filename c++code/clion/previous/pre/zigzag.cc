#include <iomanip>
#include <iostream>

using namespace std;

void glyphs(int n, int matrix[][50])
{
	int i = 0, j = 0, num = 1;
	for (int k = 0; k < 2 * n - 1; k++) // k为斜行号
	{
		if ((i + j) % 2 == 0) //偶数行（斜行号）
		{
			while (j < n && i >= 0) //偶数行从左下向右上排列，j<n判断是否超出最大列号
				matrix[i--][j++] = num++;
			if (j == n)
			{ //超出最大列号，向下移动
				i = i + 2;
				j = n - 1;
			}
			else if (i < 0) //向右移动
				i = 0;
		}
		else //奇数行
		{
			while (i < n && j >= 0) //奇数行从右上向左下排列 ，i<n判断是否超出最大行号
				matrix[i++][j--] = num++;
			if (i == n)
			{ //超出最大行号，向右移动
				i = n - 1;
				j = j + 2;
			}
			else if (j < 0)
				j = 0; //向下移动
		}
	}
}

void display(int n, int matrix[][50])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << left << matrix[i][j];
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int matrix[50][50] = { 0 };
	int n;
	cout << "Please enter the size of the glyphs n=: ";
	cin >> n;
	glyphs(n, matrix);
	display(n, matrix);
	return 0;
}