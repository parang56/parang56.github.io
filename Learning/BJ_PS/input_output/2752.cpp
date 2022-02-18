#include <bits/stdc++.h>
using namespace std;
int arr[4];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

/*
	int a, b, c;
	cin>>a>>b>>c;
 	int d, e, f;
	d = min({a,b,c});
	f = max({a,b,c});
	e = a+b+c-d-f;
	cout<<d<<' '<<e<<' '<<f;
*/
	/*
	for(int i=0;i<3;i++)
		cin>>arr[i];
	for(int i=0;i<2;i++)
		for(int j=0;j<2-i;j++)
			if(arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
	for(int i=0;i<3;i++)
		cout<<arr[i]<<' ';
	*/
	int arr[4];
    for(int i=0;i<3;i++)
    	cin>>arr[i];
    sort(arr, arr+3);
    for(int i=0;i<3;i++)
 	    cout<<arr[i]<<" ";
	
	return 0;
}