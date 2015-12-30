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
	answ_(0)
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
	answ_ = powl(fabsl(cosl(x_) - cosl(y_)), 1 + 2*sinl(y_)*sinl(y_)) * (1 + z_ + powl(z_,2)/2 + powl(z_,3)/3 + powl(z_,4)/4);
}

int main() {
	Equation eq;
	eq.setX(4000);
	eq.setY(-0.875);
	eq.setZ(-0.000475);
	eq.Run();
	eq.print();
}