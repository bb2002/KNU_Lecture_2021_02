#include<iostream>
using namespace std;

class Vehicle {
private:
	string type;

public:
	int regNumber;

	Vehicle() : type("Vehicle") {
		cout << "Default Constructor in " << type << " class" << endl;
	}

	~Vehicle() {
		cout << "Destructor in " << type << " class" << endl;
	}
};

class Car : public Vehicle {
private:
	string type;

public:
	Car() : type("Car") {
		cout << "Default Constructor " << type << " class" << endl;
	}

	~Car() {
		cout << "Destructor in " << type << " class" << endl;
	}
};

int main() {
	Vehicle* c = new Car();
	delete c;
}