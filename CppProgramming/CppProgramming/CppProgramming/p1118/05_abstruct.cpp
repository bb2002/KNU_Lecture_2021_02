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

class Car : public Vehicle {
private:
	string type;

public:
	Car() :type("Car") {
		cout << "Default Constructor in " << type << " class" << endl;
	}
	void accelerate() {
		cout << "Acceleration in " << type << " class" << endl;
	}
};

int main() {
	// Car* c = new Car(); //error!!!
	// c->accelerate();		// 부모 클래스의 순수 가상 함수를 override 해야함.
}