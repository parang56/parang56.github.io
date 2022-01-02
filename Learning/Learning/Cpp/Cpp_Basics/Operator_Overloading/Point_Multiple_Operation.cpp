#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
		{ }
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
	}
	Point operator*(int times) //곱셈 연산자 오버로딩, Point 객체와 정수간의 곱셈이 가능하게 되었다.
	{
		Point pos(xpos*times, ypos*times);
		return pos;
	}
};

int main(void)
{
	Point pos(1,2);
	Point cpy;
	
	cpy=pos*3; //pos.operator*(3) 으로 해석된다. 이렇게 해석이 되기 위해서는 Point 객체가 곱셈 연산자의 왼편에 있어야 한다.
	cpy.ShowPosition();
	
	cpy=pos*3*2;
	cpy.ShowPosition();
	return 0;
}