#include <iostream>
#include <stdlib.h>
#include "sort.h"

int main(){
	int sequence[10];
	RandomSequence(sequence, 10, 50);
	for (int i = 0; i < 10; i++){
		cout << sequence[i] << " ";
	}
	cout << endl;
	HeapSort(sequence, 10);
	for (int i = 0; i < 10; i++){
		cout << sequence[i] << " ";
	}
	system("pause");
	return 0;
}