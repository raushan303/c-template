#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second

#define MAXN 1000005
#define level 18


vector<ll>v[MAXN];
ll depth[MAXN];
ll parent[MAXN][level];

void dfs(ll cur, ll prev)
{
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    ll sz = v[cur].size();
    for (ll i = 0; i < sz; i++)
    {
        if (v[cur][i] == prev)
            continue;
        dfs(v[cur][i], cur);
    }
}

void precomputeSparseMatrix(ll n)
{
    for (ll i = 1; i < level; i++)
    {
        for (ll node = 1; node <= n; node++)
        {
            if (parent[node][i - 1] != -1)
                parent[node][i] =
                    parent[parent[node][i - 1]][i - 1];
        }
    }
}

ll lca(ll x, ll y)
{
    if (depth[y] < depth[x])
        swap(x, y);

    ll diff = depth[y] - depth[x];

    // Step 1 of the pseudocode
    for (ll i = 0; i < level; i++)
        if ((diff >> i) & 1)
            y = parent[y][i];

    // now depth[u] == depth[v]
    if (x == y)
        return x;

    // Step 2 of the pseudocode
    for (ll i = level - 1; i >= 0; i--)
        if (parent[x][i] != parent[y][i])
        {
            x = parent[x][i];
            y = parent[y][i];
        }

    return parent[x][0];
}


int msb(int x) {
    for (int i = 20; ~i; i--) {
        if (x & (1 << i)) {
            return i;
        }
    }
}


void solve()
{
    memset(parent, -1, sizeof(parent));
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    precomputeSparseMatrix(n);

    // for hth parent of any vextex node

    int h = par;
    while (h != 0) {
        int ms = msb(h);
        node = parent[node][ms];
        h ^= (1 << ms);
    }
    cout << node << endl;

}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

}
