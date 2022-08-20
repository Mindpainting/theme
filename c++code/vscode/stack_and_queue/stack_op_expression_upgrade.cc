#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <stdexcept>

using namespace std;

//
class zero_divisor : public exception
{
public:
    const char *what(void) const throw()
    {
        return "a divisor is zero";
    }
};

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

// operator（运算符），operand（操作数）

// 判断运算符优先级
int precede(char a, char b) // a 为当前扫描到的运算符，b 为栈顶运算符
{
    /*
    1：当前扫描的运算符比栈顶运算符优先级高
    0：当前扫描的运算符和栈顶运算符优先级相同
    -1：当前扫描的运算符比栈顶运算符优先级低

              s2  (  +  -   *   /   栈顶
            s1 +  1  0, 0, -1, -1,
               -  1  0, 0, -1, -1,
               *  1  1, 1,  0,  0,
               /  1  1, 1,  0,  0,
    */

    string s1 = "+-*/", s2 = "(+-*/";
    int m = 0, n = 0;
    int PriM[4][5] = {
        // 运算符优先级矩阵
        {1, 0, 0, -1, -1},
        {1, 0, 0, -1, -1},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0},
    };
    while (s1[m] != a) // 找到在s1中和当前扫描的运算符相等的运算符的序号，即为当前扫描的运算符在矩阵中的行号
        m++;
    while (s2[n] != b) // 找到在s2中和栈顶运算符相等的运算符的序号，即为栈顶运算符在矩阵中的列号
        n++;
    return PriM[m][n]; // 输出行列号在矩阵中所对应的数值，即为当前扫描的运算符和栈顶运算符优先级的比较结果
}

// 判断是否输入的是合法的表达式
bool judge_exp_legality(string exp)
{
    string::iterator it;
    int flag = 1;
    for (it = exp.begin(); it != exp.end(); ++it)
    {
        if (*it != '(' && *it != ')' && *it != '+' && *it != '-' && *it != '*' && *it != '/' && *it < '0' || *it > '9')
        {
            flag = 0;
            break;
        }
    }
    return flag == 1;
}

void calculate(stack<char> &opr, stack<int> &opd) throw(zero_divisor)
{
    char ch; // 记录运算符栈出栈的运算符
    ch = opr.top();
    opr.pop();

    int a, b; // a记录运算符前面的操作数，b记录运算符后面的操作数
    b = opd.top();
    opd.pop();
    a = opd.top();
    opd.pop();

    int c = 0; // 记录每次出栈的两个操作数的运算结果
    switch (ch)
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
        if (b == 0)
        {
            throw zero_divisor();
        }
        else
        {
            // 这里小小的优化使计算结果四舍五入
            // 將 a 强制转为 double 类型，以得到 double 类型的计算结果
            double t1 = static_cast<double>(a) / b;
            int t2 = a / b;
            if ((t1 - t2) >= 0.5)
                c = t2 + 1;
            else
                c = t2;
            opd.push(c);
            break;
        }
    default:
        break;
    }
}

// 计算中缀表达式的值，将中缀表达式转后缀表达式算法和后缀表达式求值算法结合
int evaluate_infix_expression(string exp) throw(zero_divisor)
{
    stack<char> opr; // 运算符栈
    stack<int> opd;  // 操作数栈

    stack<char> temp; // 将中缀表达式中的数字字符转换为整数
    string::iterator it_exp;
    for (it_exp = exp.begin(); it_exp != exp.end(); ++it_exp)
    {

        if (*it_exp >= '0' && *it_exp <= '9')
        {
            while (*it_exp >= '0' && *it_exp <= '9')
            {
                temp.push(*it_exp);
                it_exp++;
                if (it_exp == exp.end())
                    break;
            }
            it_exp--; // 防止it_exp向后移动两位，直接跳过了一个字符

            int num = 0;            // num 存放计算后多位操作数的整数形式
            int size = temp.size(); // 若直接将 temp.size()写在for循环中，则每执行一次i会增加，temp.size()会减少
            for (int i = 0; i < size; ++i)
            {
                num = num + (temp.top() - '0') * pow(10, i);
                temp.pop();
                if (temp.empty())
                    opd.push(num);
            }
        }
        else
        {
            if (opr.empty())
                opr.push(*it_exp);
            else
            {
                // 左括号，直接进栈
                if (*it_exp == '(')
                    opr.push(*it_exp);

                // 右括号，直到左括号前的运算符出栈，最后左括号出栈
                else if (*it_exp == ')')
                {
                    while (opr.top() != '(')
                    {
                        calculate(opr, opd);
                    }
                    opr.pop(); // 左括号出栈
                }
                // 加减乘除运算符
                else
                {
                    if (precede(*it_exp, opr.top()) == 1) // 当前扫描的运算符优先级高
                        opr.push(*it_exp);

                    else
                    { // 当前扫描的运算符比栈顶运算符优先级低或者相同
                        calculate(opr, opd);
                        opr.push(*it_exp); // 栈顶优先级高的运算符出栈后，优先级低的进栈
                    }
                }
            }
        }
    }
    // 所有表达式扫描完后 opr栈中所有剩余的运算符出栈
    while (!opr.empty())
    {
        calculate(opr, opd);
    }

    return opd.top();
}

int main()
{
    string exp;
    cout << "Please enter a positive integer expression:" << endl;
    cin >> exp;
    if (judge_exp_legality(exp) == true)
    {
        try
        {
            cout << evaluate_infix_expression(exp) << endl;
        }
        catch (const exception &ex)
        {
            cout << ex.what() << endl;
        }
    }
    else
    {
        cout << "Please enter a valid expression:" << endl;
        cin >> exp;
    }
    return 0;
}