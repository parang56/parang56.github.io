#include <bits/stdc++.h>
using namespace std;

int freq[26]; //전역으로 선언 안하면 직접 선언해줘야함 -> 그냥 0으로 채워짐.
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin>>S;
	for(auto c : S) //auto c
		freq[c-'a']++;
	for(int i=0;i<26;i++)
		cout<<freq[i]<<' ';
}