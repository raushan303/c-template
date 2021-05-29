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
const ll N = 1e5 + 10;
ll mx[N * 4], premax[N * 4], sufmax[N * 4], sm[N * 4];

void build(ll nd, ll st, ll en, ll a[]) {
	if (st == en) {
		mx[nd] = a[st];
		sm[nd] = a[st];
		premax[nd] = a[st];
		sufmax[nd] = a[st];
		return;
	}
	ll m = (st + en) / 2;
	build(nd * 2 + 1, st, m, a);
	build(nd * 2 + 2, m + 1, en, a);
	sm[nd] = sm[nd * 2 + 1] + sm[nd * 2 + 2];
	mx[nd] = max(mx[nd * 2 + 1], mx[nd * 2 + 2]);
	if (premax[nd * 2 + 1] < sm[nd * 2 + 1] + premax[nd * 2 + 2]) {
		premax[nd] = sm[nd * 2 + 1] + premax[nd * 2 + 2];
	}
	else {
		premax[nd] = premax[nd * 2 + 1];
	}
	if (sufmax[nd * 2 + 2] < sm[nd * 2 + 2] + sufmax[nd * 2 + 1]) {
		sufmax[nd] = sm[nd * 2 + 2] + sufmax[nd * 2 + 1];
	}
	else {
		sufmax[nd] = sufmax[nd * 2 + 2];
	}

	mx[nd] = max(mx[nd], sufmax[nd * 2 + 1] + premax[nd * 2 + 2]);
	mx[nd] = max(mx[nd], premax[nd]);
	mx[nd] = max(mx[nd], sufmax[nd]);
}

void update(ll nd, ll st, ll en, ll ind, ll val) {
	if (st > ind or en < ind) {
		return;
	}
	if (st == en) {
		mx[nd] = val;
		sm[nd] = val;
		premax[nd] = val;
		sufmax[nd] = val;
		return;
	}
	ll m = (st + en) / 2;
	update(nd * 2 + 1, st, m, ind, val);
	update(nd * 2 + 2, m + 1, en, ind, val);
	sm[nd] = sm[nd * 2 + 1] + sm[nd * 2 + 2];
	mx[nd] = max(mx[nd * 2 + 1], mx[nd * 2 + 2]);
	if (premax[nd * 2 + 1] < sm[nd * 2 + 1] + premax[nd * 2 + 2]) {
		premax[nd] = sm[nd * 2 + 1] + premax[nd * 2 + 2];
	}
	else {
		premax[nd] = premax[nd * 2 + 1];
	}
	if (sufmax[nd * 2 + 2] < sm[nd * 2 + 2] + sufmax[nd * 2 + 1]) {
		sufmax[nd] = sm[nd * 2 + 2] + sufmax[nd * 2 + 1];
	}
	else {
		sufmax[nd] = sufmax[nd * 2 + 2];
	}

	mx[nd] = max(mx[nd], sufmax[nd * 2 + 1] + premax[nd * 2 + 2]);
	mx[nd] = max(mx[nd], premax[nd]);
	mx[nd] = max(mx[nd], sufmax[nd]);

}

void solve()
{
	ll n, m;
	cin >> n >> m;
	ll a[n + 10];
	f(i, 0, n) {
		cin >> a[i];
	}

	build(0, 0, n - 1, a);

	cout << max(mx[0], 0ll) << endl;

	while (m--) {
		ll l, r;
		cin >> l >> r;
		a[l] = r;
		update(0, 0, n - 1, l, r);
		cout << max(mx[0], 0ll) << endl;
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