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
	printf("%f\n", M_PI);
	answ_ = (powl(y_, x_ + 1)/(powl(fabsl(y_ - 2), 1/3.0) + 3)) + (((x_ + y_/2)/(2*fabsl(x_ + y_))) * powl(x_ + 1, -1/sinl(z_)));
}

int main() {
	Equation eq;
	eq.setX(1.23);
	eq.setY(15.4);
	eq.setZ(252);
	eq.Run();
	eq.print();
}