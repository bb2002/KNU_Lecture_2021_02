#include<iostream>

class Point {
private:
	int x;
	int y;

public:
	explicit Point(int arr[2]);
	int getX() const;
	int getY() const;
};

Point::Point(int arr[2]) : x(arr[0]), y(arr[1]) {};

int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

int getRepValue(Point p) {
	return p.getX() + p.getY();
}

int main() {
	int pos[2] = { 1,2 };
	//std::cout << "res: " << getRepValue(pos) << std::endl;

	//Point p = pos;
}