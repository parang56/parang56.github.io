#include <iostream>
void swap(int* num1,int* num2); //넣어도 되고 안 넣어도 됨 (num1,num2)
void swap(char*,char*);
void swap(double*,double*);
int main(void)
{
	int num1 =20,num2=30;
	swap(&num1,&num2);
	std::cout<<num1<<' '<<num2<<std::endl;
	
	char ch1='A',ch2='Z';
	swap(&ch1,&ch2);
	std::cout<<ch1<<' '<<ch2<<std::endl;
	
	double dbl1=1.111, dbl2=5.555;
	swap(&dbl1,&dbl2);
	std::cout<<dbl1<<' '<<dbl2<<std::endl;
	
	return 0;
}

void swap(int *num1, int *num2)
{
	int temp;
	temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}

void swap(char *ch1,char *ch2)
{
	char temp;
	temp = *ch2;
	*ch2 = *ch1;
	*ch1 = temp;
}

void swap(double *dbl1,double *dbl2)
{
	double temp;
	temp = *dbl2;
	*dbl2 = *dbl1;
	*dbl1 = temp;
}