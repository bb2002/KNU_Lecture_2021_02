#include <iostream>
#include<string>

using namespace std;

// ù��° ���
//struct mystruct {
//	string name;
//	int id;
//} student;

// �ι�° ���
//struct mystruct {
//	string name;
//	int id;
//	string department;
//	double GPA;
//};
//
//struct mystruct student;

typedef struct {
	string name;
	int id;
	string department;
	double GPA;
} MyStruct;

// MyStruct student;

int main() {
	// MyStruct student = { "Albert", 20200000, "CSE", 4.5 };

	/*MyStruct* student = (MyStruct*)malloc(sizeof(MyStruct));
	student->name = "Albert";
	student->id = 20200000;
	student->department = "CSE";
	student->GPA = 4.5;*/

	MyStruct* student = new MyStruct;
	student->name = "Albert";
	student->id = 20200000;
	student->department = "CSE";
	student->GPA = 4.5;

	std::cout << student->name << ", " << student->id << ", " << student->department << ", " << student->GPA << std::endl;

}