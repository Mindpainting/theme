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