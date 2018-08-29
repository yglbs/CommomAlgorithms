#include "shortestpath.h"
#define inf 99999999

// Floyd-Warshall�㷨
// ʱ�临�Ӷ� ---- O(n^3)
// �ռ临�Ӷ� ---- O(n^2)
// ������� ------ ����ͼ���Ͷ����ϵ����
// ��Ȩ ---------- ���Խ����Ȩ
void FloydWarshall(int e[][11], int n){
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}
		}
	}
	// ���
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout << e[i][j] << " ";
		}
		cout << endl;
	}
}

// Dijkstra�㷨
// ʱ�临�Ӷ� ---- O((m+n)logn)
// �ռ临�Ӷ� ---- O(m)
// ������� ------ ����ͼ���Ͷ����ϵ����
// ��Ȩ ---------- ���ܽ����Ȩ
void Dijkstra(int e[][11], int n, int p){
	int dis[11], book[11], u, v;
	// ��ʼ��dis���飬������p�Ŷ��㵽�����������ĳ�ʼ·��
	for (int j = 1; j <= n; j++){
		dis[j] = e[p][j];
	}
	for (int i = 1; i <= n; i++)
		book[i] = 0;
	book[p] = 1;
	for (int i = 1; i <= n - 1; i++){
		//�ҵ���p�Ŷ�������Ķ���
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

// Bellman-Ford�㷨
// ʱ�临�Ӷ� ---- O(mn)
// �ռ临�Ӷ� ---- O(m)
// ������� ------ ϡ��ͼ���ͱ߹�ϵ����
// ��Ȩ ---------- ���Խ����Ȩ
void BellmanFord(int x[], int y[], int val[], int n, int m, int p){
	int dis[11];
	// ��ʼ��dis���飬������p�Ŷ��㵽�����������ĳ�ʼ·��
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

// �Ľ���Bellman-Ford�㷨(����Ȩ���)
void OptBellmanFord(int x[], int y[], int val[], int n, int m, int p){
	int dis[11], bak[11], check, flag;
	// ��ʼ��dis���飬������p�Ŷ��㵽�����������ĳ�ʼ·��
	for (int i = 1; i <= n; i++){
		dis[i] = inf;
	}
	dis[p] = 0;
	for (int i = 1; i <= n - 1; i++){
		// ��dis���鱸����bak������
		for (int j = 1; j <= n; j++)
			bak[i] = dis[i];
		// ����һ���ɳ�
		for (int j = 0; j < m; j++){
			if (dis[y[j]] > dis[x[j]] + val[j]){
				dis[y[j]] = dis[x[j]] + val[j];
			}
		}
		// �ɳ���Ϻ���dis�����Ƿ��и���
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
	// ��⸺Ȩ��·
	flag = 0;
	for (int i = 0; i < m; i++){
		if (dis[y[i]] > dis[x[i]] + val[i])
			flag = 1;
	}
	if (flag == 1){
		cout << "��ͼ���и�Ȩ��·" << endl;
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
//	int n, m; // n��ʾ���������m��ʾ�ߵ�����
//	// �����ʼ��
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