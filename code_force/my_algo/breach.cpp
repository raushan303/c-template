/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int Time;
const int mxn=1e5+10;
vector<int>adj[mxn];
int low[mxn];
int disc[mxn];
int ap[mxn];
// map<int,int>mp;
int cnt;
int cnta;
int sub[mxn];
int vis[mxn];
int n;
typedef long long ll;
#define md 1000000007 


ll minv(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    { 
        ll q = a / m,t = m; 
        m = a % m, a = t,t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
} 
void dfs(int u,int p)
{
    vis[u]=1;
    sub[u]=1;
    for(auto it:adj[u])
    {
         if(vis[it])
           continue;
         dfs(it,u);
         sub[u]+=sub[it];
    }



}


int dfsAP(int u, int p) 
{
  int children = 0;
  low[u] = disc[u] = ++Time;
  for (int& v : adj[u]) 
  {
    if (v == p) 
      continue; 
    if (!disc[v]) 
    { 
      children++;
      dfsAP(v, u); 
      if (disc[u] < low[v]) 
      {
            // cout<<u<<" "<<v<<endl;
            cnt+=1;
            if(sub[v]%2==0 and (n-sub[v])%2==0)
               cnta++;
      }
      low[u] = min(low[u], low[v]);
    } 
    else 
      low[u] = min(low[u], disc[v]); 
  }
  return children;
}




int main()
{
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);
    dfsAP(1,0);
//     for(int i=1;i<=n;i++)
//       cout<<sub[i]<<" ";
//       cout<<endl;
// cout<<cnt<<" "<<cnta<<endl;

    long long ans1=(cnta*minv(cnt,md))%md;
    long long ans2=((cnt-cnta)*minv(cnt,md))%md;

    cout<<ans1<<" "<<ans2;







}
