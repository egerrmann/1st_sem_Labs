#include <iostream>

using namespace std;

class Vector;
class Circle;
class Square;

class Point {
 public:
	double _x, _y;
	Point(double x, double y) : _x(x), _y(y) {}
};

class Visitor {
 public:
	virtual void VisitVector(Vector &vector) = 0;
	virtual void VisitCircle(Circle &circle) = 0;
	virtual void VisitSquare(Square &square) = 0;
};

class Figure {
 public:
	virtual void Accept(Visitor &v) = 0;

};

class Vector : Figure {
 public:
	Point _point;

	void Accept(Visitor &v) override {
		v.VisitVector(*this);
	}

	Vector(Point p) : _point(p) {}
};

class Circle : Figure {
 public:
	Point _centre;
	double _radius{};

	void Accept(Visitor &v) override {
		v.VisitCircle(*this);
	}

	Circle(Point p, double radius) : _centre(p), _radius(radius) {}
};

class Square : Figure {
 public:
	Point _a;
	Point _c;

	void Accept(Visitor &v) override {
		v.VisitSquare(*this);
	}

	Square(Point A, Point C) : _a(A), _c(C) {}
};

class ParallelTransfer : Visitor {
	Point _movingVector;

 public:
	ParallelTransfer(Point movingVector) : _movingVector(movingVector) {}

	void VisitVector(Vector &vector) override {
		vector._point._x += _movingVector._x;
		vector._point._y += _movingVector._y;
	}

	void VisitCircle(Circle &circle) override {
		circle._centre._x += _movingVector._x;
		circle._centre._y += _movingVector._y;
	}

	void VisitSquare(Square &square) override {
		square._a._x += _movingVector._x;
		square._a._y += _movingVector._y;
		square._c._x += _movingVector._x;
		square._c._y += _movingVector._y;
	}
};

class Scaling : Visitor {
	double coefficient;

 public:
	Scaling(double scale) : coefficient(scale) {}

	void VisitVector(Vector &vector) override {
		vector._point._x *= coefficient;
		vector._point._y *= coefficient;
	}

	void VisitCircle(Circle &circle) override {
		circle._radius *= coefficient;
	}

	void VisitSquare(Square &square) override {
		square._a._x *= coefficient;
		square._a._y *= coefficient;
		square._c._x *= coefficient;
		square._c._y *= coefficient;
	}
};

class Reflection : Visitor {
 public:
	void VisitVector(Vector &vector) override {
		vector._point._x *= -1;
		vector._point._y *= -1;
	}

	void VisitCircle(Circle &circle) override {
		circle._centre._x *= -1;
		circle._centre._y *= -1;
	}

	void VisitSquare(Square &square) override {
		square._a._x *= -1;
		square._a._y *= -1;
		square._c._x *= -1;
		square._c._y *= -1;
	}
};

int main()
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
