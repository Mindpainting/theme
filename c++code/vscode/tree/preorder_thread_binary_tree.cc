#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
 * ltag = 0,表示lchild指向左孩子结点
 * ltag = 1,表示lchild指向前驱结点
 * rtag = 0,表示rchild指向右孩子结点
 * rtag = 1,表示rchild指向后继结点
*/
typedef struct ThreadBinaryNode{
    char value;
    int ltag; // 线索标记
    int rtag; // 线索标记
    struct ThreadBinaryNode *lchild, *rchild;
} ThreadBinaryTree;

ThreadBinaryTree* pre; // 指向当前结点的前驱结点

// 创建二叉树
void create_binary_tree(ThreadBinaryTree* &root, const string& str) {
    stack<ThreadBinaryTree*> node_stack;
    ThreadBinaryTree* p; // 指向创建的新结点

    int i = 0, j;
    while (i != str.length()) {
        switch (str[i]) {
            case '(':
                node_stack.push(p);
                j = 1;
                break;
            case ')':
                node_stack.pop();
                break;
            case ',':
                j = 2;
                break;
            default:
                p = (ThreadBinaryTree*) malloc(sizeof(ThreadBinaryTree));
                p->value = str[i];
                p->lchild = p->rchild = nullptr;
                p->ltag = p->rtag = 0;
                if (root == nullptr)
                    root = p;
                else {
                    switch (j) {
                        case 1:
                            node_stack.top()->lchild = p;
                            break;
                        case 2:
                            node_stack.top()->rchild = p;
                            break;
                        default:
                            break;
                    }
                }
        }
        ++i;
    }
}

// 先序遍历的过程中，边遍历，边线索化
void preorder_thread(ThreadBinaryTree* const root) {
    ThreadBinaryTree* p = root;
    if (p != nullptr) {
        // p结点左子树为空，建立p结点的前驱线索
        if (p->lchild == nullptr) {
            p->lchild = pre;
            p->ltag = 1;
        } // 由于建立二叉树时，ltag和rtag默认为0，即默认指向孩子结点，所以，左子树不为空时不需要再设置ltag和rtag

        // pre结点右子树为空，建立pre结点的后继线索
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;

        // 判断p是否有真正的左孩子，防止死循环
        if (p->ltag == 0)
            preorder_thread(p->lchild); // 左子树线索化
        if (p->rtag == 0)
            preorder_thread(p->rchild); // 右子树线索化
    }
}

// 创建先序线索二叉树
void preorder_thread_binary_tree(ThreadBinaryTree* root) {
    pre = nullptr;
    if (root != nullptr) {
        preorder_thread(root);
        if (pre->rchild == nullptr) // 处理最后一个结点
            pre->rtag = 1;
    }
}

// 在先序线索二叉树中找到结点p的前驱结点
ThreadBinaryTree* pre_node(ThreadBinaryTree* p) {
    if (p->ltag == 1)
        return p->lchild;
    // 如果p->ltag == 0，在基于只有指向孩子结点指针的线索二叉树中找不到p的前驱结点
    return nullptr;
}

// 在先序线索二叉树中找到结点p的后继结点
ThreadBinaryTree* next_node(ThreadBinaryTree* p) {
    if (p->rtag == 1)
        return p->rchild;
    else {
        // 若只用p->lchild != nullptr来判断，则 B 和 D 形成死循环
        if (p->ltag == 0) // 判断p是否有真正的左孩子，防止死循环
            return p->lchild;
        else
            return p->rchild;
    }
}

// 对先序线索二叉树遍历
void traversal(ThreadBinaryTree* root) {
    for (ThreadBinaryTree* p = root; p != nullptr; p = next_node(p)) {
        cout << p->value << " ";
    }
    cout << endl;
}

int main() {
    ThreadBinaryTree* root = nullptr; // 非线索化二叉树的根
    string str = "A(B(D(,G)),C(E,F))";
    create_binary_tree(root, str);
    preorder_thread_binary_tree(root);
    traversal(root);
}
