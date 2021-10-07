#include<iostream>
using namespace std;

class Point {
private:
	static int num;
	int x;
	int y;

public:
	Point() = default;
	Point(int val1, int val2);
	void printPoint();
};

int Point::num = 0;

Point::Point(int val1, int val2) :x(val1), y(val2) {
	num++;
}

void Point::printPoint() {
	cout << "x, y: " << x << ", " << y << endl;
	cout << "Number of points : " << Point::num << endl;
}

int main() {
	Point p1 = Point(1, 2);
	p1.printPoint();
	Point p2 = Point(3, 4);
	p2.printPoint();
}
