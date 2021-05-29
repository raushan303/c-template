///////////////////////////////////////////////////

/*
   * * * *    *     *   * * *      * *       * * *    * * *
   *      *   *   *     *    *   *     *    *        *
   * * * *    * *       * * *   *       *    * * *    * * *
   *     *    *   *     *    *   *     *          *        *
   *      *   *     *   * * *      * *       * * *    * * *
*/

///////////////////////////////////////////////////

#include"bits/stdc++.h"
using namespace std;

///////////////////////////////////////////////////

#define ll                long long
// #define int               long long

///////////////////////////////////////////////////

#define md                1000000007
#define md1               998244353
#define inf               9000000000000000000
#define minf              -1000000000000000

///////////////////////////////////////////////////

#define ff                first
#define ss                second
#define pll               pair<ll,ll>
#define mkp               make_pair

///////////////////////////////////////////////////

#define in                insert
#define mpll              map<ll,ll>

///////////////////////////////////////////////////

#define ar                array
#define mem(a,t)          memset(a,t,sizeof(a))
#define endl              "\n"

///////////////////////////////////////////////////

#define V                 vector
#define vl                vector<ll>
#define vvl               vector<vl>
#define vpll              vector<pair<ll,ll>>
#define pb                push_back
#define Pb                pop_back
#define be()              begin()
#define en()              end()
#define lb                lower_bound
#define ub                upper_bound
#define all(v)            v.begin(),v.end()
#define len(p)            (ll)p.size()

///////////////////////////////////////////////////

#define f(i,yha,wha)      for(ll i=yha;i<wha;i++)
#define rf(i,wha,yha)     for(ll i=wha;i>=yha;i--)
#define f0(n)             for(ll i=0;i<n;i++)
#define f1(n)             for(ll i=1;i<=n;i++)
#define fg(i,yha,wha,gap) for(ll i=yha;i<wha;i+=gap)


///////////////////////////////////////////////////

#define I                 cin>>
#define O                 cout<<

////////////////////////////////////////////////////

void flash()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

///////////////////////////////////////////////////

#ifndef ONLINE_JUDGE
#include"../debugger.h"
#else
#define dbg(x...)
#endif

////////////////////////////////////////////////////
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template < typename T > using indexed_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;

ll pwm(ll x, ll y)
{
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	ll ans = pwm(x, y / 2) % md;
	ans = (ans * ans) % md;
	if (y % 2 == 1)
		ans = (ans * x) % md;
	return ans;
}

struct DiffFenwick
{
	vector<ll> BIT;
	void reset(ll n)
	{
		BIT.resize(n + 5);
	}
	void add(int r, int value, ll n)
	{
		for (int i = r; i <= n; i = i | (i + 1))
			BIT[i] += value;
	}
	int qry(int r)
	{
		ll ans = 0;
		for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
			ans += BIT[i];
		return ans;
	}
};

struct Segtree {
	int N;
	vector<vector<int>> Tree;
	void init(int n) {
		N = n + 1;
		Tree.resize(4 * n + 10);
	}
	void build(vector<long long> &a, int node, int low, int high) {
		if (low == high) {
			Tree[node] = vector<int>(1, a[low]);
		} else {
			int mid = (low + high) / 2;
			build(a, node * 2, low, mid);
			build(a, node * 2 + 1, mid + 1, high);
			merge(Tree[node * 2].begin(), Tree[node * 2].end(), Tree[node * 2 + 1].begin(), Tree[node * 2 + 1].end(), back_inserter(Tree[node]));
		}
	}
	int query(int node, int low, int high, int l , int r, int x) {
		if (r < l) {
			return 0;
		}
		if (low == l && high == r) {
			auto k = lower_bound(all(Tree[node]), x);
			return (k == Tree[node].end() ? 0 : (int)Tree[node].size() - (k - Tree[node].begin()));
		}
		int mid = (low + high) / 2;
		return (query(2 * node, low, mid, l, min(mid, r), x) + query(2 * node + 1, mid + 1, high, max(l, mid + 1), r, x));
	}
};
struct Fenwick {
	vector<long long> BIT;
	int N;
	void init(int n) {
		N = n;
		BIT.resize(N + 1);
	}
	long long qry(int r) {
		long long ans = 0;
		for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
			ans += BIT[i];
		}
		return ans;
	}
	void reset() {
		for (int i = 0; i <= N; i++) {
			BIT[i] = 0;
		}
	}
	void add(int r, int value) {
		for (int i = r; i <= N; i = i | (i + 1)) {
			BIT[i] += value;
		}
	}

};
#define int long long
const int mod = (int)1e9 + 7;
void solve() {
	int n;
	cin >> n;
	vector<set<int>> v(n + 1);
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].insert(y);
		v[y].insert(x);
	}
	int q;
	cin >> q;

	if (n <= 1000 and q <= 1000) {
		vl h(n + 1, 0);
		vvl pos(n + 1, vl(n + 1, 1));
		DiffFenwick f, s[n + 2];
		f.reset(n);

		function<vl(ll, ll)> dfs = [&](ll u, ll p)->vl {
			h[u] = h[p] + 1;
			vl child;
			pos[u][u] = 0;
			for (auto it : v[u]) {
				if (it == p)
					continue;
				vl tmp = dfs(it, u);
				for (auto it : tmp) {
					child.pb(it);
					pos[u][it] = 0;
				}
			}
			child.pb(u);
			f.add(u, n - len(child), n);
			return child;
		};
		h[0] = -1;
		dfs(1, 0);
		vector<set<int>>done(n + 1);
		vvl height(n + 1);
		f(i, 1, n + 1) {
			s[i].reset(n);
			height[h[i]].pb(i);
			f(j, 1, n + 1) {
				if (pos[i][j]) {
					s[i].add(h[j], 1, n);
				}
			}
		}

		ll d = 0;
		ll tim = 1;
		while (q--) {
			ll e, c, x, y, h;
			cin >> e;
			c = e ^ d;
			// cout << c << endl;
			ll st = 1, en = n;
			while (st <= en) {
				ll mid = (st + en) / 2;
				ll cnt = f.qry(mid - 1);
				if (cnt >= c) {
					en = mid - 1;
				}
				else {
					x = mid;
					st = mid + 1;
				}
			}
			c -= f.qry(x - 1);
			st = 0, en = n - 1;
			while (st <= en) {
				ll mid = (st + en) / 2;
				ll cnt = s[x].qry(mid - 1);
				// cout << mid - 1 << " " << cnt << endl;
				if (cnt >= c) {
					en = mid - 1;
				}
				else {
					h = mid;
					st = mid + 1;
				}
			}
			c -= s[x].qry(h - 1);
			ll cnt = 0;
			for (auto it : height[h]) {
				if (!pos[x][it] or done[x].count(it))
					continue;
				cnt++;
				if (cnt == c) {
					y = it;
					break;
				}
			}
			done[x].in(y);
			s[x].add(h, -1, n);
			f.add(x, -1, n);
			// cout << x << " " << h << " " << y << endl;
			d = d + (pwm(2, tim) * x) % md + (pwm(3, tim) * y) % md;
			d %= md;
			tim++;
		}
		cout << d << endl;
	}
	else {
		vector<int> H(n + 1);
		vector<int> In(n + 1), Out(n + 1);
		int counter = 0;
		vector<int> child(n + 1);
		function<void(int, int)> dfs = [&](int x, int prev) {
			In[x] = ++counter;
			child[x] = 1;
			for (auto &i : v[x]) {
				if (i != prev) {
					H[i] = H[x] + 1;
					dfs(i, x);
					child[x] += child[i];
				}
			}
			Out[x] = counter;
		};
		H[1] = 1;
		dfs(1, 0);
		int bhut_bda_element = -1;
		for (auto it : H) {
			bhut_bda_element = max(bhut_bda_element, it);
		}
		vector<vector<array<int, 2>>> siblings(bhut_bda_element + 1);
		vector<vector<int>> sibilings_count(bhut_bda_element + 1), phir_koi_aane_wala_hain(bhut_bda_element + 1);
		for (int i = 1; i <= bhut_bda_element; i++) {
			siblings[i].push_back({ -1, -1});
			sibilings_count[i].push_back(-1);
			phir_koi_aane_wala_hain[i].push_back(-1);
		}
		for (int i = 1; i <= n; i++) {
			siblings[H[i]].push_back({In[i], i});
			sibilings_count[H[i]].push_back(i);
		}
		for (int i = 1; i <= bhut_bda_element; i++) {
			sort(all(siblings[i]));
			sort(all(sibilings_count[i]));
		}
		for (int i = 1; i <= bhut_bda_element; i++) {
			for (int j = 1; j < (int)sibilings_count[i].size(); j++) {
				phir_koi_aane_wala_hain[i].push_back(In[sibilings_count[i][j]]);
			}
		}
		vector<int> choraai(bhut_bda_element + 1), pref_choraai(bhut_bda_element + 1);
		for (int i = 1; i <= n; i++) {
			choraai[H[i]] += 1;
		}
		for (int i = 1; i <= bhut_bda_element; i++) {
			pref_choraai[i] = pref_choraai[i - 1] + choraai[i];
		}
		Fenwick Tree; Tree.init(n + 10);
		for (int i = 1; i <= n; i++) {
			Tree.add(i, n - child[i]);
		}
		vector<vector<int>> fen(bhut_bda_element + 1);
		for (int i = 1; i <= bhut_bda_element; i++) {
			fen[i].resize(choraai[i] + 1);
			for (int j = 1; j <= choraai[i]; j++) {
				fen[i][j] = fen[i][j - 1] + (child[siblings[i][j][1]] - 1);
			}
		}
		vector<Segtree> Treetree(bhut_bda_element + 1);
		for (int i = 1; i <= bhut_bda_element; i++) {
			Treetree[i].init(choraai[i] + 1);
			Treetree[i].build(phir_koi_aane_wala_hain[i], 1, 1, choraai[i]);
		}
		vector<indexed_set<array<int, 2>>> iscompleted(n + 1);
		vector<indexed_set<array<int, 2>>> done(n + 1);

		auto binary_search = [&](int compare, int greater, int m)->int{
			int low = 1, high = (int)siblings[m].size() - 1;
			int start = -1, end = -1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (greater) {
					if (siblings[m][mid][0] >= compare) {
						start = mid;
						high = mid - 1;
					} else {
						low = mid + 1;
					}
				}
				else {
					if (siblings[m][mid][0] <= compare) {
						end = mid;
						low = mid + 1;
					} else {
						high = mid - 1;
					}
				}
			}
			if (greater)
				return start;
			else
				return end;
		};

		auto binary_search2 = [&](int compare, int greater, int an)->int{
			int low = 1, high = (int)siblings[an - 1].size() - 1;
			int u = -1, v = -1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (greater) {
					if (siblings[an - 1][mid][0] >= compare) {
						u = mid;
						high = mid - 1;
					} else {
						low = mid + 1;
					}
				}
				else {
					if (siblings[an - 1][mid][0] <= compare) {
						v = mid;
						low = mid + 1;
					} else {
						high = mid - 1;
					}
				}
			}
			if (greater)
				return u;
			else
				return v;
		};

		int pw_2 = 2, pw_3 = 3;
		int d = 0;
		int tim = 1;
		while (q--) {
			int e;
			cin >> e;
			int c = (d ^ e);
			int l = 1, h = n;
			int ans;
			while (l <= h) {
				int m = (l + h) / 2;
				if (Tree.qry(m) < c) {
					ans = m + 1;
					l = m + 1;
				} else {
					h = m - 1;
				}
			}
			d = (d + pw_2 * ans % mod) % mod;
			int left = c - Tree.qry(ans - 1);
			l = 1, h = bhut_bda_element;
			int an;
			int nodea = -1, nodeb = -1;
			while (l <= h) {
				int m = (l + h) / 2;
				int here = pref_choraai[m];
				here -= done[ans].order_of_key({m + 1, -1});
				int start = -1, end = -1;
				start = binary_search(In[ans], 1, m);
				end = binary_search(Out[ans], 0, m);
				if (start != -1 and end != -1 and start <= end) {
					int extra = child[ans] - fen[m][end] + fen[m][start - 1];
					here -= extra;
				} else {
					if (m > H[ans]) {
						here -= child[ans];
					}
				}
				if (here >= left) {
					nodea = start, nodeb = end;
					an = m;
					h = m - 1;
				} else {
					l = m + 1;
				}
			}
			int u = -1, v = -1;
			u = binary_search2(In[ans], 1, an);
			v = binary_search2(Out[ans], 0, an);

			l = 1, h = (int)siblings[an].size() - 1;
			left = (left - pref_choraai[an - 1]);
			left += ((int)done[ans].order_of_key({an, -1}));
			if (u != -1 and v != -1 and u <= v) {
				left = (left + (child[ans] - fen[an - 1][v] + fen[an - 1][u - 1]));
			} else {
				if (an - 1 > H[ans]) {
					left += child[ans];
				}
			}
			int node;
			int total = 0;
			while (l <= h) {
				int m = (l + h) / 2;
				int here = m;
				int extra = Treetree[an].query(1, 1, choraai[an], l, m, In[ans]) - Treetree[an].query(1, 1, choraai[an], l, m, Out[ans] + 1) + total;
				here -= (iscompleted[ans].order_of_key({an, sibilings_count[an][m] + 1}) - iscompleted[ans].order_of_key({an, 0}));
				here -= extra;
				if (here >= left) {
					node = sibilings_count[an][m];
					h = m - 1;
				} else {
					l = m + 1;
					total = extra;
				}
			}
			d = (d + pw_3 * node % mod) % mod;
			done[ans].insert({H[node], In[node]});
			iscompleted[ans].insert({H[node], node });
			pw_2 = pw_2 * 2LL % mod;
			pw_3 = pw_3 * 3LL % mod;
			Tree.add(ans, -1);
		}
		cout << d << endl;
	}
}
int32_t main() {
	flash();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}