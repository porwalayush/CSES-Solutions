#include<bits/stdc++.h>
using namespace std;
const int N=200005;
list<int> gr[N];
int visited[N];
void dfs_helper(int cur)
{
	visited[cur]=1;
	for(auto nbr:gr[cur])
	{
		if(!visited[nbr])
			dfs_helper(nbr);
	}
}
void dfs(int v)
{
	int bridge=0;
	vector<int> q;
	for(int i=1;i<=v;i++)
	{
		if(!visited[i])
		{
			dfs_helper(i);
			bridge++;
			q.push_back(i);
		}
	}
	cout<<bridge-1<<endl;
	for(int i=1;i<q.size();i++)
	{
		cout<<q[i-1]<<" "<<q[i]<<endl;
	}

}
int main()
{
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	memset(visited,0,sizeof(visited));
	dfs(v);
	return 0;
}