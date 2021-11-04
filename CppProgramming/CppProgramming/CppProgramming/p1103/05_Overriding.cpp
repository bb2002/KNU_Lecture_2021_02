#include<iostream>

using namespace std;

class Vehicle {
public:
	int regNumber;

private:
	string type;

public:
	Vehicle() {
		type = "Vehicle";
		cout << "Default Constructor in " << type << " class" << endl;
	}

	Vehicle(int val) : type("Vehicle") {
		regNumber = val;
		cout << "Constructor in " << type << " class" << endl;
	}


	void startEngine() {
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

	Car(int val) : Vehicle(val) {
		type = "Car";
		cout << "Constructor in " << type << " class" << endl;
	}

	void startEngine() {
		cout << type << "'s engine is starting" << endl;
	}
};


int main() {
	Car car1;
	Car car2(20200001);
	car1.startEngine();
	return 0;

}