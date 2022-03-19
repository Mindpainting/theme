#include <iostream>

using namespace std;

/* 邻接表（无向图） */

typedef struct ENode { // 边表结点
    int adjvex; // 该弧所指向的顶点的位置
    struct ENode *next; // 指向下一条弧的指针
} ENode;

typedef struct VNode { // 顶点表结点
    int data; // 顶点信息
    ENode *first; // 指向第一条依附该顶点的弧的指针
} VNode;

typedef struct {
    VNode adjlist[50]; // 邻接表的头结点数组
    int vertex_num; // 图中的顶点数
    int edge_num; // 图中的边数
} AdjGraph; // 图邻接表类型

void create_adjacent_list(AdjGraph *&adjacent_graph, int adjmat[][5], int v, int e) {
    adjacent_graph->vertex_num = v;
    adjacent_graph->edge_num = e;

    for (int i = 0; i < 5; ++i) {
        adjacent_graph->adjlist[i].data = i;
        for (int j = v - 1; j >= 0; --j) {
            if (adjmat[i][j] == 1) {
                ENode *p;
                p = (ENode *) (malloc(sizeof(ENode)));
                p->adjvex = j;
                p->next = adjacent_graph->adjlist[i].first; // 采用头插法，尾插法不能实现，尾为空指针
                adjacent_graph->adjlist[i].first = p;
            }
        }
    }

}

int main() {
    int adjmat[5][5] = {{0, 1, 0, 1, 1},
                        {1, 0, 1, 1, 0},
                        {0, 1, 0, 1, 1},
                        {1, 1, 1, 0, 1},
                        {1, 0, 1, 1, 0}};
    AdjGraph *adjacent_graph;
    create_adjacent_list(adjacent_graph, adjmat, 5, 5);

    for (int i = 0; i < 5; ++i) {
        ENode *p = adjacent_graph->adjlist[i].first;
        cout << adjacent_graph->adjlist[i].data << " ";
        while (p != nullptr) {
            cout << p->adjvex << " ";
            p = p->next;
        }
        cout << endl;
    }
}