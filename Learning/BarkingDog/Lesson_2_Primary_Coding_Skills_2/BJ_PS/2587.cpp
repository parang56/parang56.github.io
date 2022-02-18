#include <bits/stdc++.h>
using namespace std;

int arr[5];
int sum;

int main(void)
{
	ios::sync_with_stdio(0);
  	cin.tie(0);
	
	for(int i=0;i<5;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	cout<<sum/5<<'\n';
	sort(arr,arr+5);
	cout<<arr[2];
	
	return 0;
}