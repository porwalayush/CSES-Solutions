#include<bits/stdc++.h>
using namespace std;
const int N=200005;
list<int> gr[N];
int visited[N+1];
int color[N+1];
int t=0;
void dfs_helper(int cur,int col)
{
	visited[cur]=1;
	color[cur]=col;
	for(auto nbr:gr[cur])
	{
      if(!visited[nbr])
      	dfs_helper(nbr,3-col);
      else
      {
      	if(color[nbr]==color[cur])
      	{
      		t=1;return;
      	}

      }
	}
}
void dfs(int v)
{
	int col=1;
	for(int i=1;i<=v;i++)
	{
		if(!visited[i])
		{
			dfs_helper(i,col);
			col++;
		}
	}
	if(col>3 || t==1)
		cout<<"IMPOSSIBLE"<<endl;
	else
	{

	for(int i=1;i<=v;i++)
		cout<<color[i]<<" ";
    }
}
int main()
{
	
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