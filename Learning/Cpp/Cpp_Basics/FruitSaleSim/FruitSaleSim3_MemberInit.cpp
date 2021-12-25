#include <iostream>
using namespace std;

class FruitSeller
{
	private:
		const int APPLE_PRICE; //const 멤버변수도 이니셜라이저를 이용하면 초기화가 가능하다!
		int numOfApples;
		int myMoney;
	
	public:
		FruitSeller(int price, int num, int money) 
			:APPLE_PRICE(price),numOfApples(num),myMoney(money) //이니셜라이저 이용!
		{ }
		int SaleApples(int money)
		{
			if(money<0)
			{
				cout<<"오류! 판매를 취소합니다!";
				return 0;
			}
			int num=money/APPLE_PRICE;
			numOfApples-=num;
			myMoney+=money;
			return num;
		}
	void ShowSalesResult() const
	{
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<myMoney<<endl<<endl;
	}
};

class FruitBuyer
{
	private:
		int numOfApples;
		int myMoney;
	
	public:
		FruitBuyer(int money)
			: myMoney(money),numOfApples(0)
		{ }
		
		void BuyApples(FruitSeller &seller, int money)
		{
			if(money<0)
			{
				cout<<"오류! 구매를 취소합니다!"<<endl;
				return;
			}
			numOfApples+=seller.SaleApples(money);
			myMoney-=money;
		}
		void ShowBuyResult() const
		{
			cout<<"현재 잔액: "<<myMoney<<endl;
			cout<<"사과 개수: "<<numOfApples<<endl<<endl;
		}
};

int main(void)
{
	FruitSeller seller(1000,20,0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller,2000); //* 과일의 구매
	
	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult();
	return 0;
}