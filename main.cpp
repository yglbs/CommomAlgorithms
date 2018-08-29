#include <iostream>
#include <stdlib.h>

using namespace std;

 int main(){
	 int x;
	 x = 123;
	 printf("%d \n", x);
	 int y;
	 int *addr = &y;
	 addr++;
	 addr++;
	 *addr = 456;
	 printf("%d \n", x);
	system("pause");
	return 0;
}
