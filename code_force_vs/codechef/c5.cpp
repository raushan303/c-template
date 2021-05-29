/*

    * * * *      *       *     * * *        * *      * * * *    * * * *
    *       *    *     *       *     *    *     *   *          *
    *       *    *   *         *     *   *       *  *          *
    * * * *      * *           * * *     *       *    * * *      * * *
    *      *     *   *         *     *   *       *          *          *
    *       *    *     *       *     *    *     *           *          *
    *        *   *       *     * * *        * *     * * * *    * * * *

*/
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int               long long
#define ff                first
#define ss                second
#define md                1000000007
#define md1               998244353
#define inf               1000000000000000
#define minf              -1000000000000000
#define pb                push_back
#define ppb               pop_back
#define in                insert
#define mkp               make_pair
#define mpll              map<ll,ll>
#define len(p)            (ll)p.size()
#define pll               pair<ll,ll>
#define all(v)            v.begin(),v.end()
#define mem(a,t)          memset(a,t,sizeof(a))
#define endl              "\n"
#define ar                array
#define vl                vector<ll>
#define vvl               vector<vl>
#define lb                lower_bound
#define ub                upper_bound
#define be()              begin()
#define en()			  end()
#define vpll              vector<pair<ll,ll>>
#define f(i,yha,wha)      for(ll i=yha;i<wha;i++)
#define rf(i,wha,yha)     for(ll i=wha;i>=yha;i--)
#define f0(n)             for(ll i=0;i<n;i++)
#define f1(n)             for(ll i=1;i<=n;i++)
#define fg(i,yha,wha,gap) for(ll i=yha;i<wha;i+=gap)



void flash()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n + 10];
	f(i, 1, n + 1)
	cin >> a[i];

	ll st1 = -1, st2 = -1;
	rf(i, k, 1)
	{
		if (a[i] % 2)
		{
			st1 = i;
			break;
		}
	}

	rf(i, k, 1)
	{
		if (a[i] % 2 == 0)
		{
			st2 = i;
			break;
		}
	}

	ll ans1 = -1, ans2 = -1;

	if (st1 != -1)
	{
		ans1 = 1;
		while (st1 <= n)
		{
			ans1++;
			ll j = st1 + k;
			if (j > n)
				break;
			while (a[j] % 2 == 0)
				j--;
			if (st1 == j)
			{
				ans1 = -1;
				break;
			}
			st1 = j;
		}
	}

	if (st2 != -1)
	{
		ans2 = 1;
		while (st2 <= n)
		{
			ans2++;
			ll j = st2 + k;
			if (j > n)
				break;
			while (a[j] % 2)
				j--;
			if (st2 == j)
			{
				ans2 = -1;
				break;
			}
			st2 = j;
		}
	}

	if (ans1 == -1 and ans2 == -1)
	{
		cout << "-1" << endl;
		return;
	}
	if (ans1 == -1)
	{
		cout << ans2 << endl;
		return;
	}
	if (ans2 == -1)
	{
		cout << ans1 << endl;
		return;
	}

	cout << min(ans1, ans2) << endl;
	return;



}

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
