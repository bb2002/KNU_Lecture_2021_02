#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string* name;

public:
	Person(string val) {
		cout << "Parameterized constructor" << endl;
		name = new string;
		*name = val;
	}

	~Person() {
		cout << "Destructor is called" << endl;
		delete name;
	}

	void printInfo() {
		cout << "Name : " << *name << endl;;
	}
};
int main() {
	Person p1("Albert");
	p1.printInfo();
	return 0;
}
