#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin>>S;
	for(char i='a';i<='z';i++)
	{
		int cnt=0;
		for(char c : S) //auto c
			if(i==c)
				cnt++;
		cout<<cnt<<' ';
	}
}