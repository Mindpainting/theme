#include <iostream>
using namespace std;

typedef struct BinarySortNode {
    int key;
    struct BinarySortNode *lchild, *rchild;
} BinarySortTree;

// 插入结点，每次插入的一定是叶子结点（递归实现）
int insert_recursive(BinarySortTree* &bstree, int key) {
    if (bstree == nullptr) {
        bstree = (BinarySortTree*) malloc(sizeof(BinarySortTree));
        bstree->key = key;
        bstree->lchild = nullptr;
        bstree->rchild = nullptr;
        return 1;
    } else if (bstree->key == key) {
        return 0;
    } else if (key < bstree->key) {
        return insert_recursive(bstree->lchild, key);
    } else {
        return insert_recursive(bstree->rchild, key);
    }
}

/*bool insert_non_recursive(BinarySortTree* &bstree, int key) {
    BinarySortTree* p = bstree;
    if (p != nullptr && p->key == key)
        return false;
    if (p != nullptr) {
        while (p != nullptr) {
            if (p->lchild != nullptr && key < p->key)
                p = p->lchild;
            if (p->rchild != nullptr && key > p->key)
                p = p->rchild;
        }
    }
    bstree = (BinarySortTree*) malloc(sizeof(BinarySortTree));
    bstree->key = key;
    bstree->lchild = nullptr;
    bstree->rchild = nullptr;
    return true;
}*/

// 构造一颗二叉排序树
void create_binary_sort_tree(BinarySortTree* &bstree, int keys[], int n) {
    for (int i = 0; i < n; ++i) {
        // insert_non_recursive(bstree, keys[i]);
        insert_recursive(bstree, keys[i]);
    }
}

// 先序遍历二叉排序树，输出由小到大排序的结果
void inorder(BinarySortTree* bstree) {
    if (bstree != nullptr) {
        inorder(bstree->lchild);
        cout << bstree->key << " ";
        inorder(bstree->rchild);
    }
}

// 查找指定结点，返回指定结点指针
BinarySortTree* search(BinarySortTree* bstree, int key) {
    while (bstree != nullptr && bstree->key != key) {
        if (key < bstree->key)
            bstree = bstree->lchild;
        else
            bstree = bstree->rchild;
    }
    return bstree;
}

int main() {
    int keys[] = {50, 25, 74, 12, 36, 56, 14, 22, 89, 64};
    int n;
    n = sizeof(keys) / 4; // 数组的长度
    BinarySortTree* bstree = nullptr;
    create_binary_sort_tree(bstree, keys, n);
    inorder(bstree);
    cout << endl;

    BinarySortTree* search_results = search(bstree, 12);
    if (search_results != nullptr)
        cout << "Search results: " << search_results->key << endl;
    else
        cout << "The query value does not exist!" << endl;

    return 0;
}