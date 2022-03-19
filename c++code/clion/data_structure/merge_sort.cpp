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