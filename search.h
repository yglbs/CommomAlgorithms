#include<iostream>
#include<algorithm>

using namespace std;

int BinarySerach(int sequence[], int key, int length); // ���ֲ���
int FindFirstEqual(int sequence[], int key, int length); // ���ֲ��ҵ�һ����ȵ�Ԫ��λ��
int FindLastEqual(int sequence[], int key, int length); // ���ֲ������һ����ȵ�Ԫ��
int FindLastEqualSmaller(int sequence[], int key, int length); // ���ֲ������һ�����ڻ���С��key��Ԫ��
int FindLastSmaller(int sequence[], int key, int length); // ���ֲ������һ��С��key��Ԫ��
int FindFirstEqualLarger(int sequence[], int key, int length); // ���ֲ��ҵ�һ�����ڻ��ߴ���key��Ԫ��
int FindFirstLarger(int sequence[], int key, int length); // ���ֲ��ҵ�һ������key��Ԫ��

// ����ʱ�����(BFPRT): ǰKС������
int InsertSort(int sequence[], int left, int right);
int GetPivotIndex(int sequence[], int left, int right);
int Partition(int sequence[], int left, int right, int pivot_index);
int BFPRT(int sequence[], int left, int right, const int & k);