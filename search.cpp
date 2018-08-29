#include"search.h"

// ���ֲ���
int BinarySerach(int sequence[], int key, int length) {
	int left = 0;
	int right = length - 1;
	// ��������� <=
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

// ���ֲ��ҵ�һ����ȵ�Ԫ��λ��
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

// ���ֲ������һ����ȵ�Ԫ��
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

// ���ֲ������һ�����ڻ���С��key��Ԫ��
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

// ���ֲ������һ��С��key��Ԫ��
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

// ���ֲ��ҵ�һ�����ڻ��ߴ���key��Ԫ��
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

// ���ֲ��ҵ�һ������key��Ԫ��
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

// ����ʱ�����(BFPRT): ǰKС������
// �㷨���裺
// 1. ��n��Ԫ��ÿ5��һ�飬�ֳ�n / 5(�Ͻ�)�顣
// 2. ȡ��ÿһ�����λ�����������򷽷��������������
// 3. �ݹ�ĵ���selection�㷨������һ����������λ������λ������Ϊx��ż������λ����������趨Ϊѡȡ�м�С��һ����
// 4. ��x���ָ����飬��С�ڵ���x�ĸ���Ϊk������x�ĸ�����Ϊn - k��
// 5. ��i == k������x����i<k����С��x��Ԫ���еݹ���ҵ�iС��Ԫ�أ���i>k���ڴ���x��Ԫ���еݹ���ҵ�i - kС��Ԫ�ء�
// ԭʼ�������������
// �������򣬷�����λ���±�
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

// ������λ������λ���±�
int GetPivotIndex(int sequence[], int left, int right)
{
	if (right - left < 5)
		return InsertSort(sequence, left, right);

	int sub_right = left - 1;
	for (int i = left; i + 4 <= right; i += 5)
	{
		int index = InsertSort(sequence, i, i + 4);  //�ҵ����Ԫ�ص���λ�����±�
		swap(sequence[++sub_right], sequence[index]);   //���η������
	}
	return BFPRT(sequence, left, sub_right, ((sub_right - left + 1) >> 1) + 1);
}

// ������λ������λ�����±���л��֣����طֽ����±� 
int Partition(int sequence[], int left, int right, int pivot_index)
{
	swap(sequence[pivot_index], sequence[right]);  //�ѻ�׼������ĩβ
	int divide_index = left;  //���ٻ��ֵķֽ���
	for (int i = left; i < right; i++)
	{
		if (sequence[i] < sequence[right])
			swap(sequence[divide_index++], sequence[i]);  //�Ȼ�׼С�Ķ��������
	}
	swap(sequence[divide_index], sequence[right]);  //���ѻ�׼������
	return divide_index;
}

int BFPRT(int sequence[], int left, int right, const int & k)
{
	int pivot_index = GetPivotIndex(sequence, left, right);            //�õ���λ������λ���±�
	int divide_index = Partition(sequence, left, right, pivot_index);  //���л��֣����ػ��ֱ߽�
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