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