#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T Max(T a, T b)
{
	return a>b ? a : b ;
}

template <>
char* Max(char* a,char* b)
{
	cout<<"char* Max<char*>(char* a, char* b)"<<endl;
	return strlen(a) > strlen(b) ? a : b ;
}

template <>
const char* Max(const char* a, const char* b)
{
	cout<<"const char* Max<const char*>(const char* a, const char* b)"<<endl;
	return strcmp(a,b) > 0 ? a : b;
}

int main(void)
{
	cout<< Max(11, 15)          <<endl;
	cout<< Max('T', 'Q')        <<endl;
	cout<< Max(3.5, 7.5)        <<endl;
	cout<< Max("Simple", "Best")<<endl; //문자열을 상수로 받음: 19행 Max함수 호출-> const char* a : const 상수
	
	char str1[]="Simple";
	char str2[]="Best";
	cout<< Max(str1, str2)      <<endl; //str1, str2 변수로 선언: 포인터형: char* -> 12행 Max함수 호출
	return 0;
}