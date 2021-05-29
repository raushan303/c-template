#include <iostream>
using namespace std;
#include<bits/stdc++.h>
typedef long long ll;
#define md 1000000007
#define INF -500000000000000000

const ll N=1<<18;

class Segment {
public:
    ll max, push, l, r;

    Segment() : max(INF), push(0), l(-1), r(-1) {}

    Segment(ll value, ll l, ll r) : max(value), push(0), l(l), r(r) {}

};

Segment tree1[2 * N],tree[2*N],tree2[2*N],tree3[2*N];

void makePush(int v) {
    if (tree[v].push == 0) {
        return;
    }

    if (v < N) {
        tree[v * 2].push += tree[v].push;
        tree[v * 2 + 1].push += tree[v].push;
    }
    tree[v].max += tree[v].push;
    tree[v].push = 0;
}

void build(ll v,ll arr[],ll l,ll r) {
    
    if(l==r){
        tree[v].l=l;
        tree[v].r=r;
        tree[v].push=0;
      tree[v].max=arr[l];
    //   cout<<tree[v].max<<" ";
    //   cout<<l<<"\n";
      return;
    }
    
    build(v*2,arr,l,(l+r)/2);
    build(v*2+1,arr,(l+r)/2+1,r);
    tree[v].max=max(tree[v*2].max,tree[v*2+1].max);
    tree[v].l=l;
    tree[v].r=r;
    tree[v].push=0;
    // cout<<l<<" "<<r<<" "<<tree[v].max<<endl;
    return;
}
ll get(ll v, ll l, ll r) {
    makePush(v);

    if (tree[v].r <l || r <tree[v].l) {
        return INF;
    }
    if (l <= tree[v].l && tree[v].r <= r) {
        return tree[v].max;
    }

    return max(get(v * 2, l, r),get(v * 2 + 1, l, r));
}

void add(int v, int l, int r, int delta,int val) {
    makePush(v);

    if (tree[v].r <l || r <tree[v].l) {
        return;
    }
    if (l <= tree[v].l && tree[v].r <= r) {
        tree[v].push += (delta-val);
        makePush(v);
        return;
    }

    add(v * 2, l, r, delta, val);
    add(v * 2 + 1, l, r, delta, val);

    tree[v].max = max(tree[v * 2].max ,tree[v * 2 + 1].max);
}

void solve()
{
        ll n,q;
	    cin>>n>>q;
	    ll a[N+10];
	    ll suf[N+10];
	    for (int i = 0; i < N; ++i) 
        {
          suf[i] = INF;
          a[i]=0;
        }
	    for(int i=0;i<n;i++)
        {
	      cin>>a[i];
	      suf[i]=a[i];
	    }
	    for(int j=n-2;j>=0;j--)
	      suf[j]+=suf[j+1];
	      
	    build(1,suf,0,n-1); 
}