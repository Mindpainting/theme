#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

typedef struct BinaryNode {
    char value;
    struct BinaryNode *lchild, *rchild;
} BinaryTree;

// 创建二叉树
void create_binary_tree(BinaryTree* &root, const string& str) {
    stack<BinaryTree*> node_stack;
    BinaryTree* p; // 指向创建的新结点

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
                p = (BinaryTree*) malloc(sizeof(BinaryTree));
                p->value = str[i];
                p->lchild = p->rchild = nullptr;
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

// 求二叉树的高度
int get_height(BinaryTree* root) {
    int lchild_height;
    int rchild_height;
    if (root == nullptr)
        return 0;
    else {
        lchild_height = get_height(root->lchild);
        rchild_height = get_height(root->rchild);
        return (lchild_height > rchild_height) ? (lchild_height + 1) : (rchild_height + 1);
    }
}

// 查找结点，找到返回结点指针；否则，返回空
BinaryTree* find_node(BinaryTree* root, char x) {
    BinaryTree* p;
    if (root == nullptr)
        return nullptr;
    else if (root->value == x)
        return root;
    else {
        p = find_node(root->lchild, x);
        if (p != nullptr)
            return p;
        else
            return find_node(root->rchild, x);
    }
}

// 显示二叉树
void display(BinaryTree* root) {
    if (root != nullptr) {
        cout << root->value;
        if (root->lchild != nullptr || root->rchild != nullptr) {
            cout << "(";
            display(root->lchild);
            if (root->rchild != nullptr)
                cout << ",";
            display(root->rchild);
            cout << ")";
        }
    }
}

// 销毁二叉树
void destory(BinaryTree* root) {
    if (root != nullptr) {
        destory(root->lchild);
        destory(root->rchild);
        free(root);
    }
}

// 先序遍历（递归），第一次路过时访问结点
void preorder_recursive(BinaryTree* const root) {
    if (root != nullptr) {
        cout << root->value << " ";
        preorder_recursive(root->lchild);
        preorder_recursive(root->rchild);
    }
}

// 先序遍历（非递归）
void preorder_non_recursive(BinaryTree* const root) {
    stack<BinaryTree*> stack;

    if (root != nullptr) {
        stack.push(root);
        while (!stack.empty()) {
            BinaryTree* top = stack.top();
            stack.pop();
            cout << top->value << " ";
            // 遍历结果是右孩子结点在后，所以右孩子结点先进栈
            if (top->rchild != nullptr)
                stack.push(top->rchild);
            if (top->lchild != nullptr)
                stack.push(top->lchild);
        }
    }
}

// 中序遍历（递归），第二次路过时访问结点
void inorder_recursive(BinaryTree* const root) {
    if (root != nullptr) {
        inorder_recursive(root->lchild);
        cout << root->value << " ";
        inorder_recursive(root->rchild);
    }
}

// 中序遍历（非递归）
void inorder_non_recursive(BinaryTree* const root) {
    BinaryTree* p = root;
    stack<BinaryTree*> stack;
    while (!stack.empty() || p != nullptr) {
        // 扫描 p结点的所有左下结点并进栈
        while (p != nullptr) {
            stack.push(p);
            p = p->lchild;
        }
        if (!stack.empty()) {
            p = stack.top();
            stack.pop();
            cout << p->value << " ";
            // 转向处理右子树
            p = p->rchild;
        }
    }
}

// 后序遍历（递归），第三次路过时访问结点
void postorder_recursive(BinaryTree* const root) {
    if (root != nullptr) {
        postorder_recursive(root->lchild);
        postorder_recursive(root->rchild);
        cout << root->value << " ";
    }
}

// 后序遍历（非递归）
void postorder_non_recursive(BinaryTree* const root) {
    bool flag; // 为真表示正在处理栈顶结点
    BinaryTree *p = root;
    BinaryTree *r;
    stack<BinaryTree *> stack;
    do {
        // 扫描p结点的所有左下结点并进栈
        while (p != nullptr) {
            stack.push(p);
            p = p->lchild;
        }
        r = nullptr; // 指向刚访问的结点，初始时为空
        flag = true;
        while (!stack.empty() && flag) {
            p = stack.top();
            // 若栈顶结点的右孩子为空或者为刚刚访问过的结点
            if (p->rchild == r) {
                cout << p->value << " ";
                stack.pop();
                r = p; // r指向刚访问过的结点
            } else {
                p = p->rchild;
                flag = false;
            }
        }
    } while (!stack.empty());
}

// 层次遍历
void levelorder(BinaryTree* const root) {
    queue<BinaryTree*> queue;
    queue.push(root);

    while (!queue.empty()) {
        BinaryTree* front = queue.front();
        cout << front->value << " ";
        queue.pop();
        if (front->lchild != nullptr)
            queue.push(front->lchild);
        if (front->rchild != nullptr)
            queue.push(front->rchild);
    }
}

int main() {
    BinaryTree* root = nullptr;
    string str = "A(B(D(,G)),C(E,F))";
    create_binary_tree(root, str);
    cout << "height: " << get_height(root) << endl;

    BinaryTree* find_result = find_node(root, 'E');
    cout << "find_result: " << find_result->value << endl;

    cout << "display_binary_tree: ";
    display(root);
    cout << endl;

    cout << "preorder_recursive: ";
    preorder_recursive(root);
    cout << endl;

    cout << "preorder_non_recursive: ";
    preorder_non_recursive(root);
    cout << endl;

    cout << "inorder_recursive: ";
    inorder_recursive(root);
    cout << endl;

    cout << "inorder_non_recursive: ";
    inorder_non_recursive(root);
    cout << endl;

    cout << "postorder_recursive: ";
    postorder_recursive(root);
    cout << endl;

    cout << "postorder_non_recursive: ";
    postorder_non_recursive(root);
    cout << endl;

    cout << "levelorder: ";
    levelorder(root);
    cout << endl;

    return 0;
}
