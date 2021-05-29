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
#define PI                3.141592653589793238
#define INF               16331239353195370

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

void solve() {
	ll n;
	cin >> n;
	vl p(n);
	f(i, 0, n) {
		cin >> p[i];
	}
	auto cal = [&](vl & v) {
		ll ln = len(v);
		ll cnt = 0;
		f(i, 0, ln) {
			f(j, 0, i) {
				cnt += (v[j] > v[i]);
			}
		}
		return cnt;
	};

	if (n <= 20) {
		f(i, 0, (1 << n)) {
			vl v1, v2;
			f(j, 0, n) {
				if ((i >> j) & 1) {
					v1.pb(p[j]);
				}
				else {
					v2.pb(p[j]);
				}
			}
			if (cal(v1) == cal(v2)) {
				cout << "YES" << endl;
				return;
			}
		}
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}




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