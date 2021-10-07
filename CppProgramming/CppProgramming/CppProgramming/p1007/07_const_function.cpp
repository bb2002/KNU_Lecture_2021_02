#include<iostream>

class Point {
private:
	static int num;
	int x;
	int y;

public:
	Point() = default;
	Point(int val1, int val2);
	void getNumOfPoints() const;
};

int Point::num = 0;

void Point::getNumOfPoints() const {
	std::cout << "x, y: " << x << ", " << y << std::endl;
	// x = 10;			함수 내에서 값 수정을 할 수 없다.
}

Point::Point(int val1, int val2) : x(val1), y(val2) {
	++num;
}

int main() {
	Point p1 = Point(1, 2);
	p1.getNumOfPoints();
	Point p2 = Point(3, 4);
	p2.getNumOfPoints();
}