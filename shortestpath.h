#include<iostream>
#include<string>

using namespace std;

void FloydWarshall(int e[][11], int n); // Floyd-Warshall�㷨
void Dijkstra(int e[][11], int n, int p); // Dijkstra�㷨
void AllPointDijkstra(int e[][11], int n); // ȫ������Dijkstra�㷨
void BellmanFord(int x[], int y[], int val[], int n, int m, int p); // Bellman-Ford�㷨
void OptBellmanFord(int x[], int y[], int val[], int n, int m, int p); // �Ľ���Bellman-Ford�㷨(����Ȩ���)
void AllPointBellmanFord(int x[], int y[], int val[], int n, int m); // ȫ������Bellman-Ford�㷨