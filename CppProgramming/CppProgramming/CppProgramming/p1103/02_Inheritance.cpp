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

class Bus : public Vehicle {
public:
	int passengerCapacity;
};

int main() {
	Car car;
	Bus bus1;

	car.regNumber = 2020001;
	car.brand = "BMW";

	bus1.regNumber = 2020002;
	bus1.passengerCapacity = 300;

	car.startEngine();
	bus1.startEngine();
}