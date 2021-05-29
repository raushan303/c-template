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

void solve() {
	ll n;
	cin >> n;
	vl a(n + 1);
	f1(n) {
		cin >> a[i];
	}
	ll minm = inf, maxm = minf;
	cout << setprecision(10) << fixed;
	f1(n) {
		ll ans = 0;

		V<double> infec(n + 1, -1);
		infec[i] = 0.0;
		f(j, 1, i) {
			if (a[j] > a[i]) {
				ans++;
				infec[j] = (i - j) * (1.0) / (a[j] - a[i]);
			}
		}
		f(j, i + 1, n + 1) {
			f(k, 1, i + 1) {
				if (infec[k] != -1) {
					if (a[k] > a[j]) {
						double tim = (j - k) * (1.0) / (a[k] - a[j]);
						if (tim >= infec[k]) {
							ans++;
							break;
						}
					}
				}
			}
		}

		ans++;
		// cout << ans << endl;

		minm = min(minm, ans);
		maxm = max(maxm, ans);
	}
	cout << minm << " " << maxm << endl;

}

///////////////////////////////////////////////////

int32_t main()
{
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