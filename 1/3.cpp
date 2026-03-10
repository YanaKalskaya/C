#include <iostream>
using namespace std;

int main () {
	system("chcp 1251 > nul");
	int a=2, b=5;
	void obmen1(int, int);
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	cout << "Исходные значения: a=" << a << ", b=" << b << endl;
	obmen1 (a, b);
	cout << "После обмена 1: a=" << a << ", b=" << b << endl;
	obmen2 (&a, &b);
	cout << "После обмена 2: a=" << a << ", b=" << b << endl;
	obmen3 (a, b);
	cout << "После обмена 3: a=" << a << ", b=" << b << endl;
}

void obmen1(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void obmen2(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void obmen3(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
