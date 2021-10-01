#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string name;
	int id;
public:
	Person() {
		cout << "Enter your name: ";
		getline(cin, name);
		cout << "Enter your id: ";
		cin >> id;
	}

	void printInfo() {
		cout << "Name : " << name << endl;
		cout << "Id : " << id << endl;
	}
};

int main() {
	Person p1;
	//Person p1=Person();
	p1.printInfo();
	return 0;
}