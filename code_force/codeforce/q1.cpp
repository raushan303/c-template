#include<bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////

#define ll                long long
#define int               long long

///////////////////////////////////////////////////

#define md                1000000007
#define md1               998244353
#define inf               9000000000000000000
#define minf              -10000000000000000

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

////////////////////////////////////////////////////

// void flash()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// }


void solve() {

	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		ll tmp;
		cin >> v[i];
	}
	ll c1, c2;
	cin >> c1 >> c2;
	vector<int>vis(n, 0);

	int j = c1;
	while (v[j] != -1) {
		vis[j] = 1;
		j = v[j];
	}

	j = c2;

	while (v[j] != -1) {
		if (vis[j]) {
			cout << j << endl;
			return;
		}
		j = v[j]
	}

	cout << "-1" << endl;





}

///////////////////////////////////////////////////

int32_t main()
{
	// flash();
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

///////////////////////////////////////////////////