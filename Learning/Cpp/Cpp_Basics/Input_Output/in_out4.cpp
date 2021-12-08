#include <iostream>

int main()
{
	int total,money;
	while(1){
		std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin>>money;
		if(money==-1){
			std::cout<<"프로그램을 종료합니다\n";
			break;
		}
		total = 50 + money*(0.12);
		std::cout<<"이번 달 급여: "<<total<<std::endl;
	}
	return 0;
}