//시간복잡도 O(N)
#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N)
{
	int occur[101] = {};
	for(int i=0;i<N;i++)
	{
		//이전에 나온 것이 이미 존재하면(배열 값이 1이면), return 1
		if(occur[100-arr[i]])
			return 1;
		//이전에 나온 것이 아니면, 나왔다고 체크 (배열 값 1로 check)
		occur[arr[i]] = 1;
	}
	return 0;
}

int main(void)
{
	int ex1[3] = {1,52,48};
	int ex2[2] = {50,42};
	int ex3[4] = {4,13,63,87};
	cout<<func2(ex1,3)<<'\n';
	cout<<func2(ex2,2)<<'\n';
	cout<<func2(ex3,4)<<'\n';
}