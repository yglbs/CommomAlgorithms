// �����㷨��ð�ݣ���β�ƣ�ѡ�񣬲��룬���ֲ��룬ϣ�������ţ��鲢��������
#include "sort.h"

// �����������
void RandomSequence(int sequence[], int length, int max){
	srand((unsigned)time(NULL));
	for (int i = 0; i < length; i++){
		sequence[i] = rand() % max + 1;
	}
}

// ð������
// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n^2)
// ����ʱ�临�Ӷ� ---- ��������ڲ�ѭ����һ������ʱ,ʹ��һ���������ʾ������Ҫ�����Ŀ���,���԰�����ʱ�临�ӶȽ��͵�O(n)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ �ȶ�
void BubbleSort(int sequence[], int length){
	for (int i = 0; i < length - 1; i++){
		for (int j = 0; j < length - 1 - i; j++){
			if (sequence[j] > sequence[j + 1]){
				int temp = sequence[j];
				sequence[j] = sequence[j + 1];
				sequence[j + 1] = temp;
			}
		}
	}
}

// ��β������
// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n^2)
// ����ʱ�临�Ӷ� ---- ���������һ��ʼ�Ѿ��󲿷�������Ļ�,��ӽ�O(n)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ �ȶ�
void CocktailSort(int sequence[], int length){
	int left = 0;
	int right = length - 1;
	while (left < right){
		for (int i = left; i < right; i++){
			if (sequence[i] > sequence[i + 1]){
				int temp = sequence[i];
				sequence[i] = sequence[i + 1];
				sequence[i + 1] = temp;
			}
		}
		right--;
		for (int i = right; i > left; i--){
			if (sequence[i - 1] > sequence[i]){
				int temp = sequence[i];
				sequence[i] = sequence[i - 1];
				sequence[i - 1] = temp;
			}
		}
		left++;
	}
}

// ѡ������
// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n^2)
// ����ʱ�临�Ӷ� ---- O(n^2)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ ���ȶ�
void SelectionSort(int sequence[], int length){
	for (int i = 0; i < length - 1; i++){
		int min = i;
		for (int j = i + 1; j < length; j++){
			if (sequence[j] < sequence[min]){
				min = j;
			}
		}
		if (min != i){
			int temp = sequence[i];
			sequence[i] = sequence[min];
			sequence[min] = temp;
		}
	}
}

// ��������
// ���� ------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- ����Ϊ���������ǽ������е�,��ʱʱ�临�Ӷ�O(n^2)
// ����ʱ�临�Ӷ� ---- ������Ϊ�����������������е�,��ʱʱ�临�Ӷ�O(n)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ �ȶ�
void InsertionSort(int sequence[], int length){
	for (int i = 1; i < length; i++){
		int flag = sequence[i];
		int j = i - 1;
		while (j >= 0 && sequence[j] > flag){
			sequence[j + 1] = sequence[j];
			j--;
		}
		sequence[j + 1] = flag;
	}
}

// ���ֲ�������
// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(n^2)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(n^2)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ �ȶ�
void InsertionSortDichotomy(int sequence[], int length){
	for (int i = 1; i < length; i++){
		int flag = sequence[i];
		int left = 0;
		int right = i - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (sequence[mid] > flag)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (int j = i - 1; j >= left; j--){
			sequence[j + 1] = sequence[j];
		}
		sequence[left] = flag;
	}
}

// ϣ������
// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- ���ݲ������еĲ�ͬ����ͬ����֪��õ�ΪO(n(logn)^2)
// ����ʱ�临�Ӷ� ---- O(n)
// ƽ��ʱ�临�Ӷ� ---- ���ݲ������еĲ�ͬ����ͬ��
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ ���ȶ�
void ShellSort(int sequence[], int length){
	int h = 0;
	while (h <= length){
		h = 3 * h + 1; // ���ɳ�ʼ����
	}
	while (h >= 1){
		for (int i = h; i < length; i++){
			int j = i - h;
			int flag = sequence[i];
			while (j >= 0 && sequence[j] > flag){
				sequence[j + h] = sequence[j];
				j = j - h;
			}
			sequence[j + h] = flag;
		}
		h = (h - 1) / 3; // �ݼ�����
	}
}

// ��������
// ���� ------------ �ڲ��Ƚ�����
// ���ݽṹ --------- ����
// ���ʱ�临�Ӷ� ---- ÿ��ѡȡ�Ļ�׼������󣨻���С����Ԫ�أ�����ÿ��ֻ���ֳ���һ����������Ҫ����n-1�λ��ֲ��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(n^2)
// ����ʱ�临�Ӷ� ---- ÿ��ѡȡ�Ļ�׼������λ��������ÿ�ζ����ȵĻ��ֳ�����������ֻ��Ҫlogn�λ��־��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ ��Ҫ�ǵݹ���ɵ�ջ�ռ��ʹ��(��������left��right�Ⱦֲ�����)��ȡ���ڵݹ�������ȣ�һ��ΪO(logn)�����ΪO(n)       
// �ȶ��� ---------- ���ȶ�
int Partition(int A[], int left, int right)  // ���ֺ���
{
	int pivot = A[right];               // ����ÿ�ζ�ѡ�����һ��Ԫ����Ϊ��׼
	int tail = left - 1;                // tailΪС�ڻ�׼�����������һ��Ԫ�ص�����
	for (int i = left; i < right; i++)  // ������׼���������Ԫ��
	{
		if (A[i] <= pivot)              // ��С�ڵ��ڻ�׼��Ԫ�طŵ�ǰһ��������ĩβ
		{
			swap(A[++tail], A[i]);
		}
	}
	swap(A[tail + 1], A[right]);           // ���ѻ�׼�ŵ�ǰһ��������ĺ�ߣ�ʣ�µ���������Ǵ��ڻ�׼��������
	return tail + 1;                    // ���ػ�׼������
}

void QuickSort(int A[], int left, int right)
{
	if (left >= right)
		return;
	int pivot_index = Partition(A, left, right); // ��׼������
	QuickSort(A, left, pivot_index - 1);
	QuickSort(A, pivot_index + 1, right);
}

// �鲢����
// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(nlogn)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ O(n)
// �ȶ��� ------------ �ȶ�
void Merge(int A[], int left, int mid, int right)// �ϲ��������ź��������A[left...mid]��A[mid+1...right]
{
	int len = right - left + 1;
	int *temp = new int[len];       // �����ռ�O(n)
	int index = 0;
	int i = left;                   // ǰһ�������ʼԪ��
	int j = mid + 1;                // ��һ�������ʼԪ��
	while (i <= mid && j <= right)
	{
		temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // ���Ⱥű�֤�鲢������ȶ���
	}
	while (i <= mid)
	{
		temp[index++] = A[i++];
	}
	while (j <= right)
	{
		temp[index++] = A[j++];
	}
	for (int k = 0; k < len; k++)
	{
		A[left++] = temp[k];
	}
}

void MergeSortRecursion(int A[], int left, int right)    // �ݹ�ʵ�ֵĹ鲢����(�Զ�����)
{
	if (left == right)    // ������������г���Ϊ1ʱ���ݹ鿪ʼ���ݣ�����merge����
		return;
	int mid = (left + right) / 2;
	MergeSortRecursion(A, left, mid);
	MergeSortRecursion(A, mid + 1, right);
	Merge(A, left, mid, right);
}

void MergeSortIteration(int A[], int len)    // �ǵݹ�(����)ʵ�ֵĹ鲢����(�Ե�����)
{
	int left, mid, right;// ����������,ǰһ��ΪA[left...mid]����һ��������ΪA[mid+1...right]
	for (int i = 1; i < len; i *= 2)        // ������Ĵ�Сi��ʼΪ1��ÿ�ַ���
	{
		left = 0;
		while (left + i < len)              // ��һ�����������(��Ҫ�鲢)
		{
			mid = left + i - 1;
			right = mid + i < len ? mid + i : len - 1;// ��һ���������С���ܲ���
			Merge(A, left, mid, right);
			left = right + 1;               // ǰһ����������������ƶ�
		}
	}
}

// ������
// ���� -------------- �ڲ��Ƚ�����
// ���ݽṹ ---------- ����
// ���ʱ�临�Ӷ� ---- O(nlogn)
// ����ʱ�临�Ӷ� ---- O(nlogn)
// ƽ��ʱ�临�Ӷ� ---- O(nlogn)
// ���踨���ռ� ------ O(1)
// �ȶ��� ------------ ���ȶ�
void Heapify(int A[], int i, int size)  // ��A[i]���½��жѵ���
{
	int left_child = 2 * i + 1;         // ��������
	int right_child = 2 * i + 2;        // �Һ�������
	int max = i;                        // ѡ����ǰ����������Һ�������֮�е����ֵ
	if (left_child < size && A[left_child] > A[max])
		max = left_child;
	if (right_child < size && A[right_child] > A[max])
		max = right_child;
	if (max != i)
	{
		swap(A[i], A[max]);                // �ѵ�ǰ�����������(ֱ��)�ӽڵ���н���
		Heapify(A, max, size);          // �ݹ���ã������ӵ�ǰ������½��жѵ���
	}
}

int BuildHeap(int A[], int n)           // ���ѣ�ʱ�临�Ӷ�O(n)
{
	int heap_size = n;
	for (int i = heap_size / 2 - 1; i >= 0; i--) // ��ÿһ����Ҷ��㿪ʼ���½��жѵ���
		Heapify(A, i, heap_size);
	return heap_size;
}

void HeapSort(int A[], int n)
{
	int heap_size = BuildHeap(A, n);    // ����һ������
	while (heap_size > 1)   // �ѣ���������Ԫ�ظ�������1��δ�������
	{
		// ���Ѷ�Ԫ����ѵ����һ��Ԫ�ػ��������Ӷ���ȥ�����һ��Ԫ��
		// �˴������������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Զ������ǲ��ȶ��������㷨
		swap(A[0], A[--heap_size]);
		Heapify(A, 0, heap_size);     // ���µĶѶ�Ԫ�ؿ�ʼ���½��жѵ�����ʱ�临�Ӷ�O(logn)
	}
}

//int main(){
//	int sequence[10];
//	RandomSequence(sequence, 10, 50);
//	for (int i = 0; i < 10; i++){
//		cout << sequence[i] << " ";
//	}
//	cout << endl;
//	HeapSort(sequence, 10);
//	for (int i = 0; i < 10; i++){
//		cout << sequence[i] << " ";
//	}
//	return 0;
//}