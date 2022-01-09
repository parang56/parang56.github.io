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
	friend Point operator+(const Point &pos1, const Point &pos2); //18행의 함수에 대해 private 영역의 접근을 허용하기 위해서 friend 선언
};

Point operator+(const Point &pos1, const Point &pos2) // + 연산자를 전역함수의 형태로 오버로딩. friend선언으로 private 멤버에 접근 가능.
{
	Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(3,4);
	Point pos2(10,20);
	Point pos3=pos1+pos2;
	
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}