//OperationOverLoading_10-1-1가 베이스
//Point 클래스에 대해서 다음 조건을 만족하는 형태로 +=연산자와 -=연산자를 오버로딩 해보자
/*
1.멤버함수 기반으로 오버로딩
2.연산 'pos1+=pos2'의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값만큼 멤버 별 증가
3.연산 'pos1-=pos2'의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값만큼 멤버 별 감소
4.연산의 결과로 값이 증가 및 감소한 pos1의 객체를 반환하도록(참조형으로 반환) 연산자 오버로딩
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
	friend Point operator-(const Point &pos1, const Point &pos2);
	
	Point & operator+=(const Point &ref) //멤버함수 기반+= & 참조형으로 반환
	{
		xpos += ref.xpos; //조건 2
		ypos += ref.ypos;
		return *this;
	}
	
	Point & operator-=(const Point &ref) //멤버함수 기반-= & 참조형으로 반환
	{
		xpos-=ref.xpos; //조건 3
		ypos-=ref.ypos;
		return *this; //자기 자신 반환(ref) //조건 4
	}
};

Point operator-(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(10,20);
	Point pos2(3,4);
	
	pos1.ShowPosition();
	pos2.ShowPosition();
	(pos1+=pos2).ShowPosition();
	(pos1-=pos2).ShowPosition();
	return 0;
}