#include <bits/stdc++.h>
using namespace std;

int getmax(int& n1, int& n2, int& n3)
{
	if((n1 >= n2) && (n1 >= n3))
        return n1;
    else if ((n2 >= n1) && (n2 >= n3))
        return n2;
    return n3;
}

int getsame(int& n1, int& n2, int& n3)
{
	if(n1==n2 && n1!=n3 && n2!=n3)
		return n1;
	if(n1==n3 && n2!=n3 && n1!=n2)
		return n1;
	if(n2==n3 && n1!=n2 && n1!=n3)
		return n2;
	return 0;
}

int solution(int& n1, int& n2, int& n3)
{
	int cnt,max,same;
	if(n1==n2)
		cnt++;
	if(n1==n3)
		cnt++;
	if(n2==n3)
		cnt++;
	switch(cnt)
	{
		case 0:
			max=getmax(n1,n2,n3);
			return max*100;
		case 1:
			same=getsame(n1,n2,n3);
			return 1000+same*100; 
		case 3:
			return 10000+n1*1000;
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	int a,b,c;
	cin>>a>>b>>c;
	cout<<solution(a,b,c)<<'\n';
	return 0;
}