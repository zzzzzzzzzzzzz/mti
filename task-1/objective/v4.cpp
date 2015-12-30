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
	answ_(1)
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
	answ_ = powl(y_, powl(fabsl(x_), 1/3.0)) + powl(cosl(y_),3)* (fabsl(x_ - y_) * (1 + powl(sinl(z_),2)/sqrt(x_ + y_))/(x_/2 + expl(fabsl(x_ - y_))));
}

int main() {
	Equation eq;
	eq.setX(6.251);
	eq.setY(0.827);
	eq.setZ(25.001);
	eq.Run();
	eq.print();
}