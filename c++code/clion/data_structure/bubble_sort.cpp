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