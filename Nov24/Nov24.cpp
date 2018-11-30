#include <iostream>

using namespace std;

int f1(int);
int f1(double);
void print(int);
extern int yossi;

void swap0(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;

	//a += b; // a = a0 + b0
	//b = a - b; // b = a0 + b0 - b0 = a0
	//a = a - b; // a = a0 + b0 - a0 = b0
}

void ff(const int& n) {
	cout << n << endl;
}

const double PI = 3.14;

int main() {
	double d = 2.6;
	int i = 5, j = 2;
	d = static_cast<double>(i) / j;
	cout << d << f1(5.0) << endl;
	print(-1);
	print(1);
	swap0(i, j);
	ff(5);
	ff(i);
	return 0;
}

int f1(int m) {
	return m;
}

int f1(double m) {
	return static_cast<int>(m);
}

void print(int num) {
	if (num < 0)
		return;
	cout << num << endl;
}