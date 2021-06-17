#include<bits/stdc++.h>
using namespace std;
static int dp[10001];
int solve(int n)
{
	if(n<=0)
		return 0;
	else if(dp[n]!=-1)
			return dp[n];
	else
	{
		int t=0;
		for(int i=1;i<=6;i++)
		{
			if(n>=i)
			 t=t+(solve(n-i)+1);
		}
		return dp[n]=t;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	memset(dp,0,sizeof(dp));
    // solve(n);
	for(int i=1;i<=n;i++)
	{
		int tot=0;
		for(int j=1;j<=6;j++)
		{
			if(i>=j)
			{
              tot=tot+(dp[i-j]+1);
			}
		}
		dp[i]=tot;
	}
	cout<<dp[1]<<dp[2]<<dp[3]<<endl;
    return 0;
}