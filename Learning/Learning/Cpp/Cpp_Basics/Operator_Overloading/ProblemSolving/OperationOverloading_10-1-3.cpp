//OperationOverLoading_10-1-2가 베이스
//Point 클래스에 대해서 다음 조건을 만족하는 형태로 ==연산자와 !=연산자를 오버로딩 해보자
/*
1.둘 다 전역함수의 형태로 오버로딩
2.연산 'pos1==pos2'의 결과로 모든 멤버의 값이 같다면 true, 그렇지 않다면 false 반환
3.연산 'pos1!=pos2'의 결과로 모든 멤버의 값이 같다면 false, 그렇지 않다면 true 반환
4.연산의 ==를 먼저 오버로딩 한 다음에, 이를 이용하는 형태로 != 연산자를 오버로딩
*/

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
	Point& operator+=(const Point &ref) //반환형이 참조형, Point& 아니면 변수 반환
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point &ref)
	{
		xpos-=ref.xpos;
		ypos-=ref.ypos;
		return *this;
	}
	friend Point operator-(const Point &pos1, const Point &pos2);
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
};

Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2)
{
	if(pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos)
		return true;
	return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
	return !(pos1==pos2); //오버로딩 된 == 연산자를 호출하고 있다.
	//pos1==pos2 : true : !(true) -> false
}

int main(void)
{
	Point pos1(10,20);
	Point pos2(3,4);
	Point pos3(5,7);
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	(pos1-pos2).ShowPosition(); //객체를 반환하므로 함수호출 가능
	(pos2+=pos3).ShowPosition(); //반환형이 참조형이므로 함수호출 가능
	if(pos2==pos3)
		cout<<"equal"<<endl;
	else
		cout<<"not equal"<<endl;
	
	(pos2-=pos3).ShowPosition(); //반환형이 참조형이므로 함수호출 가능
	
	if(pos2!=pos3)
		cout<<"not equal"<<endl;
	else
		cout<<"equal"<<endl;
	return 0;
	return 0;
}