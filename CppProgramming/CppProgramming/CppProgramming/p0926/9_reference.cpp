#include <iostream>
using namespace std;
int main() {
	int a;
	int& ra = a;
	int& rra = ra;

	a = 111;
	cout << "a : " << a << endl;
	cout << "ra : " << ra << endl;
	cout << "rra : " << rra << endl;

	ra = 401;
	cout << "a : " << a << endl;
	cout << "ra : " << ra << endl;
	cout << "raa : " << rra << endl;

	rra = 409;
	cout << "a : " << a << endl;
	cout << "ra : " << ra << endl;
	cout << "rra : " << rra << endl;
}
