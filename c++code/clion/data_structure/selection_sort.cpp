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