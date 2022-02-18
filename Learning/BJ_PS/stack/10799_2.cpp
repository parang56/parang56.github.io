#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> S;
	string input;
	int sum = 0;
	cin>>input;
	for(int i=0; i<input.length(); i++) 
	{
		if(input[i] == '(')
		{
			if(input[i+1]==')')
			{
				sum += S.size();
				i++;
			}
			else
				S.push(input[i]);
		}
		else 
		{
			S.pop();
			sum++;
		}
	}
	cout<<sum<<'\n';
	
	return 0;
}