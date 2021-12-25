#include <iostream>
using namespace std;

class Date
{
private:
	int _year, _month, _day;
public:
	int getMonthsMaxDay(int year, int month) const
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
	
	Date(int year, int month, int day): _year(year),_month(month),_day(day)
	{
		if(getMonthsMaxDay(year,month)<day||month>12)
		{
			cout<<"Error! Invalid Date!"<<endl;
			return;
		}
		cout<<"Date Set!"<<endl;
	}
	
	/* void setDate(int year, int month, int day)
	{
		if(getMonthsMaxDay(year,month)<day||month>12)
		{
			cout<<"Error! Invalid Date!"<<endl;
			return;
		}
		
		_year=year;
		_month=month;
		_day=day;
		cout<<"Date Set!"<<endl;
	}*/
	
	void addDay(int add)
	{
		_day+=add;
		while(_day>getMonthsMaxDay(_year,_month))
		{
			_day-=getMonthsMaxDay(_year,_month);
			addMonth(1);
		}
	}
	void addMonth(int add)
	{
		_month+=add;
		while(_month>12)
		{
			_month-=12;
			addYear(1);
		}
	}
	void addYear(int add)
	{
		_year+=add;
	}
	void showDate()
	{
		cout<<"Now Date() : "<<_year<<"년 "<<_month<<"월 "<<_day<<"일"<<endl;
	}
};

int main(void)
{
	/*Date date; 
	date.setDate(2021,12,13);*/
	Date date(2021,12,13);
	date.addDay(331);
	date.showDate();
}