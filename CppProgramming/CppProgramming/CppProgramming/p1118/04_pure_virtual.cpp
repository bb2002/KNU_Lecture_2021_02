#include<iostream>

using namespace std;

class Vehicle {
private:
	string type;
public:
	int regNumber;

	Vehicle() :type("Vehicle") {
		cout << "Default Constructor in " << type << " class" << endl;
	}

	virtual void startEngine() = 0;
};

int main() {
	// Vehicle* v = new Vehicle(); ���� ���� �Լ��� ������ �߻� Ŭ������ ��.
	v->startEngine();
}