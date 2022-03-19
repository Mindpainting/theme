#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int max_value;
    int low;
    int high;
} Index;

// 索引表顺序查找
// 索引表折半查找

int block_search(vector<int> b, int key) {

}

int main() {
    vector<int> a = {5, 7, 12, 18, 19, 24, 25, 33, 41, 45, 52, 55, 56};
    int result;
    result = block_search(a, 33);
}