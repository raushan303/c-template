///////////////////////////////////////////////////

/*

      ⠀⠀⠀⠀⠀⠀⣀⣤⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣀⠀⠀⠀⠀⠀
  ⠀⠀⠀⠀⣰⣿⣿⣿⣿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣧⢀⠀⠀⠀⠀
  ⠀⠀⠀⣿⣿⣿⠋⠀⠀⠀⠀⠀⠙⠀⠙⣿⣿⣿⣷⢳⢀⠀⠀⠀
  ⠀⠀⣠⣿⣿⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⢀
  ⠀⠀⣸⣿⣿⣿⠸⠀⠀⠀⠒⠒⠒⠐⠀⠀⢿⣿⣿⣿⣿⣿⠀⠀
  ⠀⣴⣿⣿⣿⡿⠀⠒⣋⣙⡒⢰⠀⠤⣖⠒⢾⣿⣿⣿⣿⣧⠀⠀
  ⢺⣿⣿⣿⣿⢀⠀⠀⠉⠉⠉⠸⠀⡇⠉⠉⠀⢿⣿⣿⣿⣄⠀⠀
  ⠀⠙⣿⣿⣧⢻⠀⠀⠀⠀⠀⠠⠀⠰⠀⠀⠀⣸⠸⣿⣿⠿⠰⠀
  ⠀⠀⠀⠹⣿⣿⣿⣷⠀⡠⠙⣲⣔⣅⢡⣰⣷⣿⣿⣿⣧⠀⠀⠀
  ⠀⠀⠀⣼⣿⣿⣿⣿⠀⡿⠭⠭⠭⠭⢿⠀⣿⢻⣿⣿⠃⠀⠀⠀
  ⠀⠀⠀⠙⠛⣿⢻⠹⣿⠐⠙⠛⠟⠉⢀⣴⡟⢿⣿⡏⠀⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⡟⠀⠀⠻⣦⣤⣶⠾⠋⠀⠀⠁⡦⢄⢀⠀⠀⠀
  ⠀⠀⠀⠀⡠⠁⡇⠑⢄⠀⠀⠀⠀⠀⠀⠔⠀⠀⠁⠀⠀⠀⠉⠁
  ⠀⠔⠊⠁⠀⠀⣇⠀⠀⠀⠑⡤⠤⢎⠁⠀⠀⡘⠀⠀⠀⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⢢⠠⠀⡠⢆⠀⠀⡠⠙⢄⠀⡸⠀


  * * * *      *       *     * * *        * *      * * * *    * * * *
  *       *    *     *       *     *    *     *   *          *
  *       *    *   *         *     *   *       *  *          *
  * * * *      * *           * * *     *       *    * * *      * * *
  *      *     *   *         *     *   *       *          *          *
  *       *    *     *       *     *    *     *           *          *
  *        *   *       *     * * *        * *     * * * *    * * * *

*/

///////////////////////////////////////////////////

#include"bits/stdc++.h"
using namespace std;

///////////////////////////////////////////////////

#define ll                long long
#define int               long long

///////////////////////////////////////////////////

#define md                1000000007
#define md1               998244353
#define inf               90000000000000000
#define minf              -1000000000000000

///////////////////////////////////////////////////

#define ff                first
#define ss                second
#define pll               pair<ll,ll>
#define mkp               make_pair

///////////////////////////////////////////////////

#define in                insert
#define mpll              map<ll,ll>
#define M                 map
#define UM                unordered_map

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
#define dbg(i)            cout<<i<<endl
#define dbga              cout<<"!! Running with A  !!"<<endl
#define dbgb              cout<<"!! Running with B  !!"<<endl
#define dbgc              cout<<"!! Running with C  !!"<<endl
#define dbcd              cout<<"!! Running with D  !!"<<endl

////////////////////////////////////////////////////

void flash()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

///////////////////////////////////////////////////
const ll N = 1e4 + 5;
ll n, m;
ll xy[40][40];
ll fvis[40];

vl v[40];
UM<ll, ll> all[N];
UM<ll, ll> mxm[40];
ll vis[40];
vl prime;
ll ele[40], sz;
vl nodes;
void dfs(ll u)
{
	vis[u] = 1;
	nodes.pb(u);
	for (auto it : v[u])
	{
		if (vis[it])
			continue;
		dfs(it);
	}

}

ll cal(ll ind, ll pm)
{
	if (ind == sz)
		return 1;
	fvis[nodes[ind]] = 1;

	ll ok1 = 1, ok2 = 1;
	ll ans1 = 1, ans2 = 1;

	for (auto it : v[nodes[ind]])
	{
		if (fvis[it] and ele[it] != all[xy[nodes[ind]][it]][pm])
		{
			ok1 = 0;
		}
		else if (fvis[it] and mxm[nodes[ind]][pm] != all[xy[nodes[ind]][it]][pm])
		{
			ok2 = 0;
		}

	}

	if (ok1)
	{
		ele[nodes[ind]] = mxm[nodes[ind]][pm] - 1;
		ans1 = (cal(ind + 1, pm) * mxm[nodes[ind]][pm]) % md;
	}
	else
	{
		ans1 = 0;
	}

	if (ok2)
	{
		ele[nodes[ind]] = mxm[nodes[ind]][pm];
		ans2 = (cal(ind + 1, pm) % md);
	}
	else
	{
		ans2 = 0;
	}
	fvis[nodes[ind]] = 0;

	ll ans = (ans1 + ans2) % md;
	return ans;


}




void solve()
{

	cin >> n >> m;
	prime.clear();

	f(i, 1, n + 1)
	{
		vis[i] = 0;
		fvis[i] = 0;
		v[i].clear();

		mxm[i].clear();
		ele[i] = -1;
	}
	f(i, 0, m )
	all[i].clear();
	set<ll>tprime;
	mem(xy, -1);
	ll ok = 1;
	f(i, 0, m)
	{
		ll x, y, r;
		cin >> x >> y >> r;

		if (xy[x][y] != -1)
		{
			UM<ll, ll> mp;
			f(j, 0, r)
			{
				ll p, e;
				cin >> p >> e;
				mp[p] += e;
			}
			// if (all[xy[x][y]] != mp)
			// {
			// 	ok = 0;
			// }
			if (len(all[xy[x][y]]) != len(mp))
			{
				ok = 0;
			}
			else
			{
				for (auto it : mp)
				{
					if (it.ss != all[xy[x][y]][it.ff])
					{
						ok = 0;
					}
				}
			}
			continue;
		}

		xy[x][y] = i;
		xy[y][x] = i;

		// cout << x << " " << y << " " << xy[x][y] << endl;

		v[x].pb(y);
		v[y].pb(x);

		f(j, 0, r)
		{
			ll p, e;
			cin >> p >> e;
			tprime.in(p);
			all[i][p] += e;
		}
	}

	if (ok == 0)
	{
		cout << "0" << endl;
		return;
	}
	for (auto it : tprime)
		prime.pb(it);

	f(i, 1, n + 1)
	{
		for (auto it : prime)
		{
			mxm[i][it] = inf;
		}
		for (auto it : v[i])
		{
			for (auto itr : prime)
			{
				mxm[i][itr] = min(mxm[i][itr], all[xy[i][it]][itr]);
			}
		}
	}

	// f(i, 1, n + 1)
	// {
	// 	for (auto it : prime)
	// 	{
	// 		cout << mxm[i][it] << " ";
	// 	}
	// 	cout << endl;
	// }

	ll ans = 1;


	for (auto it : prime)
	{
		mem(fvis, 0);
		mem(vis, 0);

		f(i, 1, n + 1)
		{
			if (vis[i])
				continue;
			nodes.clear();
			dfs(i);
			sz = len(nodes);
			ans = (ans * cal(0, it)) % md;
			// cout << it << " " << ans << endl;
		}
	}


	if (ans == 0)
	{
		cout << "0" << endl;
		return;
	}

	// f(i, 0, n)
	// {
	// 	f(j, 0, n)
	// 	cout << xy[i][j] << " ";
	// 	cout << endl;
	// }
	f(i, 1, n + 1)
	{
		ll ok = 0;
		f(j, 1, n + 1)
		{
			if (xy[i][j] != -1)
			{
				ok = 1;
				break;
			}
		}
		if (ok == 0)
		{
			cout << "-1" << endl;
			return;
		}
	}

	cout << ans << endl;

}
///////////////////////////////////////////////////

int32_t main()
{
	flash();
	int t;
	t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

///////////////////////////////////////////////////