#include <math.h>
#include <stdio.h>

class Equation {
private:
	long double x_,y_,z_,answ_;
public:
	Equation();
	~Equation();
	void setX(long double x);
	void setY(long double y);
	void setZ(long double z);
	void print();
	void Run();
};

Equation::Equation():
	x_(0),
	y_(0),
	z_(0),
	answ_(-1)
{}

Equation::~Equation() {
	x_ = -1;
	y_ = -1;
	z_ = -1;
	answ_ = -1;
}

void Equation::setX(long double x) {
	x_ = x;
}

void Equation::setY(long double y) {
	y_ = y;
}

void Equation::setZ(long double z) {
	z_ = z;
}

void Equation::print() {
	fprintf(stdout, "x = %Lf\ny = %Lf\nz = %Lf\nanswer = %Lf\n", x_,y_,z_, answ_);
}

void Equation::Run() {
	answ_ = fabsl(powl(x_,y_/x_) - powl(y_/x_, 1/3.0)) + (y_ - x_) * ((cosl(y_) - z_/(y_ - x_)) /(1 + powl((y_ - x_),2)) );
}

int main() {
	Equation eq;
	eq.setX(182.5);
	eq.setY(18.225);
	eq.setZ(-0.03298);
	eq.Run();
	eq.print();
}