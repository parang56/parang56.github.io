#include <stdio.h>

//선언
void p(int num);

void function_without_return();
int function_with_return();
void function_without_params();
void function_with_params(int num1,int num2,int num3);

int apple(int total, int ate); //전체 total개에서 ate개수 만큼 먹고 남은 수를 반환

int add(int num, int num2);
int sub(int num, int num2);
int mul(int num, int num2);
int div(int num, int num2);


int main_function(void)
{
	//function
	//계산기
/*	int num=2;
	p(num);
	
	num+=3;
	p(num);
	
	num *=3;
	p(num);
	
	num /= 6;
	p(num);*/
	
	//함수 종류
	//반환값이 없는 함수
	//function_without_return();
	
	//반환값이 있는 함수
	/*int ret = function_with_return();
	p(ret);*/
	
	// 파라미터(전달값)가 없는 함수
	//function_without_params();
	
	// 파라미터(전달값)가 있는 함수
	//function_with_params(1, 2, 3);
	
	// 파라미터(전달값)도 받고, 반환값이 있는 함수
	//int ret = apple(5,2); //5개의 사과 중에 2개를 먹었어요
	//printf("사과 5개 중에 2개를 먹으면 %d개가 남아요\n",ret);
	//printf("사과 %d개 중에 %d개를 먹으면? %d개가 남아요\n", 10, 4, apple(10,4));



	//계산기 함수
	int num=2;
	num = add(num,3);
	p(num);
	
	num = sub(num,1);
	p(num);
	
	num = mul(num,3);
	p(num);
	
	num = div(num,6);
	p(num);
	
	return 0;
}


//정의
void p(int num)
{
	printf("num은 %d입니다\n", num);
}

/*전달값 : 36
함수 : ㅁ + 4
반환형 : int, double, float, void

반환형 함수이름(전달값)
{
	
}*/

void function_without_return()
{
	printf("반환값이 없는 함수입니다\n");
}

int function_with_return()
{
	printf("반환값이 있는 함수입니다\n");
	return 10;
}

void function_without_params()
{
	printf("전달값이 없는 함수입니다\n");
}

void function_with_params(int num1,int num2,int num3)
{
	printf("전달값이 있는 함수이며, 전달 받은 값은 %d, %d, %d입니다\n", num1, num2 ,num3);
}

int apple(int total, int ate)
{
	printf("전달값과 반환값이 있는 함수입니다.");
	return total - ate;
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul(int num1, int num2)
{
	return num1 * num2;
}

int div(int num1, int num2)
{
	return num1 / num2;
}