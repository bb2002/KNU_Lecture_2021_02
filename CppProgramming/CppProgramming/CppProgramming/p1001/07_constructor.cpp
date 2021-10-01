#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int id;

public:
	Person();

	void printInfo();
};

Person::Person() {
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your id: ";
	cin >> id;
}

void Person::printInfo() {
	cout << "Name : " << name << endl;
	cout << "Id : " << id << endl;
}

int main() {
	Person p1;
	p1.printInfo();
	return 0;
}