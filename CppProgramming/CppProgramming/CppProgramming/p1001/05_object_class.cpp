#include <iostream>
using namespace std;

class Person {
private:
	string name;
	int id;
public:
	void setInfo(string _name, int _id) {
		name = _name;
		id = _id;
	}
	void printInfo() {
		cout << "Name : " << name << endl;
		cout << "Id : " << id << endl;
	}
};

int main() {
	Person p1;
	p1.setInfo("Albert", 20200000);
	p1.printInfo();
	return 0;
}