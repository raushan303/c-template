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
const ll N = 2e5 + 10;
string s;

int ispos(ll x, ll y, ll mov)
{
	if (abs(x) + abs(y) <= mov)
		return 1;
	return 0;
}

void solve()
{

	ll u;
	cin >> u;

	ll n = 10000;

	string num[n + 2], str[n + 2];

	map<char, ll>mp;


	map<char, ll>zero;

	f(i, 0, n)
	{
		cin >> num[i] >> str[i];
		f(j, 0, len(str[i]))
		mp[str[i][j]] = 9;
		zero[str[i][0]] = 1;
	}
	cout << endl;
	// for (auto it : mp)
	// 	cout << it.ff << " " << it.ss << endl;

	f(i, 0, n)
	{
		if (len(str[i]) == len(num[i]))
			mp[str[i][0]] = min(mp[str[i][0]], (int)num[i][0] - 48);
	}

	map<ll, char>mp2;
	for (auto it : mp)
	{
		if (zero[it.ff] == 0)
			mp[it.ff] = 0;
	}
	for (auto it : mp)
		cout << it.ff << " " << it.ss << endl;

	for (auto it : mp)
		mp2[it.ss] = it.ff;

	string ans = "";

	f(i, 0, 10)
	ans += mp2[i];
	cout << ans << endl;



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
