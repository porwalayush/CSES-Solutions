#include<bits/stdc++.h>
using namespace std;
# define int long long
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
bool visited[1000][1000];

int solver(char a[][1000],int n,int m,int x,int y)
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
void solve(char a[][1000],int n,int m,int x,int y)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
            visited[i][j]=false;
		}
	}
	solver(a,n,m,x,y);
}
int32_t main()
{
	
    int n,m,x,y;
    cin>>n>>m;
    char a[1000][1000];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin>>a[i][j];
    		if(a[i][j]=='A')
    			{
                   x=i;
                   y=j;
    			}
    	}
    }
    solve(a,n,m,x,y);
	return 0;
}