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
 
	int n,pre,cur;
	cin>>n>>pre;
	n--;
	int steps=0;
	while(n--){
		cin>>cur;
		if(pre>cur)
			steps+=(pre-cur);
 
		else
			pre=cur;
	}
 
 
 
	cout<<steps<<endl;
	
 
 
}
 
 
 
int32_t main()
{
 
	solve();
	return 0;
}
