///////////////////////////////////////////////////

#include"bits/stdc++.h"
using namespace std;

///////////////////////////////////////////////////

#define ll                long long
#define int               long long

///////////////////////////////////////////////////

#define ff                first
#define ss                second
#define pll               pair<ll,ll>

///////////////////////////////////////////////////

#define endl              "\n"

///////////////////////////////////////////////////

#define V                 vector
#define vl                vector<ll>
#define vvl               vector<vl>
#define vpll              vector<pair<ll,ll>>
#define pb                push_back
#define len(p)            (ll)p.size()

///////////////////////////////////////////////////

#define f(i,yha,wha)      for(ll i=yha;i<wha;i++)
#define rf(i,wha,yha)     for(ll i=wha;i>=yha;i--)

///////////////////////////////////////////////////

void flash()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

///////////////////////////////////////////////////
const ll N = 2e5 + 10;
ll n, q, h[N], a[N], mx[N * 4];
vl v[N * 4], v1[N * 4];
vector<array<ll, 3>> lazy1[4 * N], lazy2[4 * N];


struct Fenwick
{
	vector<ll> BIT;
	void reset(ll n)
	{
		BIT.resize(n + 2);
	}
	void add(int r, int value, ll n)
	{
		for (int i = r; i < n; i = i | (i + 1))
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

Fenwick b1[N * 4], b2[N * 4];

vpll merge(ll nd, ll st, ll en)
{
	if (st == en)
	{
		v[nd].pb(h[st]);
		b1[nd].reset(1ll);
		b1[nd].add(0ll, a[st], 1ll);
		mx[nd] = h[st];
		return {{h[st], st}};
	}

	ll m = (st + en) / 2;

	vpll tmp1 = merge(2 * nd + 1, st, m);
	vpll tmp2 = merge(2 * nd + 2, m + 1, en);

	vpll tmp;
	ll sm = 0;

	for (auto it : tmp1)
	{
		if (it.ff > tmp2[0].ff)
		{
			sm += a[it.ss];
			tmp.pb(it);
			v[nd].pb(it.ff);
		}
		else
			break;
	}

	for (auto it : tmp2)
	{
		sm += a[it.ss];
		v[nd].pb(it.ff);
		tmp.pb(it);
	}

	ll sz = len(tmp);
	b1[nd].reset(sz);

	f(i, 0, sz)
	{
		b1[nd].add(i, a[tmp[i].ss], sz);
	}

	mx[nd] = tmp[0].ff;
	return tmp;
}

vpll merge1(ll nd, ll st, ll en)
{
	if (st == en)
	{
		v1[nd].pb(h[st]);
		b2[nd].reset(1ll);
		b2[nd].add(0ll, a[st], 1ll);
		return {{h[st], st}};
	}

	ll m = (st + en) / 2;

	vpll tmp1 = merge1(2 * nd + 1, st, m);
	vpll tmp2 = merge1(2 * nd + 2, m + 1, en);

	vpll tmp;
	ll sm = 0;


	for (auto it : tmp1)
	{
		sm += a[it.ss];
		v1[nd].pb(it.ff);
		tmp.pb(it);
	}

	ll sz1 = len(tmp1);
	ll sz2 = len(tmp2);

	f(i, 0, sz2)
	{
		if (tmp2[i].ff > tmp1[sz1 - 1].ff)
		{
			sm += a[tmp2[i].ss];
			tmp.pb(tmp2[i]);
			v1[nd].pb(tmp2[i].ff);
		}
	}

	ll sz = len(tmp);
	b2[nd].reset(sz);
	f(i, 0, sz)
	{
		b2[nd].add(i, a[tmp[i].ss], sz);
	}

	return tmp;
}

ll ans;
vl nodes;

ll mxm(ll nd, ll st, ll en, ll l, ll r)
{
	if (st >= l and en <= r)
	{
		return mx[nd];
	}
	if (st > r or en < l)
		return 0;

	ll m = (st + en) / 2;
	return max(mxm(nd * 2 + 1, st, m, l, r), mxm(nd * 2 + 2, m + 1, en, l, r));
}

void update1(ll nd, ll st, ll en)
{
	ll sz = len(lazy1[nd]);
	f(i, 0, sz)
	{
		ll ind = lazy1[nd][i][0];
		ll intial = lazy1[nd][i][1];
		ll final = lazy1[nd][i][2];
		if (st >= ind and en <= ind)
		{
			b1[nd].add(0ll, final - intial, 1ll);
			continue;
		}
		if (mxm(0, 0, n - 1, ind + 1, en) < h[ind])
		{
			ll tst = 0, ten = len(v[nd]) - 1;
			ll sz = ten + 1;
			ll tmx = h[ind];
			while (tst <= ten)
			{
				ll mid = (tst + ten) / 2;
				if (v[nd][mid] == tmx)
				{
					b1[nd].add(mid, final - intial, sz);
					break;
				}
				if (v[nd][mid] > tmx)
				{
					tst = mid + 1;
				}
				else
				{
					ten = mid - 1;
				}
			}
		}
	}
	lazy1[nd].clear();
}
void update2(ll nd, ll st, ll en)
{
	ll sz = len(lazy2[nd]);
	f(i, 0, sz)
	{
		ll ind = lazy2[nd][i][0];
		ll intial = lazy2[nd][i][1];
		ll final = lazy2[nd][i][2];
		if (st >= ind and en <= ind)
		{
			b2[nd].add(0ll, final - intial, 1ll);
			continue;
		}
		if (mxm(0, 0, n - 1, st, ind - 1) < h[ind])
		{
			ll tst = 0, ten = len(v1[nd]) - 1;
			ll sz = ten + 1;
			ll tmx = h[ind];
			while (tst <= ten)
			{
				ll mid = (tst + ten) / 2;
				if (v1[nd][mid] == tmx)
				{
					b2[nd].add(mid, final - intial, sz);
					break;
				}
				if (v1[nd][mid] > tmx)
				{
					ten = mid - 1;
				}
				else
				{
					tst = mid + 1;
				}
			}
		}
	}
	lazy2[nd].clear();
}

void push(ll nd, ll st, ll en, ll ind, ll intial, ll final)
{
	if (st > ind or en < ind)
		return;
	if (st == en)
	{
		lazy1[nd].pb({ind, intial, final});
		lazy2[nd].pb({ind, intial, final});
		return;
	}
	ll m = (st + en) / 2;
	push(2 * nd + 1, st, m, ind, intial, final);
	push(2 * nd + 2, m + 1, en, ind, intial, final);
	lazy1[nd].pb({ind, intial, final});
	lazy2[nd].pb({ind, intial, final});
}

void query1(ll nd, ll st, ll en, ll l, ll r)
{
	if (st >= l and en <= r)
	{
		update1(nd, st, en);
		nodes.pb(nd);
		return;
	}
	if (st > r or en < l)
		return;
	ll m = (st + en) / 2;
	query1(nd * 2 + 1, st, m, l, r);
	query1(nd * 2 + 2, m + 1, en, l, r);
}

void query2(ll nd, ll st, ll en, ll l, ll r)
{
	if (st >= l and en <= r)
	{
		update2(nd, st, en);
		nodes.pb(nd);
		return;
	}
	if (st > r or en < l)
		return;

	ll m = (st + en) / 2;
	query2(nd * 2 + 1, st, m, l, r);
	query2(nd * 2 + 2, m + 1, en, l, r);
}

void solve()
{
	cin >> n >> q;
	f(i, 0, n)
	cin >> h[i];
	f(i, 0, n)
	cin >> a[i];
	merge(0, 0, n - 1);
	merge1(0, 0, n - 1);

	while (q--)
	{
		ll t, st, en;
		cin >> t >> st >> en;
		ans = 0;
		if (t == 2)
		{
			st--;
			en--;
			if (st <= en)
			{
				if (mxm(0, 0, n - 1, st + 1, en) >= h[st])
				{
					cout << "-1" << endl;
					continue;
				}
				nodes.clear();
				query1(0, 0, n - 1, st, en);

				ll sz = len(nodes);
				ll tsz = len(v[nodes[sz - 1]]);
				ans += b1[nodes[sz - 1]].qry(tsz - 1);
				ll tmx = v[nodes[sz - 1]][0];
				rf(i, sz - 2, 0)
				{
					ll tst = 0, ten = len(v[nodes[i]]) - 1;
					ll loc = -1;
					while (tst <= ten)
					{
						ll mid = (tst + ten) / 2;
						if (v[nodes[i]][mid] > tmx)
						{
							loc = mid;
							tst = mid + 1;
						}
						else
						{
							ten = mid - 1;
						}
					}
					if (loc != -1)
					{
						ans += b1[nodes[i]].qry(loc);
						tmx = v[nodes[i]][0];
					}
				}
				cout << ans << endl;
			}
			else
			{
				if (mxm(0, 0, n - 1, en, st - 1) >= h[st])
				{
					cout << "-1" << endl;
					continue;
				}

				nodes.clear();
				query2(0, 0, n - 1, en, st);

				ll sz = len(nodes);
				ans += b2[nodes[0]].qry(len(v1[nodes[0]]) - 1);
				ll tmx = v1[nodes[0]][len(v1[nodes[0]]) - 1];
				f(i, 1, sz)
				{
					ll tst = 0, ten = len(v1[nodes[i]]) - 1;
					ll loc = -1;
					while (tst <= ten)
					{
						ll mid = (tst + ten) / 2;
						if (v1[nodes[i]][mid] > tmx)
						{
							loc = mid;
							ten = mid - 1;
						}
						else
						{
							tst = mid + 1;
						}
					}
					if (loc != -1)
					{
						ans += b2[nodes[i]].qry(len(v1[nodes[i]]) - 1) - (loc == 0 ? 0 : b2[nodes[i]].qry(loc - 1));
						tmx = v1[nodes[i]][len(v1[nodes[i]]) - 1];
					}
				}
				cout << ans << endl;
			}
		}
		else
		{
			st--;
			push(0, 0, n - 1, st, a[st], en);
			a[st] = en;
		}
	}
}

///////////////////////////////////////////////////

int32_t main()
{
	flash();
	int t;
	t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

///////////////////////////////////////////////////