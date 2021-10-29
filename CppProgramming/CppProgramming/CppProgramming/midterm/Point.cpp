#include<iostream>

class Point {
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {
		std::cout << "Point(int x = 0, int y = 0)" << std::endl;
	}
	
	Point(const Point& ref) {
		std::cout << "Point(const Point& ref)" << std::endl;
		this->xpos = ref.xpos;
		this->ypos = ref.ypos;
	}

	void showPosition() const {
		std::cout << this->xpos << ", " << this->ypos << std::endl;
	}


	friend Point& operator++(Point&);
	friend Point& operator++(Point&, int);
	friend Point operator+(const Point& lts, const Point& rts);
};

Point operator+(const Point& lts, const Point& rts) {
	return lts.xpos + rts.xpos, lts.ypos + rts.ypos;
}

Point& operator++(Point& ref) {
	ref.xpos++;
	ref.ypos++;
	return ref;
}

Point& operator++(Point& ref, int) {
	Point tmp(ref);
	ref.xpos++;
	ref.ypos++;
	return tmp;
}

int main() {
	Point p1(1, 2);
	Point p2(3, 4);
	Point p3 = p1 + p2;
}