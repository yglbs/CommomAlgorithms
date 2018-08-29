#include"search.h"

// 二分查找
int BinarySerach(int sequence[], int key, int length) {
	int left = 0;
	int right = length - 1;
	// 这里必须是 <=
	while (left <= right) {
		int mid = (left + right) / 2;
		if (sequence[mid] == key) {
			return mid;
		}
		else if (sequence[mid] < key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

// 二分查找第一个相等的元素位置
int FindFirstEqual(int sequence[], int key, int length) {
	int left = 0;
	int right = length - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (sequence[mid] >= key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	if (left < length && sequence[left] == key) {
		return left;
	}
	return -1;
}

// 二分查找最后一个相等的元素
int FindLastEqual(int sequence[], int key, int length) {
	int left = 0;
	int right = length - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (sequence[mid] <= key) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	if (right >= 0 && sequence[right] == key) {
		return right;
	}
	return -1;
}

// 二分查找最后一个等于或者小于key的元素
int FindLastEqualSmaller(int sequence[], int key, int length) {
	int left = 0;
	int right = length - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (sequence[mid] > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return right;
}

// 二分查找最后一个小于key的元素
int FindLastSmaller(int sequence[], int key, int length) {
	int left = 0;
	int right = length - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (sequence[mid] >= key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return right;
}

// 二分查找第一个等于或者大于key的元素
int FindFirstEqualLarger(int sequence[], int key, int length) {
	int left = 0;
	int right = length - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (sequence[mid] >= key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

// 二分查找第一个大于key的元素
int FindFirstLarger(int sequence[], int key, int length) {
	int left = 0;
	int right = length - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (sequence[mid] > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

// 线性时间查找(BFPRT): 前K小数问题
// 算法步骤：
// 1. 将n个元素每5个一组，分成n / 5(上界)组。
// 2. 取出每一组的中位数，任意排序方法，比如插入排序。
// 3. 递归的调用selection算法查找上一步中所有中位数的中位数，设为x，偶数个中位数的情况下设定为选取中间小的一个。
// 4. 用x来分割数组，设小于等于x的个数为k，大于x的个数即为n - k。
// 5. 若i == k，返回x；若i<k，在小于x的元素中递归查找第i小的元素；若i>k，在大于x的元素中递归查找第i - k小的元素。
// 原始数组进行了排序
// 插入排序，返回中位数下标
int InsertSort(int sequence[], int left, int right)
{
	int j;
	for (int i = left + 1; i <= right; i++)
	{
		int temp = sequence[i];
		j = i - 1;
		while (j >= left && sequence[j] > temp)
			sequence[j + 1] = sequence[j--];
		sequence[j + 1] = temp;
	}
	return ((right - left) >> 1) + left;
}

// 返回中位数的中位数下标
int GetPivotIndex(int sequence[], int left, int right)
{
	if (right - left < 5)
		return InsertSort(sequence, left, right);

	int sub_right = left - 1;
	for (int i = left; i + 4 <= right; i += 5)
	{
		int index = InsertSort(sequence, i, i + 4);  //找到五个元素的中位数的下标
		swap(sequence[++sub_right], sequence[index]);   //依次放在左侧
	}
	return BFPRT(sequence, left, sub_right, ((sub_right - left + 1) >> 1) + 1);
}

// 利用中位数的中位数的下标进行划分，返回分界线下标 
int Partition(int sequence[], int left, int right, int pivot_index)
{
	swap(sequence[pivot_index], sequence[right]);  //把基准放置于末尾
	int divide_index = left;  //跟踪划分的分界线
	for (int i = left; i < right; i++)
	{
		if (sequence[i] < sequence[right])
			swap(sequence[divide_index++], sequence[i]);  //比基准小的都放在左侧
	}
	swap(sequence[divide_index], sequence[right]);  //最后把基准换回来
	return divide_index;
}

int BFPRT(int sequence[], int left, int right, const int & k)
{
	int pivot_index = GetPivotIndex(sequence, left, right);            //得到中位数的中位数下标
	int divide_index = Partition(sequence, left, right, pivot_index);  //进行划分，返回划分边界
	int num = divide_index - left + 1;
	if (num == k)
		return divide_index;
	else if (num > k)
		return BFPRT(sequence, left, divide_index - 1, k);
	else
		return BFPRT(sequence, divide_index + 1, right, k - num);
}

//int main(){
//	// int sequence[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sequence[] = { 5, 2, 7, 3, 8, 1, 10, 9, 4, 6 };
//	int key = 4;
//	int length = 10;
//	int result = sequence[BFPRT(sequence, 0, 9, 1)];
//	cout << result << endl;
//	getchar();
//	return 0;
//}