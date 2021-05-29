//tuple
#define mkt 		make_tuple
#define tup(t,ind) 	get<ind>(t)
#define tlen(t)		tuple_size<decltype(t)>::value
#define ig			ignore
#define tc	 		tuple_cat
tuple <int, char, float> tup1(20, 'g', 17.5);
tuple <int, char, float> tup2(10, 'f', 15.5);
tup1.swap(tup2);
//unpack tuple
tie(i_val, ch_val, f_val) = tup1;
tie(i_val, ig, f_val) = tup1;
//concat
auto tup3 = tc(tup1, tup2);

////////////////////////////////////////////////////////////////////////

//list
list<int> list1 = {10, 15, 20, 25, 30, 35};
list1.push_front(5);
list1.push_back(5);
// incrementing the positions of iterators
auto it = list1.begin();
advance(it, 2);
list1.erase(it);
list1.pop_front();
list1.pop_back();
// using remove() to delete all occurrences of 22
list1.remove(22);

bool is_div_5(const int& num) { return num % 5 == 0;}
// using remove_if() to delete multiple of 5
list1.remove_if(is_div_5);

// using assign() to insert multiple numbers
// creates 4 occurrences of "2"
list1.assign(4, 2);
int arr[10] = { 1, 2, 3, 4 };
list3.assign(arr, arr + 4);
// using assign() to copy elements of list to other
list2.assign(list1.begin(), list1.end());
// using insert to insert 2 element at the 4th position
// inserts 2 occurrences of 7 at 4th position
list1.insert(it, 2, 7);

//////////////////////////////////////////////////////////////////////

//multiset and set
auto cmp_ms = [&](int i, int j) {
	return i > j;
};
multiset<int, decltype(cmp_ms)>ms(cmp_ms);

auto cmp_s = [&](int i, int j) {
	return i > j;
};
set<int, decltype(cmp_s)>s(cmp_s);


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



