#include <iostream>
#include <vector>

using namespace std;

/* 二分查找 */
int binary_search(vector<int> b, int key) {
    int low = 0;
    int high = (int) b.size() - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2; // 向下取整
        if (key == b[mid])
            return mid;
        else if (key > b[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> a = {7, 10, 13, 16, 19, 29, 32, 33, 37, 41, 43};
    int result;
    result = binary_search(a, 41);
    if (result != -1)
        cout << "index: " << result << endl;
    else
        cout << "search failure" << endl;
}