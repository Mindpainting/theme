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