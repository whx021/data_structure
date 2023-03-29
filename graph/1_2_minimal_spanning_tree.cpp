// minimal spanning tree
// Prim algorithm : 以结点为单位构造最小生成树
// Kruskal algorithm : 以边为单位构造最小生成树

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using std::cout;
using std::endl;
using std::vector;
using std::sort;
namespace Prim {
// Prim algorithm graph structure
#define INFINITE 32767
char Vertex[5] = { 'a', 'b', 'c', 'd', 'e' };
double Edge[5][5];

// initialize adjacency matrix
void initAdjacencyMatrixGraph(void) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            Edge[i][j] = INFINITE;
        }
    }
}
/*
 * FunctionName : Prim()
 * Description : calculate the sum of the weights of the minimal spanning tree
 * Parameter 1 : the number of vertexes of the graph 
 * Parameter 2 : the object graph : Two-dimensional array
 * Parameter 3 : the first vertex of the minimal spanning tree
 * Parameter 4 : the weights of the minimal spanning tree 
 */
void Prim(const int& n, const double**& MatrixGraph, const int& v0, double& sum) {
    int lowCost[n];     // 记录当前生成树到其余各顶点边的最小权值
    // lowCost[n] : 当前生成树到顶点n边权值最小的权值
    
    bool vertexSet[n];  // 记录n顶点是否已经并入生成树
    // vertexSet[n] = true : 顶点n已经并入生成树
    // vertexSet[n] = false : 顶点n未并入生成树
    
    int v, k, min;  // v记录刚并入的顶点
    
    // 初始化lowCost array & vertexSet array & v & sum
    for (int i = 0; i < n; ++i) {
        lowCost[i] = MatrixGraph[v0][i];
        // vertexSet[i] = { 0 };
        memset(vertexSet, 0, sizeof(vertexSet));
    }
    v = v0;             
    vertexSet[v] = true;
    sum = 0;

    // 构建生成树的主要过程
    for (int i = 0; i < n - 1; ++i) {
        // 选出没有并入生成树且权值最小的边, 并将改变并入生成树
        min = INFINITE;
        for (int j = 0; j < n; ++j) {
            if (vertexSet[j] == false && lowCost[j] < min) {
                min = lowCost[j];
                k = j;
            }
        }
        vertexSet[k] = true;    // 标记k顶点已经访问
        v = k;                  // 记录刚并入的结点k
        sum += min;             // 更新最小生成树代价

        // 通过刚并入的顶点v到其他顶点的权值, 更新lowCost array 
        for (int j = 0; j < n; ++j) {
            if (vertexSet[j] == false && MatrixGraph[v][j] < lowCost[j]) {
                lowCost[j] = MatrixGraph[v][j];
            }
        }
    }
}

}   // namespace Prim


#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::sort;
namespace Kruskal {
// Kruskal algorithm graph structure : 以边为单位构造最小生成树
#define MAXSIZE 100
typedef struct {
    int a, b;   // 边的两个顶点
    int weight; // 边的权重
} Road;
Road road[MAXSIZE];

/*
 * FunctionName : getRoot()
 * Description : 并查集寻找根结点
 * Called by : Kruskal()
 * Parameter 1 : 并查集数组
 * Parameter 2 : need to find root node of the node
 * Return : the root node of Parameter node  
 */
int getRoot(const int* v, int p) {
    while (p != v[p]) {
        p = v[p];
    }
    return p;
}

/* 
 * FunctionName : Kruskal()
 * Call 1 : getRoot()
 * Call 2 : sort()
 * Parameter 1 : the Road of graph structure
 * Parameter 2 : the node numbers of graph
 * Parameter 3 : the road numbers of graph
 * Parameter 4 : the weights of the minimal spanning tree  
 */
void Kruskal(Road* road, const int& n, const int& e, int& sum) {
    int a = 0, b = 0;
    sum = 0;
    vector<int> v = { 0 };
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
}

}   // namespace Kruskal 