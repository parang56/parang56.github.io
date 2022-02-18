#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int N, height;
stack<pair<int,int>> Stack;
long long ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	
	while(N--)
	{
		cin>>height;
		int same_height_cnt=1;
		while(!Stack.empty() && Stack.top().first <= height)
		{
			ans += Stack.top().second;
			if(Stack.top().first == height)
				same_height_cnt += Stack.top().second;
			Stack.pop();
		}
		if(!Stack.empty())
			ans++;
		Stack.push({height, same_height_cnt});
	}
	
	cout<<ans<<'\n';
	
	return 0;
}