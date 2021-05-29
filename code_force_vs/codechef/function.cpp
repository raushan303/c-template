// string reverse

string rev(string tmp)
{
	string ok = "";
	ll sz = len(tmp);
	rf(i, sz - 1, 0)
	ok += tmp[i];
	return ok;
}

// substring

string sub()
{
//   s.substr(start);
//   s.substr(start,length);
}

//


void countsmall(ll n)
{
	ll i = n;
	for (++i; i <= n; i += i & -i)
// 		a[i]+=x;


		for (; i; i -= i & -i)
		{
// 		r+=a[i];
		}
}

//dsu

map<ll, ll>f;
ll fnd(ll x)
{
	if (f[x] == 0)
	{
		return x;
	}

	return f[x] == x ? x : f[x] = fnd(f[x]);

}

// dec to with base k

vector<int> decToOctal(int n, int k)
{
	vector<int> v(100);
	int i = 0;
	while (n != 0) {
		v[i] = n % k;
		n = n / k;
		i++;
	}
	return v;
}

/////////////////////////////////////////////////////

// factorial ncr power


#define int long long

const int N = 2e5 + 5;
const int MOD = 998244353;

int pow(int a, int b, int m)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % m;
		b /= 2;
		a = (a * a) % m;
	}
	return ans;
}

int fact[N], invfact[N];

int modinv(int k)
{
	return pow(k, MOD - 2, MOD);
}

void precompute()
{
	fact[0] = fact[1] = 1;
	for (int i = 2; i < N; i++)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
	invfact[N - 1] = modinv(fact[N - 1]);
	for (int i = N - 2; i >= 0; i--)
	{
		invfact[i] = invfact[i + 1] * (i + 1);
		invfact[i] %= MOD;
	}
}

int nCr(int x, int y)
{
	if (y > x)
		return 0;
	int num = fact[x];
	num *= invfact[y];
	num %= MOD;
	num *= invfact[x - y];
	num %= MOD;
	return num;
}



/////////////////////////////////////////////////////////////


//  set for order of key

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template < typename T > using indexed_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;

indexed_set<pair<ll, ll>> s;

s.order_of_key();



