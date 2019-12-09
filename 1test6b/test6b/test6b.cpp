#include <iostream>
#include <cmath>
using namespace std;


int fact(int a) {

	if (a == 0 || a == 1) {

		return 1;
	}

	return a * fact(a - 1);
}


int main() {

	setlocale(0, "");

	int k = 1;
	int counterOfElements = 0;
	const double eps = 0.000001;
	double a, b, c, d;
	double element;
	double sum = 0;
	double x;
	cout << "x\t\t\t";
	cin >> x;

	do {

		a = pow(-1, k);
		b = pow(x, 2 * k + 1);
		c = fact(k);
		d = 2 * k + 1;

		element = a * b / c / d;

		sum += element;

		counterOfElements++;
		k++;

	} while (abs(element) >= eps);

	sum -= element;
	counterOfElements--;

	cout << "sum\t\t\t" << sum << endl;
	cout << "кол-во элементов\t" << counterOfElements << endl;
	system("pause");
	return 0;
}