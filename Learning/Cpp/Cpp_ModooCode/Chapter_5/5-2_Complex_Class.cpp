#include <iostream>
#include <cstring>

class Complex
{
private:
	double real,img;
	double get_number(const char* str, int from, int to) const;
public:
	Complex(double real, double img) : real(real), img(img) { }
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);
	
	//자기 자신을 리턴하는 이항 연산자는 멤버 함수로, 아니면 외부 함수로 정의
	
	//Complex operator+(const Complex& c) const;
	Complex& operator+=(const Complex& c);
	Complex& operator=(const Complex& c);
	
	void println() { std::cout<<"("<<real<<", "<<img<<")"<<'\n'; }
	
	//이제 이 함수는 Complex의 private 멤버 변수들에 접근할 수 있다.
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend Complex operator+(const Complex& a, const Complex& b);
};

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	os << "( " << c.real << " , " << c.img << " ) ";
	return os;
}

Complex operator+(const Complex& a, const Complex& b)
{
	Complex temp(a.real + b.real, a.img + b.img);
	return temp;
}

Complex::Complex(const char* str)
{
    // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
    // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
    // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
    int pos_i = -1;
    for (int i = 0; i != end; i++)
	{
        if (str[i] == 'i')
	    {
        	pos_i = i;
            break;
        }
    }

    // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
    if (pos_i == -1)
    {
        real = get_number(str, begin, end - 1);
    	return;
    }

    // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

double Complex::get_number(const char* str, int from, int to) const {
	//atof를 이용한 get_number 짧게 쓰기
	char * temp=new char[to-from+1];
    strncpy(temp,str+from, to-from+1); //str+from은 str로부터 from 떨어진곳부터 복사를 하기 위해서 
    double ret_value=atof(temp);
    delete[] temp;
    return ret_value;
}

Complex& Complex::operator+=(const Complex& c)
{
	(*this) = *this + c;
	return *this;
}

Complex& Complex::operator=(const Complex& c)
{
	real = c.real;
	img = c.img;
	return *this;
}

int main(void)
{
	Complex a(0, 0);
    a = "-1.1 + i3.923" + a;
    std::cout << "a의 값은: "<<a<< "이다." << '\n';
	return 0;
}