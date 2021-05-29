///////////////////////////////////////////////////

/*

      ⠀⠀⠀⠀⠀⠀⣀⣤⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣀⠀⠀⠀⠀⠀
  ⠀⠀⠀⠀⣰⣿⣿⣿⣿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣧⢀⠀⠀⠀⠀
  ⠀⠀⠀⣿⣿⣿⠋⠀⠀⠀⠀⠀⠙⠀⠙⣿⣿⣿⣷⢳⢀⠀⠀⠀
  ⠀⠀⣠⣿⣿⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⢀
  ⠀⠀⣸⣿⣿⣿⠸⠀⠀⠀⠒⠒⠒⠐⠀⠀⢿⣿⣿⣿⣿⣿⠀⠀
  ⠀⣴⣿⣿⣿⡿⠀⠒⣋⣙⡒⢰⠀⠤⣖⠒⢾⣿⣿⣿⣿⣧⠀⠀
  ⢺⣿⣿⣿⣿⢀⠀⠀⠉⠉⠉⠸⠀⡇⠉⠉⠀⢿⣿⣿⣿⣄⠀⠀
  ⠀⠙⣿⣿⣧⢻⠀⠀⠀⠀⠀⠠⠀⠰⠀⠀⠀⣸⠸⣿⣿⠿⠰⠀
  ⠀⠀⠀⠹⣿⣿⣿⣷⠀⡠⠙⣲⣔⣅⢡⣰⣷⣿⣿⣿⣧⠀⠀⠀
  ⠀⠀⠀⣼⣿⣿⣿⣿⠀⡿⠭⠭⠭⠭⢿⠀⣿⢻⣿⣿⠃⠀⠀⠀
  ⠀⠀⠀⠙⠛⣿⢻⠹⣿⠐⠙⠛⠟⠉⢀⣴⡟⢿⣿⡏⠀⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⡟⠀⠀⠻⣦⣤⣶⠾⠋⠀⠀⠁⡦⢄⢀⠀⠀⠀
  ⠀⠀⠀⠀⡠⠁⡇⠑⢄⠀⠀⠀⠀⠀⠀⠔⠀⠀⠁⠀⠀⠀⠉⠁
  ⠀⠔⠊⠁⠀⠀⣇⠀⠀⠀⠑⡤⠤⢎⠁⠀⠀⡘⠀⠀⠀⠀⠀⠀
  ⠀⠀⠀⠀⠀⠀⢢⠠⠀⡠⢆⠀⠀⡠⠙⢄⠀⡸⠀


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

#define md                1000000007
#define md1               998244353
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
cout<<endl;

////////////////////////////////////////////////////

#define printr(arr,n)\
rf(i,n-1,0)\
{\
  cout<<arr[i]<<" ";\
}\
cout<<endl;

////////////////////////////////////////////////////

#define printv(vec)\
f(i,0,len(vec))\
{\
  cout<<vec[i]<<" ";\
}\
cout << endl;

////////////////////////////////////////////////////

#define print2d(arr,n,m)\
f(i,0,n)\
{\
  f(j,0,m)\
  cout<<arr[i][j]<<" ";\
  cout<<endl;\
}

////////////////////////////////////////////////////

void flash()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

///////////////////////////////////////////////////
ll h, w, k;
ll check(ll i, ll j)
{
    if (i > h - 1 or i<0 or j>w - 1 or j < 0)
        return 0;
    return 1;
}
string s[15];

ll dfs(vl &v1, vl &v2)
{
    ll cnt = 0;
    f(i, 0, h)
    {
        f(j, 0, w)
        {
            if (v1[i] or v2[j])
                continue;

            if (s[i][j] == '#')
                cnt++;

        }
    }

    return cnt == k;
}

void solve()
{

    cin >> h >> w >> k;



    f(i, 0, h)
    cin >> s[i];

    ll ans = 0;

    ll r = pow(2, h);
    ll c = pow(2, w);
    f(i, 0, r)
    {
        f(j, 0, c)
        {
            vl v1(10, 0), v2(10, 0);
            f(k, 0, 6)
            {
                if ((i >> k) & 1)
                    v1[k] = 1;
                if ((j >> k) & 1)
                    v2[k] = 1;
            }
            if (dfs(v1, v2))
                ans++;
        }
    }

    cout << ans << endl;



}



///////////////////////////////////////////////////

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

///////////////////////////////////////////////////