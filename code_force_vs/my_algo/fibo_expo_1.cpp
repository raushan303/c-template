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
#define md1                1000000007
#define md               998244353
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
ll n, a, b, c, d, e, f;

void multiply(ll F[2][2], ll M[2][2])
{
	ll x =  (F[0][0] * M[0][0]) % md + (F[0][1] * M[1][0]) % md;
	ll y =  (F[0][0] * M[0][1]) % md + (F[0][1] * M[1][1]) % md;
	ll z =  (F[1][0] * M[0][0]) % md + (F[1][1] * M[1][0]) % md;
	ll w =  (F[1][0] * M[0][1]) % md + (F[1][1] * M[1][1]) % md;
	F[0][0] = x % md;
	F[0][1] = y % md;
	F[1][0] = z % md;
	F[1][1] = w % md;
}

/*
 * function to calculate power of a matrix
 */
void power(ll F[2][2], ll n)
{
	if (n == 0 || n == 1)
		return;
	ll M[2][2] = {{e, f}, {1ll, 0ll}};
	power(F, n / 2);
	multiply(F, F);
	if (n % 2 != 0)
		multiply(F, M);
}

/*
 * function that returns nth Fibonacci number
 */
ll fibo_matrix(ll n)
{
	ll F[2][2] = {{e, f}, {1ll, 0ll}};
	if (n == 0)
		return 0;
	power(F, n - 1);
	return ((F[0][0] * b) % md + (F[0][1] * a) % md) % md;
}


void solve()
{

	cin >> n >> a >> b >> c >> d >> e >> f;
	a %= md;
	b %= md;
	e %= md;
	f %= md;
	ll ans1, ans2;

	if (n % 3 == 0)
	{
		ans1 = c;
	}
	else if (n % 3 == 1)
	{
		ans1 = d;
	}
	else if (n % 3 == 2)
	{
		ans1 = c ^ d;
	}
	if (n >= 2)
		ans2 = fibo_matrix(n);
	else if (n == 1)
	{
		ans2 = b;
	}
	else if (n == 0)
		ans2 = a;
	ans1 %= md;
	ans2 %= md;
	ll fans = (ans2 * ans1) % md + (ans2 - ans1 + md) % md;
	fans %= md;
	cout << fans << endl;


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
