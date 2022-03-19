#include <iostream>
#include <queue>

#define MAXV 50
using namespace std;

/* 邻接矩阵（无向图） */

typedef struct {
    int adjmat[MAXV][MAXV]; // 图中边的信息（顶点之间的邻接关系）
    int vexs[MAXV]; // 顶点值
    int vertex_num; // 顶点数
    int edge_num; // 边数
} MatGraph;

void create_matrix_graph(MatGraph *&matrix_graph, int v, int e, int adjmat[][5]) {
    matrix_graph->vertex_num = v;
    matrix_graph->edge_num = e;
    for (int i = 0; i < v; ++i) {
        matrix_graph->vexs[i] = i;
    }
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (adjmat[i][j] == 1) {
                matrix_graph->adjmat[i][j] = adjmat[i][j];
                matrix_graph->adjmat[j][i] = adjmat[i][j];
            }
        }
    }
}

// 返回与顶点a相邻的第一个顶点
int first_neighbor(MatGraph *&matrix_graph, int v) {
    for (int i = 0; i < matrix_graph->vertex_num; ++i) {
        if (matrix_graph->adjmat[v][i] == 1) {
            return i;
        }
    }
    return -1;
}

// 返回与顶点a相邻的下一个顶点
int next_neighbor(MatGraph *&matrix_graph, int v, int v_) {
    for (int i = v_ + 1; i < matrix_graph->vertex_num; ++i) {
        if (matrix_graph->adjmat[v][i] == 1) {
            return i;
        }
    }
    return -1;
}

// 广度优先遍历（辅助队列）
bool visited1[MAXV]; // 访问标记数组
void BFS(MatGraph *&matrix_graph, int v) {
    cout << v << " ";
    visited1[v] = true;
    queue<int> queue;
    queue.push(v);
    while (!queue.empty()) {
        queue.pop();
        for (int w = first_neighbor(matrix_graph, v); w != -1; w = next_neighbor(matrix_graph, v, w)) {
            if (!visited1[w]) {
                cout << w << " ";
                visited1[w] = true;
                queue.push(w);
            }
        }
    }
}

void BFS_(MatGraph *&matrix_graph) {
    for (int i = 0; i < matrix_graph->vertex_num; ++i) {
        visited1[i] = false;
    }
    for (int i = 0; i < matrix_graph->vertex_num; ++i) {
        if (!visited1[i])
            BFS(matrix_graph, i); // 对每个连通分量调用一次BFS
    }
}

// 深度优先遍历（函数调用栈）
bool visited2[MAXV]; // 访问标记数组
void DFS(MatGraph *&matrix_graph, int v) {
    cout << v << " ";
    visited2[v] = true;
    for (int w = first_neighbor(matrix_graph, v); w != -1; w = next_neighbor(matrix_graph, v, w)) {
        if (!visited2[w])
            DFS(matrix_graph, w);
    }
}

void DFS_(MatGraph *&matrix_graph) {
    for (int i = 0; i < matrix_graph->vertex_num; ++i) {
        visited2[i] = false;
    }
    for (int i = 0; i < matrix_graph->vertex_num; ++i) {
        if (!visited2[i])
            DFS(matrix_graph, i); // 对每个连通分量调用一次BFS
    }
}

int main() {
    int adjmat[5][5] = {{0, 1, 0, 1, 1},
                        {1, 0, 1, 1, 0},
                        {0, 1, 0, 1, 1},
                        {1, 1, 1, 0, 1},
                        {1, 0, 1, 1, 0}};
    MatGraph *matrix_graph;
    create_matrix_graph(matrix_graph, 5, 5, adjmat);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matrix_graph->adjmat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "BFS: ";
    BFS_(matrix_graph);
    cout << endl;
    cout << "DFS: ";
    DFS_(matrix_graph);
    return 0;
}