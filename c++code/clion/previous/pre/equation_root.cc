#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double fun1(double x) //计算迭代数代入方程的值
{
    return x * x * x - 3 * x - 1;
}

double fun2(double x) //计算迭代数代入方程导数的值
{
    return 3 * x * x - 3;
}

double iteration(double x)
{
    double y, e = 1e-7;
    do
    {
        y = x - fun1(x) / fun2(x); //牛顿迭代公式
        x = y;
    } while (fabs(fun1(y)) > e); //当预测值y带入方程的结果和0相差小于e时结束
    return y;
}

int main()
{
    double x;
    const double PI = 3.1415926;
    cout << "Please enter the starting point of the iteration: ";
    cin >> x;
    cout << "The real root is: " << setprecision(8) << iteration(x) << endl;
    cout << "The error is: " << setprecision(2) << scientific << fabs(2 * cos(PI / 9) - iteration(x)) << endl;
    //setprecision()设置整个小数的精度
    //setprecision()和scientific连用设置小数点后的精度
    return 0;
}

/* 
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double fun(double x)   //计算区间端点的函数值
{
	return x * x * x - 3 * x - 1;
}

double dichotomy(double a, double b)   //二分法
{
	double midpoint, e = 1e-7;

	if (fun(a) * fun(b) > 0)
		return false;
	else
	{
		do {
			midpoint = (a + b) / 2.0;

			if (fun(a) * fun(midpoint) < 0)   //左半区间
				b = midpoint;

			if (fun(b) * fun(midpoint) < 0)   //右半区间
				a = midpoint;
		} while (fabs(a - b) > e);   
	}
	return midpoint;
}

int main()
{
	double a, b;
	const double PI = 3.1415926;
	cout << "Please enter a interval a~b: ";
	cin >> a >> b;
	cout << "The real root is: " << setprecision(8) << dichotomy(a, b) << endl;
	cout << "The error is: " << setprecision(2) << scientific << fabs(2 * cos(PI / 9) - dichotomy(a, b)) << endl;
	return 0;
}
 */
