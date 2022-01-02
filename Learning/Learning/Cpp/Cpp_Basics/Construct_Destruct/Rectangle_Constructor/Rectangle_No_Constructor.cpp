#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y; //정보은닉

public:
	bool InitMembers(int xpos, int ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos); //정보 은닉으로 추가되는 엑세스 함수들
};



bool Point::InitMembers(int xpos, int ypos)
{
	if(xpos<0 || ypos<0)
	{
		cout<<"벗어난 범위의 값 전달"<<endl;
		return false;
	}
	
	x=xpos;
	y=ypos;
	return true;
}

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
	bool InitMembers(const Point &ul, const Point &lr);
	void ShowRecInfo() const;
};



bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
	if(ul.GetX()>lr.GetX() || ul.GetY()>lr.GetY())
	{
		cout<<"잘못된 위치정보 전달"<<endl;
		return false;
	} //좌상단, 우하단 바뀌는 것 차단
	upLeft=ul;
	lowRight=lr;
	return true;
}



void Rectangle::ShowRecInfo() const
{
	cout<<"좌 상단: "<<'['<<upLeft.GetX()<<", "<<upLeft.GetY()<<']'<<endl;
	cout<<"우 하단: "<<'['<<lowRight.GetX()<<", "<<lowRight.GetY()<<']'<<endl;
}



int main(void)
{
	Point pos1;
	if(!pos1.InitMembers(-2,4)) //벗어난 범위의 값 전달
		cout<<"초기화 실패"<<endl;
	if(!pos1.InitMembers(2,4))
		cout<<"초기화 실패"<<endl;
	
	Point pos2;
	if(!pos2.InitMembers(5,9))
		cout<<"초기화 실패"<<endl;
	
	Rectangle rec;
	if(!rec.InitMembers(pos2,pos1))
		cout<<"직사각형 초기화 실패"<<endl;
	
	if(!rec.InitMembers(pos1,pos2))
		cout<<"직사각형 초기화 실패"<<endl;
	
	rec.ShowRecInfo();
	return 0;
}