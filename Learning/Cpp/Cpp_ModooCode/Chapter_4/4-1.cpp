#include <iostream>
using namespace std;

class Date
{
private:
	int year, month, day;
public:
	int getMonthsMaxDay(int year, int month) const //cosnt 멤버 함수
	{
		int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		if(month==2)
		{
			if((year%4)==0&&(year%100)==0)
			{
				months[1]=29;
			}
		}
	return months[month-1];
	}
	
	/* void setDate(int year, int month, int day)
	{
		if(getMonthsMaxDay(year,month)<day||month>12)
		{
			cout<<"Error! Invalid Date!"<<endl;
			return;
		}
		
		year=year;
		month=month;
		day=day;
		cout<<"Date Set!"<<endl;
	}*/
	
	Date(int _year, int _month, int _day): year(_year),month(_month),day(_day)
	{
		if(getMonthsMaxDay(year,month)<day||month>12)
		{
			cout<<"Error! Invalid Date!"<<endl;
			return;
		}
		cout<<"Date Set!"<<endl;
	}
	
	void addDay(int add)
	{
		day+=add-1;
		while(day>getMonthsMaxDay(year,month))
		{
			day-=getMonthsMaxDay(year,month);
			addMonth(1);
		}
	}
	void addMonth(int add)
	{
		month+=add;
		while(month>12)
		{
			month-=12;
			addYear(1);
		}
	}
	void addYear(int add)
	{
		year+=add;
	}
	void showDate()
	{
		cout<<"Now Date() : "<<year<<"년 "<<month<<"월 "<<day<<"일"<<endl;
	}
};

int main(void)
{
	/*Date date; 
	date.setDate(2022,01,15);*/
	Date date(2012,01,15);
	date.addDay(299);
	date.showDate();
}