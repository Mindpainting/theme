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