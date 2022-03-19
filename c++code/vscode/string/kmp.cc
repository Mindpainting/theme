#include <iostream>
#include <string>
using namespace std;

// string容器的length()函数返回的是unsigned int类型
int pattern_string_match(const string& s1, const string& s2) {
    int i = 0, j = 0, k = 0;
    int length_s1 = (int)s1.length();
    int length_s2 = (int)s2.length();
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

int kmp (const string& s1, const string& s2, const int next[]) {
    int i = 0, j = 0;
    int length_s1 = (int)s1.length();
    int length_s2 = (int)s2.length();
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
void get_next(const string& s, int next[]) {
    int i = 0, j = -1;
    next[0] = -1;
    while (i < s.length() - 1) {
        if (j == -1 || s[i] == s[j])
            next[++i] = ++j;
        else
            j = next[j];
    }
}

// 模式串的next数组的优化，nextval数组
void get_nextval(const string& s, int nextval[]) {
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
        }
        else
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
    string main_string = "aaaabaaabbbbbbccc";
    // 模式串
    string pattern_string = "abbbb";

    int next[25] = {0};
    get_next(pattern_string, next);
    cout << "next: ";
    display_next(next, (int)pattern_string.length());

    int nextval[25] = {0};
    get_nextval(pattern_string, nextval);
    cout << "nextval: ";
    display_next(nextval, (int)pattern_string.length());

    cout << pattern_string_match(main_string, pattern_string) << endl;
    cout << kmp(main_string, pattern_string, next) << endl;
    cout << kmp(main_string, pattern_string, nextval) << endl;
}
