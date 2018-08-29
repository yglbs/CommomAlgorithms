#include<iostream>
#include<algorithm>

using namespace std;

int BinarySerach(int sequence[], int key, int length); // 二分查找
int FindFirstEqual(int sequence[], int key, int length); // 二分查找第一个相等的元素位置
int FindLastEqual(int sequence[], int key, int length); // 二分查找最后一个相等的元素
int FindLastEqualSmaller(int sequence[], int key, int length); // 二分查找最后一个等于或者小于key的元素
int FindLastSmaller(int sequence[], int key, int length); // 二分查找最后一个小于key的元素
int FindFirstEqualLarger(int sequence[], int key, int length); // 二分查找第一个等于或者大于key的元素
int FindFirstLarger(int sequence[], int key, int length); // 二分查找第一个大于key的元素

// 线性时间查找(BFPRT): 前K小数问题
int InsertSort(int sequence[], int left, int right);
int GetPivotIndex(int sequence[], int left, int right);
int Partition(int sequence[], int left, int right, int pivot_index);
int BFPRT(int sequence[], int left, int right, const int & k);