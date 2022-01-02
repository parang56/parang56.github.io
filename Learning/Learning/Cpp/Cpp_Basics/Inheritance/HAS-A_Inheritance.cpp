#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet; //장전된 총알의 수
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shot()
	{
		cout<<"BBANG!"<<endl;
		bullet--;
	}
};

class Police : public Gun
{
private:
	int handcuffs; // 소유한 수갑의 수
public:
	Police(int bnum, int bcuff)
		: Gun(bnum), handcuffs(bcuff)
	{ }
	void PutHandCuff()
	{
		cout<<"SNAP!"<<endl;
		handcuffs--;
	}
};

int main(void)
{
	Police pman(5,3); //총알5, 수갑3
	pman.Shot();
	pman.PutHandCuff();
	return 0;
}