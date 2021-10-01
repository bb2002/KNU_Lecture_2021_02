#include<iostream>
#include<string>
using namespace std;

class Person {
private:
	string name;

public:
	Person() = default;

	Person(string val) {
		cout << "Parameterized constructor" << endl;
		cout << val << " is assigned " << endl;
		cout << "---------------\n";
		name = val;
	}

	Person(const Person& person) {
		cout << "Copy constructor" << endl;
		name = person.name;
	}

	void printInfo() {
		cout << "Name: " << name << endl;
	}
};

int main() {
	Person p1("Albert");
	Person p2 = p1;
	p1.printInfo();
	p2.printInfo();
	return 0;
}