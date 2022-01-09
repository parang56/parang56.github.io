#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
	int xpos,ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}

typedef Point * POINT_PTR;

class BoundCheckPointPtrArray
{
private:
	POINT_PTR * arr;
	int arrlen;
	
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { } //28~29행 -> arr1=arr2 이런거 안하겠다.

public:
	BoundCheckPointPtrArray(int len) :arrlen(len)
	{
		arr=new POINT_PTR[len]; //저장의 대상이 Point 객체의 주소 값이기 때문에 POINT_PTR 배열을 생성하였다.
	}
	POINT_PTR& operator[] (int idx)
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR operator[] (int idx) const
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrlen() const { return arrlen; }
	~BoundCheckPointPtrArray() { delete []arr; }
};

int main(void)
{
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3,4); //Point 객체의 주소 값을 저장하고 있다. 이렇듯 객체의 주소 값을 저장할 경우, 깊은 복사냐 얕은 복사냐 신경 X
	arr[1] = new Point(5,6);
	arr[2] = new Point(7,8);
	
	for(int i=0; i<arr.GetArrlen();i++)
		cout<<*(arr[i]);
	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}