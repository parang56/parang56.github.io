#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int parent[MAX];
int visited[MAX];
vector<int> tree[MAX];

void dfs(int now)
{
    visited[now] = 1;

    for(int i=0 ; i<tree[now].size(); i++)
	{
		int next=tree[now][i];
        if(!visited[next]){
            parent[next] = now;
            dfs(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i=0; i<N-1; i++)
	{
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b); //adj
        tree[b].push_back(a);
    }
	
    dfs(1);

    for(int i=2; i<=N; i++)
        cout<<parent[i]<<"\n";
}