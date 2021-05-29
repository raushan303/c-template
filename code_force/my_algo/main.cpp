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

ll pw(ll x, ll y)
{
  if (y == 0)
    return 1;
  if (y == 1)
    return x;
  ll ans = pw(x, y / 2);
  ans = ans * ans;
  if (y % 2 == 1)
    ans = ans * x;
  return ans;
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

int check(ll n)
{
  if (n < 0)
    return 0;
  else
    return 1;
}

ll add(ll a, ll b)
{
  return a + b;
}

ll max(ll a, ll b)
{
  if (a > b)
    return a;
  else
    return b;
}

ll min(ll a, ll b)
{
  if (a > b)
    return b;
  else
    return a;
}

ll minv(ll a, ll m)
{
  ll m0 = m;
  ll y = 0, x = 1;
  if (m == 1)
    return 0;
  while (a > 1)
  {
    ll q = a / m, t = m;
    m = a % m, a = t, t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0)
    x += m0;
  return x;
}
bool cmp(ll i1, ll i2)
{

  // i1<i2 for increasing order
  //    greater<ll>();
  // i1>i2 for decreasing order
  return (i1 < i2);
}




void solve()
{





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
