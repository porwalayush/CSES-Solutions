#include<bits/stdc++.h>
using namespace std;
# define int long long
void update_range(int ss,int se,int s_tree[],int inc,int l ,int r,int v)
{
	if(l>se||r<ss)
		return;
	if(se==ss)
	{
		s_tree[v]=s_tree[v]+inc;
		return;
	}
	int m=(ss+se)/2;
	update_range(ss,m,s_tree,inc,l,r,v*2);
	update_range(m+1,se,s_tree,inc,l,r,v*2+1);
	s_tree[v]=min(s_tree[2*v],s_tree[2*v+1]);
	return;
}
void update(int ss,int se,int s_tree[],int inc,int ind,int v)
{
	if(ss>ind || se<ind)
		return;
	if(se==ss)
	{
		s_tree[v]=inc;
		return;
	}
	int m=(ss+se)/2;
	update(ss,m,s_tree,inc,ind,v*2);
	update(m+1,se,s_tree,inc,ind,v*2+1);
	s_tree[v]=(s_tree[2*v]+s_tree[2*v+1]);
	return;
}
int query(int ss,int se,int s_tree[],int qs,int qe,int v)
{
   if(qs>se || qe<ss)
   	return 0;
   if(qs<=ss && qe>=se)
   	return s_tree[v];
   int m=(ss+se)/2;
   int l=query(ss,m,s_tree,qs,qe,v*2);
   int r=query(m+1,se,s_tree,qs,qe,v*2+1);
   return (l+r);
}
void build(int a[],int i,int j,int v,int *s_tree)
{
	if(i==j)
	{
		s_tree[v]=a[i];
		return ;
	}
		
   int m=(i+j)/2;
   build(a,i,m,v*2,s_tree);
   build(a,m+1,j,v*2+1,s_tree);
   s_tree[v]=(s_tree[2*v]+s_tree[2*v+1]);
   return;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,q,a[200005];
	cin>>n>>q;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    int s_tree[4*n];
	build(a,0,n-1,1,s_tree);
	while(q--)
	{
		int d,l,r;
		cin>>d>>l>>r;
		if(d==2)
            cout<<query(0,n-1,s_tree,l-1,r-1,1)<<endl;
        else
        	update(0,n-1,s_tree,r,l-1,1);
	}
	return 0;
}