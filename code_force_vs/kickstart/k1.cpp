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
#define en()        end()
#define vpll              vector<pair<ll,ll>>
#define f(i,yha,wha)      for(ll i=yha;i<wha;i++)
#define rf(i,wha,yha)     for(ll i=wha;i>=yha;i--)
#define f0(n)             for(ll i=0;i<n;i++)
#define f1(n)             for(ll i=1;i<=n;i++)
#define fg(i,yha,wha,gap) for(ll i=yha;i<wha;i+=gap)


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

void flash()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const ll N = 32;
ll r, c;
string s[N];
void solve()
{
  cin >> r >> c;
  set<char>st;
  f(i, 0, r)
  {
    cin >> s[i];
    f(j, 0, c)
    st.in(s[i][j]);
  }

  ll n = len(s);
  map<char, ll>mp;


  f(i, 0, n)
  {
    for (auto it : st)
    {

    }
  }



}


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
