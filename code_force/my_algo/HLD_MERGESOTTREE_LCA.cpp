//https://discuss.codechef.com/t/christ02-editorial/58632
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fill(arr,x) memset(arr,x,sizeof(arr))
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define mex 100005
#define lgn 18
vector<int> adj[mex];
int in[mex],out[mex],par[mex],sub[mex],heavy[mex],tym;
int dp[mex][lgn],pos[mex],head[mex],curr;
vector<int> tree[5*mex];

inline int dfs(int u,int p)
{
    par[u]=dp[u][0]=p;
    in[u]=++tym;
    sub[u]++;
    int max_val=-1;
    for(int i=1;i<lgn;i++) dp[u][i]=dp[dp[u][i-1]][i-1];
    for(int i=0;i<sz(adj[u]);i++){
        int v=adj[u][i];
        if(v==p) continue;
        int x=dfs(v,u);
        if(x>max_val){
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
    pos[u]=curr++;
    head[u]=h;
    if(heavy[u]!=-1) decompose(heavy[u],h);
    for(int i=0;i<sz(adj[u]);i++){
        int v=adj[u][i];
        if(v==par[u] || v==heavy[u]) continue;
        decompose(v,v);
    }
}

inline vector<int> build(int u,int s,int e,int aux[])
{
    if(s==e){
        tree[u].pb(aux[s]);
        return tree[u];
    }
    int m=(s+e)/2;
    vector<int> x=build(2*u+1,s,m,aux);
    vector<int> y=build(2*u+2,m+1,e,aux);
    vector<int> v(sz(x)+sz(y));
    merge(all(x),all(y),v.begin());
    return tree[u]=v;
}

inline int que(int u,int s,int e,int l,int r,int x)
{
    if(s>r || e<l) return 0;
    if(s>=l && e<=r) return distance(tree[u].begin(),ub(all(tree[u]),x));
    int m=(s+e)/2;
    return que(2*u+1,s,m,l,r,x)+que(2*u+2,m+1,e,l,r,x);
}

inline int query(int u,int v,int l,int r,int n)
{
    int x=0,y=0;
    while(head[u]!=head[v]){
        x+=que(0,0,n-1,pos[head[v]],pos[v],l-1);
        y+=que(0,0,n-1,pos[head[v]],pos[v],r);
        v=par[head[v]];
    }
    x+=que(0,0,n-1,pos[u],pos[v],l-1);
    y+=que(0,0,n-1,pos[u],pos[v],r);
    return y-x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,q; cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fill(heavy,-1);
    dfs(0,0);
    decompose(0,0);
    int aux[n];
    for(int i=0;i<n;i++) aux[pos[i]]=arr[i];
    build(0,0,n-1,aux);
    int ans=0;
    while(q--){
        int u,v,l,r;
        cin>>u>>v>>l>>r;
        u=1+((u^ans)%n);
        v=1+((v^ans)%n);
        u--; v--;
        int x=lca(u,v);
        int a=query(x,u,l,r,n),b=query(x,v,l,r,n);
        if(arr[x]>=l && arr[x]<=r) ans=a+b-1;
        else ans=a+b;
        cout<<ans<<endl;
    }
}