// traverse graph
#include <iostream>
#include "my_queue.hpp"
using std::cout;
using std::endl;
#define MAXSIZE 100

typedef struct ArcNode {
    int adjacency_index;
    struct ArcNode* next;
} ArcNode;

typedef struct {
    char data;
    ArcNode* first;
} VertexNode;

typedef struct {
    VertexNode adjacency_list[MAXSIZE];
    int vertex_num;
    int arc_num;
} AdjacencyListGraph;

void visit(const AdjacencyListGraph& G, const int& v) {
    cout << G.adjacency_list[v].data << endl;
}

// DFS : depth-first traversal use recursion
void DFS(const AdjacencyListGraph& G, const int& v, \
            bool visit_array[MAXSIZE] = { 0 }) {
    visit_array[v] = true;
    // visit(G, v);
    [&]() {
        cout << G.adjacency_list[v].data << endl;
    } ();
    ArcNode* p = G.adjacency_list[v].first;
    while (p != nullptr) {
        if (visit_array[p->adjacency_index] == false) {
            DFS(G, p->adjacency_index, visit_array);
        }
        p = p->next;
    }
}

// BFS : breadth-first traversal
void BFS(const AdjacencyListGraph& G, const int& v, \
            bool visit_array[MAXSIZE] = { 0 }) {
    Queue<int> assist_queue;
    ArcNode* p = nullptr;
    int q = 0;
    // visit(G, v);
    [&]() {
        cout << G.adjacency_list[v].data << endl;
    } ();
    visit_array[v] = true;
    assist_queue.enter(v);
    while (!assist_queue.is_empty()) {
        q = assist_queue.exit();
        p = G.adjacency_list[q].first;
        while (p != nullptr) {
            if (visit_array[p->adjacency_index] == false) {
                visit(G, p->adjacency_index);
                visit_array[p->adjacency_index] = true;
                assist_queue.enter(p->adjacency_index);
            }
            p = p->next;
        }
    }
}