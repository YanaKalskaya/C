#define PR(x) printf("x=%u, *x=%d, &x=%u \n", x, *x, &x)
#include <stdio.h>
using namespace std;

int main () {
	short mas [] = {100, 200, 300};
	short *ptr1, *ptr2;
	ptr1 = mas;
	ptr2 = &mas[2];
	PR(ptr1);
	ptr1++;
	PR(ptr1);
	PR(ptr2);
	++ptr2;
	printf("ptr2-ptr1=%u\n", ptr2-ptr1);
}