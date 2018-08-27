#include<iostream>
#include<ctime>
using namespace std;

// 随机子序列生成
void RandomSequence(int sequence[], int length, int max);

// 排序算法
void BubbleSort(int sequence[], int length); // 冒泡排序
void CocktailSort(int sequence[], int length); // 鸡尾酒排序
void SelectionSort(int sequence[], int length); // 选择排序
void InsertionSort(int sequence[], int length); // 插入排序
void InsertionSortDichotomy(int sequence[], int length); // 二分插入排序
void ShellSort(int sequence[], int length); // 希尔排序
void QuickSort(int A[], int left, int right); // 快速排序
void MergeSortRecursion(int A[], int left, int right);    // 递归实现的归并排序(自顶向下)
void MergeSortIteration(int A[], int len);    // 非递归(迭代)实现的归并排序(自底向上)
void HeapSort(int A[], int n); // 堆排序

