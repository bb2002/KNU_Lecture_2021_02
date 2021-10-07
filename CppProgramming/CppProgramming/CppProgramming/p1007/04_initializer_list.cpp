#include<iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
	const int z;

public:
	Point() = default;
	Point(int val1, int val2);
	void printPoint();
};

Point::Point(int val1, int val2) : x(val1), y(val2), z(0) {}

int main() {
	Point p1 = Point(1, 2);
	p1.printPoint();
}

void Point::printPoint()
{
	cout << "x, y, z : " << x << ", " << y << ", " << z << endl;
}
