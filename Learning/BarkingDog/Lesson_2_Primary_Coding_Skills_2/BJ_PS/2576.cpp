#include <bits/stdc++.h>
using namespace std;

int k,sum,minimum=100;

int main(void)
{
	for(int i=0;i<7;i++)
	{
		int tmp;
		cin>>tmp;
		if(tmp%2!=0)
		{
			k++;
			sum+=tmp;
			if(tmp<minimum)
				minimum=tmp;
		}
	}
	if(k<1)
		cout<<-1<<'\n';
	else
	{
		cout<<sum<<'\n';
		cout<<minimum<<'\n';
	}
	
	return 0;
}