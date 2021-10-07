#include<iostream>

class Point {
private:
	int x;
	int y;

public:
	Point();
	Point(int val1, int val2);
	Point(const Point& p);
};

Point::Point(int val1, int val2)
{
	x = val1;
	y = val2;
}

Point::Point()
{
	std::cout << "default constructor" << std::endl;
}

//Point::Point(const Point& p)
//{
//	std::cout << "Copy Constructor" << std::endl;
//	x = p.x;
//	y = p.y;
//}

int main() {
	Point p1 = Point(1, 2);
	Point p2;
	p2 = p1;
}
