//https://atcoder.jp/contests/abc164/tasks/abc164_e


#include <bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE

#define V vector
#define P pair

using LL = long long;
#define FOR(i, x, y) \
    for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) \
    for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifndef ONLINE_JUDGE
#define dbg(x...)                             \
    do {                                      \
        cerr << "\033[32;1m" << #x << " -> "; \
        err(x);                               \
    } while (0)
void err() { cerr << "\033[39;0m" << endl; }
template <template <typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) {
    for (auto v : a) cerr << v << ' ';
    err(x...);
}
template <typename T, typename... A>
void err(T a, A... x) {
    cerr << a << ' ';
    err(x...);
}
#else
#define dbg(...)
#endif
#define sz(x) (int)x.size()

LL bin(LL a, LL b, LL p) {
    LL res = 1;
    a = (a % p + p) % p;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1) res = res * a % p;

    return res;
}

const int N = 65, M = 2505;

struct E {
    int to, w, cost;
    E(int to=0, int w=0, int cost=0):to(to), w(w), cost(cost) {}
};

LL dis[N][M + 50];
vector<E> G[N];

struct node {
    int u, s;
    LL t;
    node(int u=0, int s=0, LL t=0): u(u), s(s), t(t) {}
    bool operator > (const node &other) const {
        return t > other.t;
    }
};

int n, m, s;
int c[N], d[N];





void solve() {
    scanf("%d%d%d", &n, &m, &s);
    s = min(s, M-1);
    for (int i=0; i<m; ++i) {
        int u, v, a, b;
        scanf("%d%d%d%d", &u, &v, &a, &b);
        G[u].emplace_back(v, b, a);
        G[v].emplace_back(u, b, a);
    }

    for (int i=1; i<=n; ++i) {
        scanf("%d%d", &c[i], &d[i]);
    }

    for (int i=1; i<=n; ++i) {
        memset(dis[i], 0x3f3f3f3f, sizeof (dis[i][0]) * (M + 1));
    }

    dis[1][s] = 0;
    priority_queue<node, vector<node>, greater<node>> q;
    q.emplace(1, s, 0);
    while (!q.empty()) {
        auto now = q.top(); q.pop();
        int u = now.u, s = now.s;
        LL t = now.t;
        if (t > dis[u][s])
            continue;
        int ns = min(M-1, s + c[u]);
        if (dis[u][ns] > t + d[u]) {
            dis[u][ns]= t+ d[u];
            q.emplace(u, ns, dis[u][ns]);
        }

        for (const auto & e : G[u]) {
            int v = e.to, w = e.w, cost = e.cost;
            int ns = s - e.cost;
            if (ns >= 0 && dis[v][ns] > t + w) {
                dis[v][ns] = t + w;
                q.emplace(v, ns, dis[v][ns]);
            }
        }
    }

    for (int i=2; i<=n; ++i) {
        printf("%lld\n", *min_element(dis[i], dis[i] + M));
    }
}

int main() {

    // int t;
    // cin >> t;
    // while (t--) solve();

    solve();

    return 0;
}

