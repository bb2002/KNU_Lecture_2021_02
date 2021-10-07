#include<iostream>

class Point {
private:
	static int num;
	int x;
	int y;

public:
	Point() = default;
	Point(int val1, int val2);
	static void getNumOfPoints();
};

int Point::num = 0;

void Point::getNumOfPoints() {
	std::cout << "Number of points : " << Point::num << std::endl;
}

Point::Point(int val1, int val2) : x(val1), y(val2) {
	++num;
}

int main() {
	Point::getNumOfPoints();
	Point p1 = Point(1, 2);
	p1.getNumOfPoints();
	Point p2 = Point(3, 4);
	p2.getNumOfPoints();
}