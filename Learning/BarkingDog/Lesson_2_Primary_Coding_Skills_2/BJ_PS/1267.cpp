#include <bits/stdc++.h>
using namespace std;

int arr[10000],Y,M;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin>>N;
	
	for(int i=0;i<N;i++) cin>>arr[i];
	for(int i=0;i<N;i++) Y+=((arr[i]/30)+1)*10;
	for(int i=0;i<N;i++) M+=((arr[i]/60)+1)*15;
	
	if(Y!=M)
		Y>M ? cout << "M " << M : cout << "Y " << Y;
	if(Y==M)
		cout << "Y M " << Y;
	
	return 0;
}