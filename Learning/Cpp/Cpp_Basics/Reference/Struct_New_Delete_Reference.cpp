#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *pptr=new Point; // 2.함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가?
	pptr->xpos=p1.xpos+p2.xpos;
	pptr->ypos=p1.ypos+p2.ypos;
	return *pptr;
}

int main(void)
{
	Point *pptr1=new Point;
	pptr1->xpos=3;
	pptr1->ypos=30;
	
	Point *pptr2=new Point;
	pptr1->xpos=70;
	pptr1->ypos=7;
	
	Point &pref=PntAdder(*pptr1, *pptr2); // 1.동적할당 한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가 ?
	cout<<"["<<pref.xpos<<", "<<pref.ypos<<"]"<<endl;
	
	delete pptr1;
	delete pptr2;
	delete &pref;
	return 0;
}