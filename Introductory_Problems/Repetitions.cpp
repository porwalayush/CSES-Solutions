#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,s,n)        for(int i=s;i<n;i++)
void io()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

void solve()
{
 string str;
 cin>>str;
 char c=str[0];
 int ans=1,mx=0;
 for(int i=1;str[i];i++)
 {
  if(c==str[i])
  {
    ans++;
  }
  else
  {
    mx=max(mx,ans);
    c=str[i];
    ans=1;
  }
 }
 mx=max(mx,ans);
 cout<<mx<<endl;
} 


int32_t main()
{
    io();
    solve();
    return 0;
}