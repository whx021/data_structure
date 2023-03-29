/**
 * @file 1_3_shortest_path.cpp
 * @author whx (huxinwang021@gmail.com)
 * @brief shortest path algorithm in graph
 * @version 0.1
 * @date 2023-03-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief 
 * 
 * @param n         : vertex number   
 * @param MGraph    : matrix graph
 * @param v0        : start vertex
 * @param distance  : distance array
 * @param path      : path array
 */
#define MAX_VERTEX 20
#define INFINITY 65535
void Dijkstra(const int& n, float** MGraph, int v0, int distance[], int path[]) {
    // initialize distance array & path array
    bool set[MAX_VERTEX] = { 0 };   // record the vertex whether has been visited
}