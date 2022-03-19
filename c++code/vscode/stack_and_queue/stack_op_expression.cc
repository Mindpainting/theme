#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

// 中缀表达式：A + B * (C - D) - E / F

/*
"左优先"原则：只要左边的运算符能先计算，就优先算左边的
后缀表达式：

"左优先"，使用，表达式中从左到右运算符出现的顺序和中缀表达式的运算符生效的顺序一致，适合计算机计算使用，计算效率高
A B C D - * + E F / -

不是"左优先"原则，计算机计算不使用
A B C D - * E F / - +

算法实现是从左向右扫描后缀表达式
*/

/*
"右优先"原则：只要右边的运算符能先计算，就优先算右边的
前缀表达式：
"右优先"，使用，表达式中运算符从右到左出现的顺序和中缀表达式的运算符生效的顺序一致，适合计算机计算使用，计算效率高
+ A - * B - C D / E F

不是"左右先"原则，计算机计算不使用
- + A * B - C D / E F

算法实现是从右向左扫描前缀表达式
*/

// 判断运算符优先级
int Precede(char a, char b) // a 为栈顶运算符，b 为 exp[i]
{
	// s1为栈顶元素可能的取值，s2为 exp[i]可能的取值
	string s1 = "=(+-*/)", s2 = "=(+-*/)";
	int m = 0, n = 0, PriM[7][7] = {   // 运算符优先级矩阵
		0,-1,-1,-1,-1,-1,-1,
		1,-1,-1,-1,-1,-1,0,
		1,-1,1,1,-1,-1,1,
		1,-1,1,1,-1,-1,1,
		1,-1,1,1,1,1,1,
		1,-1,1,1,1,1,1,
		1,0,1,1,1,1,1
	};
	while (s1[m] != a)  // s1逐个和栈顶元素比较，找到栈顶元素在矩阵中所对应的行号
		m++;
	while (s2[n] != b)  // s2逐个和 exp[i] 比较，找到 exp[i] 在矩阵中所对应的行列号
		n++;
	return PriM[m][n];  // 输出行列号在矩阵中所对应的数值，即为栈顶元素和 exp[i] 优先级的比较结果
}

// 判断是否输入的是正确的运算符
bool judgement(char ch)
{
	if (ch == '(' || ch == ')' || ch == '+' || ch == '-'
		|| ch == '*' || ch == '/')
		return true;
	else
		return false;
}

// 中缀表达式转后缀表达式
int transformation(string& exp1, string& postexp1)// 参数采用引用
{
	stack<char> opr;
	opr.push('=');
	int i = 0, j = 0;
	while (exp1[i] != '\0')
	{
		if (exp1[i] >= '0' && exp1[i] <= '9')// 若为数字字符，则将后续的所有数字均依次存放到postexp中,并以字符'#'标志数值串结束
		{
			while (exp1[i] >= '0' && exp1[i] <= '9')
				postexp1[j++] = exp1[i++];
			postexp1[j++] = '#';
		}
		else
		{
			if (judgement(exp1[i]) != 0)// 判断是否输入的是正确的运算符
			{
				switch (Precede(opr.top(), exp1[i]))
				{
				case -1:               // 栈顶运算符优先级低，进栈
					opr.push(exp1[i]);
					i++;
					break;
				case 0:      // 只有栈顶为 '(' exp[i] 为 ')' 时满足这种情况
					opr.pop(); // 将 '(' 出栈
					i++;
					break;
				case 1:               // 栈顶运算符优先级高，栈顶运算符出栈放入postexp中
					postexp1[j++] = opr.top();
					opr.pop();
					break;
				}
			}
			else {
				cout << "ERROR!!!" << endl;
				for (int k = 0; k < 100; k++)  // 清空postexp,全赋值为 '\0',否则错误运算符之前的有效字符会残留
					postexp1[k] = '\0';
				return -1;   // 给出输入运算符出错信息
				break;
			}
		}
	}
	while (opr.top() != '=')  // 字符串exp扫描完毕,将运算符栈opr中'='之前的所有运算符依次出栈并存放到postexp中
	{
		postexp1[j++] = opr.top();
		opr.pop();
	}
	return 0;
}

// 后缀表达式求值
double calculate(string postexp)
{
	stack<double> opd;
	int i = 0, flag = 0;
	double a = 0, b = 0, c, d, result;
	while (postexp[i] != '\0')
	{
		if (!(postexp[i] >= '0' && postexp[i] <= '9'))  // 当 postexp[i] 是运算符时出栈两个元素
		{
			b = opd.top();       // 返回栈顶元素的引用,不出栈栈顶元素
			opd.pop();          // 将栈顶元素出栈，因为 pop() 函数返回值为 void 型，所以不能 b=opd.pop()
			a = opd.top();
			opd.pop();
		}
		switch (postexp[i])
		{
		case '+':
			c = a + b;
			opd.push(c);
			break;
		case '-':
			c = a - b;
			opd.push(c);
			break;
		case '*':
			c = a * b;
			opd.push(c);
			break;
		case '/':
			if (b == 0) {      // 除数为零两种情况，一是栈中恰有两个元素，取出栈中两个元素，不计算结果放入栈中，导致栈为空
				flag = -1;           // 给出除数为零的信息
				cout << "Divide by zero excepition!" << endl;// 二是，栈中多于两个元素，取出栈中两个元素后，栈虽不为空，但返回值不是计算的正确结果
				break;
			}
			else {
				c = a / b;
				opd.push(c);
				break;
			}
		default:
			d = 0;
			while (postexp[i] >= '0' && postexp[i] <= '9')  // 循环将字符转换为正确的数字放入 opd 栈内
			{
				d = d * 10 + postexp[i] - '0';
				i++;        // 当数字正确转换后，执行 i++ 此时 postexp[i] 为 '#'
			}
			opd.push(d);   // 转换正确的数字入栈
		}
		if (flag == -1)   
			break;
		i++;              // 执行 i++ 后，此时 postexp[i] 已是下一个数字字符，所以 switch 不用考虑字符为 '#' 的情况
	}
	if (flag == -1) {
		result = -1;
		cout << "Calculation Failure!" << endl;
	}
	else
		result = opd.top(); // 返回栈顶元素，即为表达式的结果
	return result;
}

int main()
{
	string exp, postexp;
	cout << "Please enter a positive integer expression:" << endl;
	cin >> exp;
	for (int k = 0; k <100; k++)   // 由于postexp未初始化，而 string 类不允许采用单个字符赋值给 未初始化的 postexp 以 postexp[j++] 的形式，
		postexp = postexp + '\0';  // 所以，使用string类的字符串连接方式对 postexp 初始化，初始化的空间要足够大
	while (transformation(exp, postexp) == -1) 
	{
		cout << endl;
		cout <<"Please enter the correct expression:" << endl;
		cin >> exp;
	}
	cout << "The postexp is: " << postexp << endl;
	cout << "The result is: " << calculate(postexp) << endl;
	return 0;
}