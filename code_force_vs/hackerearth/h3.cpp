#include <iostream>
using namespace std;
#include<bits/stdc++.h>
typedef long long int ll;
#define int long long int
#define ff first
#define ss second
#define md 1000000007
#define md1 998244353 
#define pb push_back
#define in insert
#define mkp make_pair
#define f(i,yha,wha) for(ll i=yha;i<wha;i++)
#define rf(i,wha,yha) for(ll i=wha;i>=yha;i--)
#define f0(n) for(ll i=0;i<n;i++)
#define f1(n) for(ll i=1;i<=n;i++)
#define fg(i,yha,wha,gap) for(ll i=yha;i<wha;i+=gap)
#define mpll map<ll,ll>
#define len(p) (ll)p.size()
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mem(a,t) memset(a,t,sizeof(a))
#define endl "\n"
#define ar array
#define vl vector<ll>
#define vpll vector<pair<ll,ll>>
#define fill(arr,x) memset(arr,x,sizeof(arr))
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define mex 500005
#define lgn 20
vector<pair<int,int>> adj[mex];
int in[mex],out[mex],par[mex],sub[mex],heavy[mex],tym,val[mex];
int dp[mex][lgn],pos[mex],head[mex],curr,tree[5*mex];
int aux[mex];
inline int dfs(int u,int p)
{
    par[u]=dp[u][0]=p;
    in[u]=++tym;
    sub[u]++;
    int max_val=-1;
    for(int i=1;i<lgn;i++) 
		dp[u][i]=dp[dp[u][i-1]][i-1];
    for(int i=0;i<sz(adj[u]);i++)
	{
        int v=adj[u][i].ff;
        if(v==p) 
			continue;
		val[v]=adj[u][i].ss;
        int x=dfs(v,u);
        if(x>max_val)
		{
            max_val=x;
            heavy[u]=v;
        }
        sub[u]+=x;
    }
    out[u]=tym;
    return sub[u];
}

inline bool check(int u,int v)
{
    return (in[u]<=in[v] && out[u]>=out[v]);
}

inline int lca(int u,int v)
{
    if(check(u,v)) return u;
    if(check(v,u)) return v;
    for(int i=lgn-1;i>=0;i--){
        if(!check(dp[u][i],v)) u=dp[u][i];
    }
    return dp[u][0];
}

inline void decompose(int u,int h)
{
//	if(u!=0)
    pos[u]=curr++;

    head[u]=h;
    if(heavy[u]!=-1) 
    {
    	decompose(heavy[u],h);
	}
		
    for(int i=0;i<sz(adj[u]);i++)
	{
        int v=adj[u][i].ff;
        if(v==par[u] || v==heavy[u]) continue;
        decompose(v,v);
    }
}

inline ll build(int u,int s,int e)
{
    if(s==e){
        tree[u]=aux[s];
        return tree[u];
    }
    int m=(s+e)/2;
    ll x=build(2*u+1,s,m);
    ll y=build(2*u+2,m+1,e);
    return tree[u]=(x+y)%md;
}

inline int que(int u,int s,int e,int l,int r)
{
    if(s>r || e<l) return 0;
    if(s>=l && e<=r) return tree[u];
    int m=(s+e)/2;
    return (que(2*u+1,s,m,l,r)+que(2*u+2,m+1,e,l,r))%md;
}

inline int query(int u,int v,int n)
{
    int x=0;
    while(head[u]!=head[v])
	{
        x=(x+que(0,0,n-1,pos[head[v]],pos[v]))%md;
        // x%=md;
        v=par[head[v]];
    }
    x=(x+que(0,0,n-1,pos[u],pos[v]))%md;
    // x%=md;
    return x;
}



inline void update(int u,int s,int e,int l,int r)
{
    if(s>r || e<l) return;
    if(s>=l && e<=r) 
    {
    	tree[u]=(tree[u]*2)%md;
    	return;
	}
		
    int m=(s+e)/2;
    update(2*u+1,s,m,l,r);
    update(2*u+2,m+1,e,l,r);
    tree[u]=(tree[2*u+1]+tree[2*u+2])%md;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	cout.tie(NULL);
    int n,q; 
	cin>>n>>q;
    for(int i=0;i<n-1;i++)
	{
        ll u,v,w; 
		cin>>u>>v>>w;
        w%=md;
//        cout<<w<<endl;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
//    ll c1=384389743398;
//    ll c2=1000000007;
//    cout<<c1%c2<<endl;

    fill(heavy,-1);
    dfs(0,0);
    decompose(0,0);
    
  
    for(int i=0;i<n;i++) 
		aux[pos[i]]=val[i]%md;
//	f(i,0,n)
//	  cout<<aux[i]<<" ";
//	  cout<<endl;
    build(0,0,n-1);
    ll ans=0;
    while(q--)
	{
        int u,v,typ;
        cin>>typ>>u;
		if(typ==1)
		{
			cin>>v;
	        int x=lca(u,v);
	        int a=query(x,u,n),b=query(x,v,n);
//	        cout<<a<<" "<<b<<" "<<val[x]<<endl;
	        ans=(a+b-2*val[x]+2*md)%md;
            
	        cout<<ans<<endl;
    	}
    	else
    	{
    		for(auto it:adj[u])
    		{
    			if(it.ff==par[u])
                {
                    val[u]=(2*val[u])%md;
    			    update(0,0,n-1,pos[u],pos[u]);
                }
    			else
                {
                    val[it.ff]=(2*val[it.ff])%md;
    			    update(0,0,n-1,pos[it.ff],pos[it.ff]);
                }
			}
		}
    }
}

//0 1 1
//0 6 2
//1 2 5
//1 3 3
//3 4 6
//3 5 7
//5 9 2
//9 10 3
//9 11 7
//6 7 4
//7 8 11
