#include<iostream>
#include<ctime>
using namespace std;

// �������������
void RandomSequence(int sequence[], int length, int max);

// �����㷨
void BubbleSort(int sequence[], int length); // ð������
void CocktailSort(int sequence[], int length); // ��β������
void SelectionSort(int sequence[], int length); // ѡ������
void InsertionSort(int sequence[], int length); // ��������
void InsertionSortDichotomy(int sequence[], int length); // ���ֲ�������
void ShellSort(int sequence[], int length); // ϣ������
void QuickSort(int A[], int left, int right); // ��������
void MergeSortRecursion(int A[], int left, int right);    // �ݹ�ʵ�ֵĹ鲢����(�Զ�����)
void MergeSortIteration(int A[], int len);    // �ǵݹ�(����)ʵ�ֵĹ鲢����(�Ե�����)
void HeapSort(int A[], int n); // ������

