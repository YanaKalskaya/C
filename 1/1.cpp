#include <iostream>
using namespace std;

int main () {
	system("chcp 1251 > nul");
	int i, k, n;
	int power(int, int);
    cout<<"Введите основание степени"<<endl;
	cin >> n;
	for (i=0; i<10; i++) {
		k=power(n, i);
		cout<<"i = "<<i<<", k = "<<k<<endl;
	}
}

int power(int x, int n) {
	int i, p=1;
	for(i=1;i<=n;i++) p*=x;
	return p;
}