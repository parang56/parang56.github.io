#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> tower;
long long ans, height;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>N;
	for(int i=1; i<=N; i++)
	{
		cin>>height;
		
		//볼 수 없는 옥상이면 pop
		while(!tower.empty() && tower.top() <= height)
			tower.pop();
		
		//볼 수 있는 옥상이면 push
		tower.push(height);
		ans += tower.size()-1;
	}
	
	cout<<ans<<'\n';
	
	return 0;
}