#include<iostream>
#include<string>

using namespace std;

void FloydWarshall(int e[][11], int n); // Floyd-Warshall算法
void Dijkstra(int e[][11], int n, int p); // Dijkstra算法
void AllPointDijkstra(int e[][11], int n); // 全部顶点Dijkstra算法
void BellmanFord(int x[], int y[], int val[], int n, int m, int p); // Bellman-Ford算法
void OptBellmanFord(int x[], int y[], int val[], int n, int m, int p); // 改进的Bellman-Ford算法(含负权检测)
void AllPointBellmanFord(int x[], int y[], int val[], int n, int m); // 全部顶点Bellman-Ford算法