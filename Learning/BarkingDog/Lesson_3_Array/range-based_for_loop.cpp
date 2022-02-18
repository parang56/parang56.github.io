#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	vector<int> v1 = {1,2,3,4,5,6};
	//c++11 부터만 지원!!
	for(int e : v1)
		cout<< e << ' ';
	
	return 0;
}

// 2. not bad
/*
for(int i=0; i<v1.size(); i++)
	cout<<v1[i] << ' ';
*/

// 3. **WRONG**
/*
for(int i=0;i<=v1.size()-1;i++)
	cout<<v1[i]<<' ';
*/

/*->3번 틀린 이유: vector의 size 메소드는 unsigned int 반환
따라서 만약 빈 벡터이면 unsigned int 0 에서 int 1을 빼서
unsigned int -1이 되므로 4294967295이 됨.