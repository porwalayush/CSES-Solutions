#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define for(i,s,n)		for(int i=s;i<n;i++)
 
 
void inputArray(int a[], int n){
	for(i,0,n){
		cin>>a[i];
	}
}
 
void outputArray(int a[], int n){
	for(i,0,n){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
 
void solve()
{
 
	w(t){
		
		int r,c;
		cin>>r>>c;
 
		int ans;
		if(c>r){
			if(c%2!=0){
				ans=(c*c)+1-r;
			}
			else{
				c--;
				ans=c*c+r;
			}
 
		}
		else{
			if(r%2!=0){
				r--;
				ans=r*r+c;
			}
			else
				ans=r*r-c+1;
		}
 
		cout<<ans<<endl;
	}
 
}
 
 
int32_t main()
{
 
	solve();
	return 0;
}
