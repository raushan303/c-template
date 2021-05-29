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

////////////////////////////////////////////////////

void flash()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

///////////////////////////////////////////////////

void solve() {
	ll n, k;
	cin >> n >> k;
	V<array<ll, 2>>a(n);
	f(i, 0, n) {
		cin >> a[i][0] >> a[i][1];
	}
	sort(all(a));


	ll ans = 0;
	ll st = -1, en = -1;
	f(i, 0, n) {
		// cout << st << " " << en << endl;
		if (a[i][0] < en)
			continue;

		ll ln = a[i][1] - a[i][0];
		ll tim = (ln - 1) / k + 1;
		st = a[i][0];
		en = a[i][0] + tim * k;
		ans += tim;
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
	f(i, 1, t + 1)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
