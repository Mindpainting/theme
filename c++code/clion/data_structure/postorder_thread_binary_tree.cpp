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

// 后序遍历的过程中，边遍历，边线索化
void postorder_thread(ThreadBinaryTree* const root) {
    ThreadBinaryTree* p = root;
    if (p != nullptr) {
        postorder_thread(p->lchild); // 左子树线索化
        postorder_thread(p->rchild); // 右子树线索化

        // 左子树为空，建立前驱线索
        if (p->lchild == nullptr) {
            p->lchild = pre;
            p->ltag = 1;
        } // 由于建立二叉树时，ltag和rtag默认为0，即默认指向孩子结点，所以，左子树不为空时不需要再设置ltag和rtag

        // 右子树为空，建立后继线索
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
    }
}

// 创建后序线索二叉树
void postorder_thread_binary_tree(ThreadBinaryTree* root) {
    pre = nullptr;
    if (root != nullptr) {
        postorder_thread(root);
        if (pre->rchild == nullptr) // 处理最后一个结点
            pre->rtag = 1;
    }
}

// 在后序线索二叉树中找到结点p的前驱结点
ThreadBinaryTree* pre_node(ThreadBinaryTree* p) {
    if (p->ltag == 1)
        return p->lchild;
    else {
        // 若只用p != nullptr来判断，则 B 和 E 形成死循环
        if (p->rtag == 0) // 判断p是否有真正的右孩子，防止死循环
            return p->rchild;
        else
            return p->lchild;
    }
}

// 在后序线索二叉树中找到结点p的后继结点
ThreadBinaryTree* next_node(ThreadBinaryTree* p) {
    if (p->rtag == 1)
        return p->rchild;
    // 如果p->rtag == 0，在基于只有指向孩子结点指针的线索二叉树中找不到p的后继结点
    return nullptr;
}

// 对后序线索二叉树逆序遍历
void traversal_reverse(ThreadBinaryTree* root) {
    for (ThreadBinaryTree* p = root; p != nullptr; p = pre_node(p)) {
        cout << p->value << " ";
    }
    cout << endl;
}

int main() {
    ThreadBinaryTree* root = nullptr; // 非线索化二叉树的根
    string str = "A(B(D(,G)),C(E,F))";
    create_binary_tree(root, str);

    postorder_thread_binary_tree(root);

    traversal_reverse(root);

}
