#include<iostream>

using namespace std;

class Vehicle {
public:
	int regNumber;

	void startEngine() {
		cout << "Engine is starting" << endl;
	}
	void accelerate() {
		cout << "Vehicle is accelerating" << endl;
	}

	void applyBrakes() {
		cout << "Brakes are being applied" << endl;
	}
};

class Car : public Vehicle {
public:
	string brand;
};

int main() {
	Car car;

	car.regNumber = 2020001;
	car.brand = "BMW";

	cout << "MyCar's brand: " << car.brand << ", reg. number:" << car.regNumber << endl;

	car.startEngine();
	car.accelerate();
}