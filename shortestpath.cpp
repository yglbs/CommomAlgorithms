#include "shortestpath.h"
#define inf 99999999

// Floyd-Warshall算法
// 时间复杂度 ---- O(n^3)
// 空间复杂度 ---- O(n^2)
// 适用情况 ------ 稠密图，和顶点关系密切
// 负权 ---------- 可以解决负权
void FloydWarshall(int e[][11], int n){
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}
		}
	}
	// 输出
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout << e[i][j] << " ";
		}
		cout << endl;
	}
}

// Dijkstra算法
// 时间复杂度 ---- O((m+n)logn)
// 空间复杂度 ---- O(m)
// 适用情况 ------ 稠密图，和顶点关系密切
// 负权 ---------- 不能解决负权
void Dijkstra(int e[][11], int n, int p){
	int dis[11], book[11], u, v;
	// 初始化dis数组，这里是p号顶点到其余各个顶点的初始路程
	for (int j = 1; j <= n; j++){
		dis[j] = e[p][j];
	}
	for (int i = 1; i <= n; i++)
		book[i] = 0;
	book[p] = 1;
	for (int i = 1; i <= n - 1; i++){
		//找到离p号顶点最近的顶点
		int min = inf;
		for (int j = 1; j <= n; j++){
			if (book[j] == 0 && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (v = 1; v <= n; v++){
			if (e[u][v] < inf){
				if (dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
			}
		}
	}
	for (int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	cout << endl;
}

void AllPointDijkstra(int e[][11], int n){
	for (int i = 1; i <= n; i++){
		Dijkstra(e, n, i);
	}
}

// Bellman-Ford算法
// 时间复杂度 ---- O(mn)
// 空间复杂度 ---- O(m)
// 适用情况 ------ 稀疏图，和边关系密切
// 负权 ---------- 可以解决负权
void BellmanFord(int x[], int y[], int val[], int n, int m, int p){
	int dis[11];
	// 初始化dis数组，这里是p号顶点到其余各个顶点的初始路程
	for (int i = 1; i <= n; i++){
		dis[i] = inf;
	}
	dis[p] = 0;
	for (int i = 1; i <= n - 1; i++){
		for (int j = 0; j < m; j++){
			if (dis[y[j]] > dis[x[j]] + val[j]){
				dis[y[j]] = dis[x[j]] + val[j];
			}
		}
	}
	for (int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	cout << endl;
}

// 改进的Bellman-Ford算法(含负权检测)
void OptBellmanFord(int x[], int y[], int val[], int n, int m, int p){
	int dis[11], bak[11], check, flag;
	// 初始化dis数组，这里是p号顶点到其余各个顶点的初始路程
	for (int i = 1; i <= n; i++){
		dis[i] = inf;
	}
	dis[p] = 0;
	for (int i = 1; i <= n - 1; i++){
		// 将dis数组备份至bak数组中
		for (int j = 1; j <= n; j++)
			bak[i] = dis[i];
		// 进行一轮松弛
		for (int j = 0; j < m; j++){
			if (dis[y[j]] > dis[x[j]] + val[j]){
				dis[y[j]] = dis[x[j]] + val[j];
			}
		}
		// 松弛完毕后检测dis数组是否有更新
		check = 0;
		for (int j = 1; j <= n; j++){
			if (bak[j] != dis[j]){
				check = 1;
				break;
			}
		}
		if (check == 0)
			break;
	}
	// 检测负权回路
	flag = 0;
	for (int i = 0; i < m; i++){
		if (dis[y[i]] > dis[x[i]] + val[i])
			flag = 1;
	}
	if (flag == 1){
		cout << "此图含有负权回路" << endl;
	}
	else{
		for (int i = 1; i <= n; i++){
			cout << dis[i] << " ";
		}
		cout << endl;
	}
	
}

void AllPointBellmanFord(int x[], int y[], int val[], int n, int m){
	for (int i = 1; i <= n; i++){
		BellmanFord(x, y, val, n, m, i);
	}
}

//int main(){
//	int e[11][11];
//	int n, m; // n表示顶点个数，m表示边的条数
//	// 矩阵初始化
//	n = 4;
//	m = 8;
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			if (i == j)
//				e[i][j] = 0;
//			else
//				e[i][j] = inf;
//		}
//	}
//	int x[] = { 1, 1, 1, 2, 3, 3, 4, 4 };
//	int y[] = { 2, 3, 4, 3, 1, 4, 1, 3 };
//	int val[] = { 2, 6, 4, 3, 7, 1, 5, 12 };
//	for (int i = 0; i < m; i++){
//		e[x[i]][y[i]] = val[i];
//	}
//	AllPointDijkstra(e, n);
//	getchar();
//	return 0;
//}