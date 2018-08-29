// 排序算法：冒泡，鸡尾酒，选择，插入，二分插入，希尔，快排，归并，堆排序
#include "sort.h"

// 生成随机序列
void RandomSequence(int sequence[], int length, int max){
	srand((unsigned)time(NULL));
	for (int i = 0; i < length; i++){
		sequence[i] = rand() % max + 1;
	}
}

// 冒泡排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
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

// 鸡尾酒排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果序列在一开始已经大部分排序过的话,会接近O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
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

// 选择排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
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

// 插入排序
// 分类 ------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
// 最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
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

// 二分插入排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
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

// 希尔排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 根据步长序列的不同而不同。已知最好的为O(n(logn)^2)
// 最优时间复杂度 ---- O(n)
// 平均时间复杂度 ---- 根据步长序列的不同而不同。
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
void ShellSort(int sequence[], int length){
	int h = 0;
	while (h <= length){
		h = 3 * h + 1; // 生成初始增量
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
		h = (h - 1) / 3; // 递减增量
	}
}

// 快速排序
// 分类 ------------ 内部比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- 每次选取的基准都是最大（或最小）的元素，导致每次只划分出了一个分区，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
// 最优时间复杂度 ---- 每次选取的基准都是中位数，这样每次都均匀的划分出两个分区，只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ 主要是递归造成的栈空间的使用(用来保存left和right等局部变量)，取决于递归树的深度，一般为O(logn)，最差为O(n)       
// 稳定性 ---------- 不稳定
int Partition(int A[], int left, int right)  // 划分函数
{
	int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
	int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
	for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
	{
		if (A[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
		{
			swap(A[++tail], A[i]);
		}
	}
	swap(A[tail + 1], A[right]);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
	return tail + 1;                    // 返回基准的索引
}

void QuickSort(int A[], int left, int right)
{
	if (left >= right)
		return;
	int pivot_index = Partition(A, left, right); // 基准的索引
	QuickSort(A, left, pivot_index - 1);
	QuickSort(A, pivot_index + 1, right);
}

// 归并排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(n)
// 稳定性 ------------ 稳定
void Merge(int A[], int left, int mid, int right)// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
{
	int len = right - left + 1;
	int *temp = new int[len];       // 辅助空间O(n)
	int index = 0;
	int i = left;                   // 前一数组的起始元素
	int j = mid + 1;                // 后一数组的起始元素
	while (i <= mid && j <= right)
	{
		temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
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

void MergeSortRecursion(int A[], int left, int right)    // 递归实现的归并排序(自顶向下)
{
	if (left == right)    // 当待排序的序列长度为1时，递归开始回溯，进行merge操作
		return;
	int mid = (left + right) / 2;
	MergeSortRecursion(A, left, mid);
	MergeSortRecursion(A, mid + 1, right);
	Merge(A, left, mid, right);
}

void MergeSortIteration(int A[], int len)    // 非递归(迭代)实现的归并排序(自底向上)
{
	int left, mid, right;// 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
	for (int i = 1; i < len; i *= 2)        // 子数组的大小i初始为1，每轮翻倍
	{
		left = 0;
		while (left + i < len)              // 后一个子数组存在(需要归并)
		{
			mid = left + i - 1;
			right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
			Merge(A, left, mid, right);
			left = right + 1;               // 前一个子数组索引向后移动
		}
	}
}

// 堆排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整
{
	int left_child = 2 * i + 1;         // 左孩子索引
	int right_child = 2 * i + 2;        // 右孩子索引
	int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
	if (left_child < size && A[left_child] > A[max])
		max = left_child;
	if (right_child < size && A[right_child] > A[max])
		max = right_child;
	if (max != i)
	{
		swap(A[i], A[max]);                // 把当前结点和它的最大(直接)子节点进行交换
		Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整
	}
}

int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
	int heap_size = n;
	for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
		Heapify(A, i, heap_size);
	return heap_size;
}

void HeapSort(int A[], int n)
{
	int heap_size = BuildHeap(A, n);    // 建立一个最大堆
	while (heap_size > 1)   // 堆（无序区）元素个数大于1，未完成排序
	{
		// 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
		// 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
		swap(A[0], A[--heap_size]);
		Heapify(A, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
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