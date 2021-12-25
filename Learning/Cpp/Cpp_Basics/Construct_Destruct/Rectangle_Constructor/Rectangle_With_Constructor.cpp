#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y; //정보은닉

public:
	Point(const int &xpos, const int &ypos): x(xpos), y(ypos)
	{ }
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos); //정보 은닉으로 추가되는 엑세스 함수들
};

/*Point::Point(const int &xpos,const int &ypos)
{
	x=xpos;
	y=ypos;
}*/ //줄여서 11행 :x(xpos), y(ypos){ }로 옮김

int Point::GetX() const
{
	return x;
}

int Point::GetY() const
{
	return y;
}

bool Point::SetX(int xpos)
{
	if(0>xpos || xpos>100)
	{
		cout<<"벗어난 범위의 값 전달"<<endl;
		return false;
	}
	x=xpos;
	return true;
}

bool Point::SetY(int ypos)
{
	if(0>ypos || ypos>100)
	{
		cout<<"벗어난 범위의 값 전달"<<endl;
		return false;
	}
	y=ypos;
	return false;
}



class Rectangle
{
private:
	Point upLeft;
	Point lowRight;
	
public:
	Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
		:upLeft(x1,y1),lowRight(x2,y2)
	{ }
	void ShowRecInfo() const;
};

void Rectangle::ShowRecInfo() const
{
	cout<<"좌 상단: "<<'['<<upLeft.GetX()<<", "<<upLeft.GetY()<<']'<<endl;
	cout<<"우 하단: "<<'['<<lowRight.GetX()<<", "<<lowRight.GetY()<<']'<<endl;
}

int main(void)
{
	Rectangle rec(1,1,5,5);
	rec.ShowRecInfo();
	return 0;
}