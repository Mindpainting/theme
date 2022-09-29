### 链表



### 栈和队列



### 字符

#### kmp

```c++
#include <iostream>
#include <string>

using namespace std;

// string容器的length()函数返回的是long long unsigned int(unsigned __int64)(size_t)类型
// 这里不会出现负值，所以int和size_t比较不会出现问题
int pattern_string_match(const string& s1, const string& s2) {
    int i = 0, j = 0, k = 0;
    size_t length_s1 = s1.length();
    size_t length_s2 = s2.length();
    while (i < length_s1 && j < length_s2) {
        if (s1[i] == s2[j]) {
            ++i;
            ++j;
        } else {
            k++;
            i = k;
            j = 0;
        }
    }
    if (j >= length_s2)
        return k;
    else
        return 0;
}

// 这里 j 的值可以为负，在和length()函数返回的size_t类型进行比较会出现意想不到的结果
int kmp(const string &s1, const string &s2, const int next[]) {
    int i = 0, j = 0;
    int length_s1 = static_cast<int>(s1.length());
    int length_s2 = static_cast<int>(s2.length());

    while (i < length_s1 && j < length_s2) {
        if (j == -1 || s1[i] == s2[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j >= length_s2)
        return i - length_s2;
    else
        return 0;
}

// 求模式串的 next数组
// next[i]表示在子串的第 i个字符与模式串匹配失败时，则跳到子串的 next[i]位置重新与主串当前位置进行比较
void get_next(const string &s, int next[]) {
    int i = 0, j = -1;
    // next[0] = -1 表示子串的第一个字符和模式串当前的字符匹配失败，则模式串后移一位和子串的第一个字符继续比较
    next[0] = -1;
    while (i < s.length() - 1) {
        if (j == -1 || s[i] == s[j])
            next[++i] = ++j;
        else
            j = next[j];
    }
}

// 模式串的next数组的优化，nextval数组
void get_nextval(const string &s, int nextval[]) {
    int i = 0, j = -1;
    nextval[0] = -1;
    while (i < s.length() - 1) {
        if (j == -1 || s[i] == s[j]) {
            ++i;
            ++j;
            if (s[i] != s[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        } else
            j = nextval[j];
    }
}

// 显示next数组
void display_next(const int next[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << next[i] << " ";
        if (i == length - 1)
            cout << endl;
    }
}

int main() {
    // 主串
    string main_string = "wonderland";
    // 模式串
    string pattern_string = "lan";

    int next[25] = {0};
    get_next(pattern_string, next);
    cout << "next: ";
    display_next(next, (int) pattern_string.length());

    int nextval[25] = {0};
    get_nextval(pattern_string, nextval);
    cout << "nextval: ";
    display_next(nextval, (int) pattern_string.length());

    cout << pattern_string_match(main_string, pattern_string) << endl;
    cout << kmp(main_string, pattern_string, next) << endl;
    cout << kmp(main_string, pattern_string, nextval) << endl;
}
```

```c++
next: -1 0 0
nextval: -1 0 0
6
6
6
```

#### 树



#### 图



### 排序

#### 冒泡

```c++
#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void bubble_sort(vector<int> &b) {
    for (int i = 0; i < b.size(); ++i) {
        bool flag = false; // 标记一次循环是否执行了交换

        // 从后向前冒泡，每次循环结束，本次循环中最小的元素会冒到最前
        for (int j = (int) b.size() - 1; j > i; --j) {
            if (b[j] < b[j - 1]) { // 不加等号，保证排序的稳定性
                swap(b[j], b[j - 1]);
                flag = true;
            }
        }
        if (!flag) // 本次遍历没有发生交换，说明表已经有序，算法可以提前结束
            return;
    }

    for (int i = (int) b.size(); i >= 0; --i) {
        bool flag = false; // 标记一次循环是否执行了交换

        // 从前向后冒泡，每次循环结束，本次循环中最大的元素会冒到最后
        for (int j = 0; j < i; ++j) {
            if (b[j] > b[j + 1]) {
                swap(b[j], b[j + 1]);
                flag = true;
            }
        }
        if (!flag) // 本次遍历没有发生交换，说明表已经有序
            return;
    }

}

void display(vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        if (i == a.size() - 1)
            cout << a[i] << endl;
        else
            cout << a[i] << " ";
    }
}

int main() {
    vector<int> a = {12, 64, 31, 44, 58, 27, 35, 54, 60};
    bubble_sort(a);
    display(a);
}
```

#### 选择

```c++
#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void selection_sort(vector<int> &b) {
    for (int i = 0; i < b.size(); ++i) {
        int min = i; // 记录最小元素索引
        for (int j = i + 1; j < b.size(); ++j) {
            if (b[j] < b[min])
                min = j;
        }
        if (min != i)
            swap(b[min], b[i]);
    }
}

void display(vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        if (i == a.size() - 1)
            cout << a[i] << endl;
        else
            cout << a[i] << " ";
    }
}

int main() {
    vector<int> a = {12, 64, 31, 44, 58, 27, 35, 54, 60};
    selection_sort(a);
    display(a);
}
```

插入

```c++
#include <iostream>
#include <vector>

using namespace std;

// 直接插入排序，顺序查找找到当前处理元素插入的位置
void insert_sort(vector<int> &b) {
    // b[0]看作是有序，从b[1] 开始进行插入排序
    for (int i = 1; i < b.size(); ++i) {
        if (b[i] < b[i - 1]) {
            int temp;
            temp = b[i];
            int j;
            for (j = i - 1; j >= 0 && b[j] > temp; --j) {
                b[j + 1] = b[j];
            }
            b[j + 1] = temp;
        }
    }
}

int binary_sort(vector<int> &d, int key, int end) {
    int low = 0;
    int high = end - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2; // 向下取整
        if (d[mid] >= key) // 等号保证折半插入排序的稳定性
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

// 折半插入排序，折半查找找到当前处理元素插入的位置，因为前面的元素一定有序
void binary_insert_sort(vector<int> &c) {
    for (int i = 1; i < c.size(); ++i) {
        if (c[i] < c[i - 1]) {
            int temp;
            temp = c[i];
            int j;
            j = binary_sort(c, temp, i);
            for (int k = i; k >= j; --k) {
                c[k] = c[k - 1];
            }
            c[j] = temp;
        }
    }
}

void display(vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        if (i == a.size() - 1)
            cout << a[i] << endl;
        else
            cout << a[i] << " ";
    }
}

int main() {
    vector<int> a = {12, 64, 31, 44, 58, 27, 35, 54, 60};
    cout << "previous: ";
    display(a);

    insert_sort(a);
    cout << "insert_sort: ";
    display(a);

    binary_insert_sort(a);
    cout << "binary_insert_sort: ";
    display(a);
}
```

#### 快速

```c++
#include <iostream>
#include <vector>

using namespace std;

//一次划分
int partition(vector<int> &c, int p, int q) {
    int i = p, j = q;
    int pivot = c[i];
    while (i < j) {
        while (i < j && c[j] >= pivot)
            j--;
        c[i] = c[j];
        while (i < j && c[i] <= pivot)
            i++;
        c[j] = c[i];
    }
    c[i] = pivot;
    return i;
}

//快速排序
void quick_sort(vector<int> &b, int p, int q) {
    int i;
    if (p < q) {
        i = partition(b, p, q);
        quick_sort(b, p, i - 1);
        quick_sort(b, i + 1, q);
    }
}

void display(vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        if (i == a.size() - 1)
            cout << a[i] << endl;
        else
            cout << a[i] << " ";
    }
}

int main() {
    vector<int> a = {12, 64, 31, 44, 58, 27, 35, 54, 60};
    quick_sort(a, 0, (int)a.size() - 1);
    display(a);
}
```

#### 希尔

```c++
#include <iostream>
#include <vector>

using namespace std;

void shell_sort(vector<int> &b) {
    int d = (int) b.size() / 2;
    while ( d >= 1) {
        for (int i = 0; i < d; ++i) { // 对每个划分的子表分别排序
            int j; // 因为默认每个划分的第一个元素为有序，所以，j指向每个划分的第二个元素
            for (j = d + i; j < b.size(); j = j + d) {
                if (b[j] < b[j - d]) {
                    int temp = b[j];
                    int k;
                    for (k = j - d; k >= 0 && b[k] > temp; k = k - d) {
                        b[k + d] = b[k];
                    }
                    b[k + d] = temp;
                }
            }
        }
        d = d / 2;
    }
}

void display(vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        if (i == a.size() - 1)
            cout << a[i] << endl;
        else
            cout << a[i] << " ";
    }
}

int main() {
    vector<int> a = {12, 64, 31, 44, 58, 27, 35, 54, 60};
    shell_sort(a);
    display(a);
}
```

#### 归并

```c++
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &c, int low, int mid, int high) {
    vector<int> sup(c.size()); // 注意辅助数组要分配初始容器大小，否则会有索引越界异常

    for (int i = low; i <= high ; ++i)
        sup[i] = c[i];
    int i; // 记录第一个有序序列的第一个元素索引
    int j; // 记录第二个有序序列的第一个元素索引
    int k;
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high ; ++k) {
        if(sup[i] <= sup[j])
            c[k] = sup[i++]; // 将较小值复制到c中
        else
            c[k] = sup[j++];
    }
    while (i <= mid)
        c[k++] = sup[i++];
    while (j <= high)
        c[k++] = sup[j++];
}

//归并排序
void merge_sort(vector<int> &b, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(b, low, mid);
        merge_sort(b, mid + 1, high);
        merge(b, low, mid, high);
    }
}

void display(vector<int> a) {
    for (int i = 0; i < a.size(); ++i) {
        if (i == a.size() - 1)
            cout << a[i] << endl;
        else
            cout << a[i] << " ";
    }
}

int main() {
    vector<int> a = {12, 64, 31, 44, 58, 27, 35, 54, 60};
    merge_sort(a, 0, (int) a.size() - 1);
    display(a);
}
```

#### 堆

```c++
#include <iostream>
#include <vector>

// 大根堆：满足任意的根结点都大于左右孩子结点
using namespace std;

void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void adjust(vector<int> &c, int k, int len) {
    int temp = c[k]; // 暂存子树的根结点
    for (int i = 2 * k; i <= len; i *= 2) {
        if (i < len && c[i] < c[i + 1])
            i++;
        if (temp >= c[i])
            break;
        else {
            c[k] = c[i];
            k = i;
        }
    }
    c[k] = temp;
}

// 建立大根堆
// 检查所有非终端结点（i <= n/2向下取整）是否满足大根堆要求
void create_max_heap(vector<int> &d) {
    // 从下往上调整，依次是 44，31，64，12
    for (int i = ((int) d.size() - 1) / 2; i >= 1; --i) {
        adjust(d, i, (int) d.size() - 1);
    }
}

void display(vector<int> a) {
    for (int i = 1; i < a.size(); ++i) {
        if (i == a.size() - 1)
            cout << a[i] << endl;
        else
            cout << a[i] << " ";
    }
}

// 堆排序
void selection_sort(vector<int> &b) {
    create_max_heap(b); // 创建大根堆
    for (int i = (int) b.size() - 1; i > 1; --i) {
        // 每一次把最大的元素放到有序队列中
        swap(b[i], b[1]);
        // 调整使剩下的元素满足大根堆
        adjust(b, 1, i - 1);
    }
}

int main() {
    // 数组下标从一开始
    vector<int> a = {-1, 12, 64, 31, 44, 58, 27, 35, 54, 60};
    selection_sort(a);
    display(a);
}
```



### 查找





### 数据结构应用

#### 栈求表达式

```c++
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <stdexcept>

using namespace std;

// 除数为零异常类
class zero_divisor: public exception {
public:
    const char* what(void) const throw() {
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
    int m = 0, n = 0, PriM[4][5] = {   // 运算符优先级矩阵
        {1, 0, 0, -1, -1},
        {1, 0, 0, -1, -1},
        {1, 1, 1,  0,  0},
        {1, 1, 1,  0,  0},
    };
    while (s1[m] != a)  // 找到在s1中和当前扫描的运算符相等的运算符的序号，即为当前扫描的运算符在矩阵中的行号
        m++;
    while (s2[n] != b)  // 找到在s2中和栈顶运算符相等的运算符的序号，即为栈顶运算符在矩阵中的列号
        n++;
    return PriM[m][n];  // 输出行列号在矩阵中所对应的数值，即为当前扫描的运算符和栈顶运算符优先级的比较结果
}

// 判断是否输入的是合法的表达式
bool judge_exp_legality(string exp) {
    string::iterator it;
    int flag = 1;
    for (it = exp.begin(); it != exp.end(); ++it) {
        if (*it != '(' && *it != ')' && *it != '+' && *it != '-' && *it != '*' && *it != '/' && *it < '0' || *it > '9') {
            flag = 0;
            break;
        }
    }
    return flag == 1;
}

void calculate(stack<char>& opr, stack<int>& opd) throw(zero_divisor) {
    char ch; // 记录运算符栈出栈的运算符
    ch = opr.top();
    opr.pop();

    int a, b; // a记录运算符前面的操作数，b记录运算符后面的操作数
    b = opd.top();
    opd.pop();
    a = opd.top();
    opd.pop();

    int c = 0; // 记录每次出栈的两个操作数的运算结果
    switch (ch) {
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
        if (b == 0) {
            throw zero_divisor();
        }
        else {
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
int evaluate_infix_expression(string exp) throw(zero_divisor) {
    stack<char> opr; // 运算符栈
    stack<int> opd; // 操作数栈

    stack<char> temp; // 将中缀表达式中的数字字符转换为整数
    string::iterator it_exp;
    for (it_exp = exp.begin(); it_exp != exp.end(); ++it_exp) {

        if (*it_exp >= '0' && *it_exp <= '9') {
            while (*it_exp >= '0' && *it_exp <= '9') {
                temp.push(*it_exp);
                it_exp++;
                if (it_exp == exp.end())
                    break;
            }
            it_exp--; // 防止it_exp向后移动两位，直接跳过了一个字符

            int num = 0; // num 存放计算后多位操作数的整数形式
            int size = temp.size(); // 若直接将 temp.size()写在for循环中，则每执行一次i会增加，temp.size()会减少
            for (int i = 0; i < size; ++i) {
                num = num + (temp.top() - '0') * pow(10, i);
                temp.pop();
                if (temp.empty())
                    opd.push(num);
            }
        }
        else {
            if (opr.empty())
                opr.push(*it_exp);
            else {
                // 左括号，直接进栈
                if (*it_exp == '(')
                    opr.push(*it_exp);

                // 右括号，直到左括号前的运算符出栈，最后左括号出栈
                else if (*it_exp == ')') {
                    while (opr.top() != '(') {
                        calculate(opr, opd);
                    }
                    opr.pop(); // 左括号出栈
                }
                // 加减乘除运算符
                else {
                    if (precede(*it_exp, opr.top()) == 1) // 当前扫描的运算符优先级高
                        opr.push(*it_exp);

                    else { // 当前扫描的运算符比栈顶运算符优先级低或者相同
                        calculate(opr, opd);
                        opr.push(*it_exp); // 栈顶优先级高的运算符出栈后，优先级低的进栈
                    }
                }
            }
        }

    }
    // 所有表达式扫描完后 opr栈中所有剩余的运算符出栈
    while (!opr.empty()) {
        calculate(opr, opd);
    }

    return opd.top();
}

int main()
{
    string exp;
    cout << "Please enter a positive integer expression:" << endl;
    cin >> exp;
    if (judge_exp_legality(exp) == true) {
        try
        {
            cout << evaluate_infix_expression(exp) << endl;
        }
        catch (const exception& ex)
        {
            cout << ex.what() << endl;
        }   
    }
    else {
        cout << "Please enter a valid expression:" << endl;
        cin >> exp;
    }
    return 0;
}
```



#### Topk
