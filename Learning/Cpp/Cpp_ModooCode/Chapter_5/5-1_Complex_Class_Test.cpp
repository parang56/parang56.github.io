#include <iostream>

class Complex
{
private:
	double real,img;
	
public:
	Complex(double real, double img) : real(real), img(img)
	{ }
	Complex(const Complex& c)
	{ real = c.real, img = c.img; }
	
	Complex& operator+(const Complex& c);
	Complex& operator-(const Complex& c);
	
	void println()
	{
		std::cout<<"("<<real<<", "<<img<<")"<<'\n';
	}
};

Complex& Complex::operator+(const Complex& c)
{
	real += c.real;
	img += c.img;
	return *this;
}

Complex& Complex::operator-(const Complex& c)
{
	real -= c.real;
	img -= c.img;
	return *this;
}

int main(void)
{
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);
	
	Complex c = a + b + a; //우리가 생각하는 답은 (5,2)
	//하지만 (a+b)+(a+b)가 되서 (8,0)이 된다.
	c.println();
	
	return 0;
}