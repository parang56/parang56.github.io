#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	/*void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}*/
	
	Point(int x, int y): xpos(x), ypos(y)
	{ }	
	
	void ShowPointInfo() const
	{
		cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
	}
};

class Circle
{
private:
	int rad;
	Point center;
	/*void Init(int x, int y, int r)
	{
		rad = r;
		center.Init(x,y);
	}*/
public:
	Circle(int x, int y, int r): center(x,y)
	{
		rad=r;
	}
	
	void ShowCircleInfo()
	{
		cout<<"radius: "<<rad<<endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle incircle;
	Circle outcircle;
/*
public:
	void Init(int x1, int y1, int r1, int x2, int y2, int r2
	{
		incircle.Init(x1,y1,r1);
		outcircle.Init(x2,y2,r2);
	}
*/
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2)
		:incircle(x1,y1,r1), outcircle(x2,y2,r2)
	{ }
	void ShowRingInfo()
	{
		cout<<"Inner Circle Info..."<<endl;
		incircle.ShowCircleInfo();
		cout<<"Outer Circle Info..."<<endl;
		outcircle.ShowCircleInfo();
	}
};

int main(void)
{
	/*
	Ring ring;
	ring.Init(1,1,4,2,2,9);
	*/
	Ring ring(1,1,4,2,2,9);
	ring.ShowRingInfo();
	return 0;
}