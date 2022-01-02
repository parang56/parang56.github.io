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

class Police
{
private:
	int handcuffs; // 소유한 수갑의 수
	Gun *pistol; //소유하고 있는 권총
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if(bnum>0)
			pistol=new Gun(bnum);
		else
			pistol=NULL; //총 소유하지 않는 것도 가능
	}
	Police(const Police& ref)
		:handcuffs(ref.handcuffs)
	{
		if(ref.pistol!=NULL)
			pistol=new Gun(*(ref.pistol)); //Gun의 복사 생성자 호출
		else
			pistol=NULL;
	}
	Police& operator=(const Police& ref)
	{
		if(pistol!=NULL)
			delete pistol;
		if(ref.pistol!=NULL)
			pistol=new Gun(*(ref.pistol));
		else
			pistol=NULL;
		
		handcuffs=ref.handcuffs;
		return *this;
	}
	void PutHandCuff()
	{
		cout<<"SNAP!"<<endl;
		handcuffs--;
	}
	void Shot()
	{
		if(pistol==NULL)
			cout<<"Hut BBANG!"<<endl;
		else
			pistol->Shot(); //Gun의 public Shot()과 Police의 public Shot() 구분이 어떻게??
	}
	~Police()
	{
		if(pistol!=NULL)
			delete pistol;
	}
};

int main(void)
{
	Police pman1(5,3); //총알5, 수갑3
	Police pman2=pman1; //복사 생성자 호출
	pman2.Shot();
	pman2.PutHandCuff();
	
	Police pman3(0,3); //권총을 소유하지 않은 경찰
	pman3.Shot();
	pman3.PutHandCuff();
	pman3=pman1; //대입 연산자의 호출
	pman3.Shot();
	pman3.PutHandCuff();
	return 0;
}