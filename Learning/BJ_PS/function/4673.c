#include <stdio.h>

int add1(int n);
int add2(int n);
int add3(int n);
int add4(int n);

int main()
{
    int arr[10000] = {0};
	
	for(int i=0;i<10000;i++){
		arr[i]=i+1;
	}
	
	for(int i=0;i<10000;i++){
		for(int j=1; j<10;j++){
			if(arr[i]==add1(j)){
				arr[i]='\0';
			}	
		}
	} //d(1)~d(9)
	
	for(int i=0;i<10000;i++){
		for(int j=10; j<100;j++){
			if(arr[i]==add2(j)){
				arr[i]='\0';
			}	
		}
	} //d(10)~d(99)
	
	for(int i=0;i<10000;i++){
		for(int j=100; j<1000;j++){
			if(arr[i]==add3(j)){
				arr[i]='\0';
			}	
		}
	} //d(100)~d(999)
	
	for(int i=0;i<10000;i++){
		for(int j=1000; j<=10000;j++){
			if(arr[i]==add4(j)){
				arr[i]='\0';
			}	
		}
	} //d(1000)~d(10000)
	
	for(int i=0;i<10000;i++){
		if(arr[i]!='\0'){
			printf("%d\n",arr[i]);
		}
	}
	
    return 0;
} 
int add1(int n){
	int a = n+n;
	return a;
}
int add2(int n){
	int a = n/10;
	int b = n%10;
	int c = n + a + b;
	return c;
}
int add3(int n){
	int a = n/100;
	int b = (n-100*a)/10;
	int c = n%10;
	int d = n + a + b + c;
	return d;
}
int add4(int n){
	int a = n/1000;
	int b = (n-1000*a)/100;
	int c = (n-1000*a-100*b)/10;
	int d = n%10;
	int e = n + a + b + c + d;
	return e;
}