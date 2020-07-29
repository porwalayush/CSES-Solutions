#include<bits/stdc++.h>
using namespace std;
# define int long long
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
bool visited[1000][1000];
void solver(char a[][1000],int n,int m,int x,int y)
{
	if(x>=n || y>=m)
		return;
	if(x<0 || y<0)
		return;
	if(a[x][y]=='#')
		return;
	visited[x][y]=true;
	for(int i=0;i<4;i++)
	{
       if(!visited[x+dx[i]][y+dy[i]])
       {
       	solver(a,n,m,x+dx[i],y+dy[i]);
       }
	}
}
void solve(char a[][1000],list<pair<int,int>> l,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
            visited[i][j]=false;
		}
	}
	int cnt=0;
	for(auto it:l)
	{
		if(!visited[it.first][it.second])
		{
			cnt++;
			solver(a,n,m,it.first,it.second);
		}
	}
	cout<<cnt;
}
int32_t main()
{
	
    int n,m;
    cin>>n>>m;
    char a[1000][1000];
    list<pair<int,int>> l;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin>>a[i][j];
    		if(a[i][j]=='.')
    			l.push_back(make_pair(i,j));
    	}
    }
    solve(a,l,n,m);
	return 0;
}