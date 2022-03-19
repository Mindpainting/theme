#include <iostream>
#include <stack>
#include <string>
using namespace std;

// parentheses（括号），bracket（括号）

bool match_bracket(string str) {
    stack<char> bracket;

    for(int i = 0; i < str.length(); ++i) {

        // 扫描到左括号进栈
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            bracket.push(str[i]);

        } else { // 扫描到右括号

            if(bracket.empty()) // 栈空，匹配失败
                return false;

            // 栈顶括号不是左括号，匹配失败
            if(str[i] == ')' && bracket.top() != '(')
                return false;

            if(str[i] == ']' && bracket.top() != '[')
                return false;

            if(str[i] == '}' && bracket.top() != '{')
                return false;

            // 一对括号匹配成功，栈顶元素出栈
            bracket.pop();
        }
    }
    // 所有字符扫描完毕之后，栈空，则匹配成空，反之，匹配失败
    return bracket.empty();
}

int main() {
    // 不匹配情况：左括号单剩，右括号单剩，左右括号不匹配

    // 字符串中有剩余的右括号，栈空，匹配失败
    string str1 = "{()[]})";

    // 栈顶括号与当前扫描到的括号不匹配，匹配失败
    string str2 = "{(}[]}";

    // 字符扫描完后栈不为空，栈中有剩余的左括号，匹配失败
    string str3 = "({()[]}";

    // 匹配成功
    string str4 = "{()[]}";

    cout << match_bracket(str1) << endl;
    cout << match_bracket(str2) << endl;
    cout << match_bracket(str3) << endl;
    cout << match_bracket(str4) << endl;
    return 0;
}
