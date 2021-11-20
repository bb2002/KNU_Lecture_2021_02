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
	// Vehicle* v = new Vehicle(); 순수 가상 함수가 있으면 추상 클래스가 됨.
	v->startEngine();
}