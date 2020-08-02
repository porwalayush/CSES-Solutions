#include<bits/stdc++.h>
using namespace std;
const int N=200005;
list<int> gr[N];
int dist[N+1];
int parent[N+1];
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	dist[s]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto nbr:gr[node])
		{
			if(dist[nbr]==INT_MAX)
			{
				q.push(nbr);
				dist[nbr]=dist[node]+1;
				parent[nbr]=node;
			}
		}
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
    for(int i=1;i<=N;i++)
    {
    	dist[i]=INT_MAX;
    }
    for(int i=1;i<=N;i++)
    {
    	parent[i]=INT_MAX;
    }
    bfs(1);
    if(dist[v]==INT_MAX)
    	cout<<"IMPOSSIBLE"<<endl;
    else
    {
    	vector<int> ans;
    	cout<<dist[v]<<endl;
    	int p=v;
    	ans.push_back(p);
    	while(p!=1)
    	{
    		ans.push_back(parent[p]);
    		p=parent[p];
    	}
    	int i=ans.size()-1;
    	for(;i>=0;i--)
    	{
    		cout<<ans[i]<<" ";
    	}
    }
	return 0;
}