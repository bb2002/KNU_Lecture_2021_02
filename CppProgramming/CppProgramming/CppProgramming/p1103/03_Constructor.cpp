#include<iostream>

using namespace std;

class Vehicle {
public:
	int regNumber;
	string type;

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
public:
	Car() {
		type = "Car";
		cout << "Default Constructor in " << type << " class" << endl;
	}

	Car(int val) : Vehicle(val) {
		type = "Car";
		cout << "Constructor in " << type << " class" << endl;
	}
};


int main() {
	Car car1;
	Car car2(20200001);
	car1.startEngine();
	return 0;

}