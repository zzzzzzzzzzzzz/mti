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
	answ_(2*sqrt(3))
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
	answ_ = (2*cosl(x_ - M_PI/6)/(0.5 + sinl(y_)*sinl(y_)))*(1 + (z_*z_)/(3-(z_*z_)/5));
}

int main() {
	Equation eq;
	eq.setX(14.26);
	eq.setY(-1.22);
	eq.setZ(0.035);
	eq.Run();
	eq.print();
}