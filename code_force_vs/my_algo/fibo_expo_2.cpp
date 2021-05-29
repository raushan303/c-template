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
const int MOD = 998244353;
void flash()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll n, a, b, c, d, e, f;



struct Matrix {
	static const int MOD = 998244353;
	static const long long SQMOD = (long long) MOD * MOD;
	static int const N = 2;
	using T = int;
	T x[N][N];
	int n, m;
	Matrix(int _n = N, int _m = N, T val = 0): n(_n), m(_m) {
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
				x[i][j] = val;
	}
	Matrix(const vector<vector<int>> &&mat) {
		n = (int) mat.size();
		m = (int) mat[0].size();
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
				x[i][j] = mat[i][j];
	}
	Matrix& operator = (const vector<vector<int>> &&mat) {
		return *this = Matrix(forward<decltype(mat)>(mat));
	}
	T* operator [] (int r) {
		return x[r];
	}
	const T* operator [] (int r) const {
		return x[r];
	}
	static Matrix unit(int n) {
		Matrix res(n, n);
		for (int i = 0; i < n; i++) res[i][i] = 1;
		return res;
	}
	Matrix& operator += (const Matrix &rhs) {
		assert (n == rhs.n && m == rhs.m);
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
				x[i][j] += rhs[i][j];
				if (x[i][j] >= MOD) x[i][j] -= MOD;
			}
		return *this;
	}
	Matrix operator + (const Matrix &rhs) const {
		Matrix lhs(*this);
		return lhs += rhs;
	}
	friend Matrix operator * (const Matrix &A, const Matrix &B) {
		assert (A.m == B.n);
		Matrix res(A.n, B.m);
		for (int i = 0; i < res.n; i++) for (int j = 0; j < res.m; j++) {
				long long sum = 0LL;
				for (int k = 0; k < A.m; k++) {
					sum += (long long) A[i][k] * B[k][j];
					if (sum >= SQMOD) sum -= SQMOD;
				}
				res[i][j] = (int) (sum % MOD);
			}
		return res;
	}
	friend Matrix operator ^ (Matrix base, long long ex) {
		assert (base.n == base.m);
		Matrix res = Matrix::unit(base.n);
		while (ex > 0) {
			if (ex & 1) res = res * base;
			base = base * base;
			ex >>= 1;
		}
		return res;
	}
	Matrix& operator *= (const Matrix &rhs) {
		return *this = *this * rhs;
	}
	Matrix& operator ^= (const long long &ex) {
		return *this = *this ^ ex;
	}
	friend ostream &operator << (ostream &os, const Matrix& A) {
		os << "(" << A.n << " x " << A.m << ")" << endl;
		os << string(A.m * 2, '-');
		for (int i = 0; i < A.n; ++i) {
			os << endl;
			for (int j = 0; j < A.m; ++j) os << A[i][j] << ' ';
		}
		return os << endl << string(A.m * 2, '-');
	}
};

void solve()
{

	cin >> n >> a >> b >> c >> d >> e >> f;
	ll ans1, ans2;
	a %= md;
	b %= md;
	e %= md;
	f %= md;

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
	{
		Matrix A{{
				{e, f},
				{1, 0}
			}};

		Matrix B{{
				{b},
				{a}
			}};

		A ^= (n - 1);
		A *= B;
		ans2 = A[0][0];
	}
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