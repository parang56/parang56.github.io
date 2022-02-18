#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int N; 
	cin>>N;
	while(N--)
	{
		list<char> L;
		auto cursor = L.begin();
		cin>>s;
		for(auto c : s)
		{
			if(c == '<')
			{
				if(cursor != L.begin())
					cursor--;
			}
			else if(c == '>')
			{
				if(cursor != L.end())
					cursor++;
			}
			else if(c == '-')
			{
				if(cursor != L.begin())
				{
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else
				L.insert(cursor,c);
		}
		for(auto c : L)
			cout<<c;
		cout<<'\n';
	}
	
	return 0;
}