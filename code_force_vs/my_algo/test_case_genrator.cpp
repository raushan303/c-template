/*

    * * * *      *       *     * * *        * *      * * * *    * * * *
    *       *    *     *       *     *    *     *   *          *
    *       *    *   *         *     *   *       *  *          *
    * * * *      * *           * * *     *       *    * * *      * * *
    *      *     *   *         *     *   *       *          *          *
    *       *    *     *       *     *    *     *           *          *
    *        *   *       *     * * *        * *     * * * *    * * * *

*/

///////////////////////////////////////////////////

#include"bits/stdc++.h"
using namespace std;

///////////////////////////////////////////////////

#define ll                long long
#define int               long long

///////////////////////////////////////////////////

#define md1               1000000007
#define md                998244353
#define inf               9000000000000000000
#define minf              -1000000000000000

///////////////////////////////////////////////////

#define ff                first
#define ss                second
#define pll               pair<ll,ll>
#define mkp               make_pair

///////////////////////////////////////////////////

#define in                insert
#define mpll              map<ll,ll>
#define M                 map
#define UM                unordered_map

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


///////////////////////////////////////////////////

#define dbg(i)            cout<<i<<endl;
#define I                 cin>>
#define O                 cout<<
#define I1(a)             cin>>a;
#define I2(a,b)           cin>>a>>b;
#define I3(a,b,c)         cin>>a>>b>>c;
#define I4(a,b,c,d)       cin>>a>>b>>c>>d;
#define O1(a)             cout<<a<<endl;
#define O2(a,b)           cout<<a<<" "<<b<<endl;

///////////////////////////////////////////////////

#define print(arr,n)\
f(i,0,n)\
{\
  cout<<arr[i]<<" ";\
}\
cout<<endl;\

////////////////////////////////////////////////////

#define printr(arr,n)\
rf(i,n-1,0)\
{\
  cout<<arr[i]<<" ";\
}\
cout<<endl;\

////////////////////////////////////////////////////

#define printv(vec)\
f(i,0,len(vec))\
{\
  cout<<vec[i]<<" ";\
}\
cout<<endl;\

////////////////////////////////////////////////////

#define print2d(arr,n,m)\
f(i,0,n)\
{\
  f(j,0,m)\
  cout<<arr[i][j]<<" ";\
  cout<<endl;\
}\

////////////////////////////////////////////////////

void flash()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

///////////////////////////////////////////////////

void solve()
{





}

///////////////////////////////////////////////////

int32_t main()
{
	srand(time(NULL));
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);
	mt19937 g(seed);
	int t;
	cin >> t;
	cout << t << '\n';
	while (t--)
	{
		uniform_int_distribution<int> N(1, 100), A(0, 25);
		ll n = N(e);
		f(i, 1, n + 1)
		cout << A(e) << " ";
		cout << endl;
	}

}

///////////////////////////////////////////////////
