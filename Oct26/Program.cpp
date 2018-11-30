#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	//unsigned char c = '\a';
	double num = -123456789000000000;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "###" << '\a' << "###\n";
	cout << "###" << num << "###\n";
	srand(time(nullptr));
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 9; ++j)
			cout << rand() % 1000 << '\t';
		cout << rand() % 1000 << '\n';
	}
	cout << "\"\'\\\?" << endl;
	int a = (num < 10) ? (num < 5 ? 2 : 3) : 9 ;

	return 0;
}