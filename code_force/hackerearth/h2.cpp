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
#define md                10
#define md1               998244353
#define inf               9000000000000000000
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
#define en()              end()
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



void solve()
{
    ll x, n;
    cin >> x >> n;

    if (n >= 5)
    {
        cout << x % 10;
    }
    else
    {
        ll fact = 1;
        f(i, 1, n + 1)
        fact *= i;

        ll ans = pwm(x, fact % 10);
        cout << ans % 10;
    }




}

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
