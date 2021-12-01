#include<iostream>
using namespace std;

template<typename T, int num>
class MyArr {
private:
	T* arr = new T[num];

public:
	MyArr(std::initializer_list<int> list) {
		int i = 0;
		for (auto it = list.begin(); it != list.end(); ++it) {
			arr[i++] = *it;
		}
	}

	T operator[](int idx) const {
		return arr[idx];
	}
};

int main() {
	MyArr<int, 4> arr1 = { 1,2,3,4 };
	MyArr<int, 5> arr2 = { 10, 20, 30, 40, 50 };
	cout << "arr1[2]" << arr1[2] << endl;
	cout << "arr2[3]" << arr2[3] << endl;
}