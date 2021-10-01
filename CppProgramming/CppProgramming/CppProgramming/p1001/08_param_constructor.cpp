#include<iostream>
#include<string>
using namespace std;

class Person {
private:
	string name;

public:
	Person() {
		cout << "Default constructor" << endl;
		cout << "Enter your name : ";
		getline(cin, name);
		cout << "---------------\n";
	}

	Person(string val) {
		cout << "Parameterized constructor" << endl;
		cout << val << " is assigned " << endl;
		cout << "---------------\n";
		name = val;
	}

	void printInfo() {
		cout << "Name: " << name << endl;
	}
};

int main() {
	Person p1;
	Person p2 = Person("Eggbot");
	p1.printInfo();
	p2.printInfo();
}