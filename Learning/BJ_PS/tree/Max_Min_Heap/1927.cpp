#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, temp;
// priority_queue의 기본형. 3개의 인자를 받으며, 마지막 인자가 greater일 경우 최소힙 less인 경우 최대힙이다.
priority_queue<int, vector<int>, greater<int>> q;

int main(void) 
{    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    while(N--) 
	{
        cin >> temp;
        
        if(temp == 0) 
		{
            if(q.size() == 0)
                cout << "0\n";
            else 
			{
                cout << q.top() << '\n';
            	q.pop();
            }
        }
        else
            q.push(temp);
    }
    
	return 0;
}