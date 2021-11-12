#include<iostream>

using namespace std;

class Vehicle {
private:
	string type;
public:
	int regNumber;

	virtual void fun() {}

	Vehicle() {
		type = "Vehicle";
		cout << "Default Constructor in " << type << " class" << endl;
	}
	Vehicle(int val) :type("Vehicle") {
		regNumber = val;
		cout << "Constructor in " << type << " class" << endl;
	}
	virtual void startEngine() {
		cout << type << "'s engine is starting" << endl;
	}
};


class Car : public Vehicle {
private:
	string type;
public:
	Car() {
		type = "Car";
		cout << "Default Constructor in " << type << " class" << endl;
	}

	Car(int val) :Vehicle(val) {
		type = "Car";
		cout << "Constructor in " << type << " class" << endl;
	}

	void startEngine() override  {
		cout << type << "'s engine is starting" << endl;
	}
};

class Bus : public Vehicle {
private:
	string type;
public:
	Bus() :type("Bus") {
		cout << "Default Constructor in " << type << " class" << endl;
	}
	void startEngine() override {
		cout << type << "'s engine is starting" << endl;
	}
};

int main() {
	Vehicle** v = new Vehicle * [2];
	Bus b;
	Car c;
	v[0] = &b;
	v[1] = &c;
	for (int i = 0; i < 2; i++) {
		v[i]->startEngine();
	}
	return 0;
}