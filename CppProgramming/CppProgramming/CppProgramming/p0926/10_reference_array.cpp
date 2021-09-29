#include<iostream>
using namespace std;

int main() {

	int arr[2] = { 111, 222 };
	int (&rArr)[2] = arr;
	
	cout << "arr[0]: " << arr[0] << endl;
	cout << "arr[1]: " << arr[1] << endl;

	cout << "rArr[0]: " << rArr[0] << endl;
	cout << "rArr[1]: " << rArr[1] << endl;

}