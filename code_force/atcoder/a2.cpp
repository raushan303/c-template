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

ll mod(ll x)
{
    x = x % md;
    x += md;
    x %= md;
    return x;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll a[n + 10];

    int av = 0;

    vl v1, v2;

    ll mul = 1;

    f(i, 0, n)
    {
        ll tmp;
        cin >> tmp;

        mul = (mul * mod(tmp)) % md;
        if (mul < 0)
            mul += md;
        if (tmp == 0)
        {
            av = 1;
            continue;
        }
        if (tmp > 0)
            v1.pb(tmp);
        else
            v2.pb(tmp);
    }

    if (n == k)
    {
        if (mul < 0)
            mul += md;
        cout << mul << endl;
        return;
    }

    mul = 1;

    sort(all(v1), greater<ll>());
    sort(all(v2));

    ll sz1 = len(v1);

    ll sz2 = len(v2);

    if (sz1 == 0 and av == 0 and k % 2)
    {
        sort(all(v2), greater<ll>());
        ll j = 0;
        ll mul = 1;
        // ll mul2 = 1;
        while (k--)
        {
            // mul2 = mul2 * v2[j];
            mul = (mul * mod(v2[j])) % md;
            if (mul < 0)
                mul += md;
            j++;
        }
        // cout << mul2 << endl;
        if (mul < 0)
            mul += md;
        cout << mul << endl;
        return;
    }

    if (sz1 == 0)
    {
        if (k % 2 and av == 1)
        {
            cout << "0" << endl;
            return;
        }
    }

    if (k - sz2 + (sz2 % 2) > sz1)
    {
        if (av == 1)
        {
            cout << "0" << endl;
            return;
        }

    }


    ll i = 0;
    ll j = 0;


    while (k > 1 and i < sz1 and j + 1 < sz2)
    {
        if (v1[i] < v2[j]*v2[j + 1])
        {
            ll tmp = (v2[j] * v2[j + 1]) % md;
            tmp %= md;
            mul = (mul * tmp) % md;
            if (mul < 0)
                mul += md;
            j += 2;
            k -= 2;
        }
        else
        {

            mul = (mul * v1[i]) % md;
            if (mul < 0)
                mul += md;
            i++;
            k--;
        }


    }

    while (k > 0 and i < sz1)
    {
        // dbg(mul);
        mul = (mul * v1[i]) % md;
        if (mul < 0)
            mul += md;
        i++;
        k--;
    }
    ll mul2 = 1;

    while (k > 0 and j < sz2)
    {
        // mul2 = mul2 * v2[j];
        mul = (mul * mod(v2[j])) % md;
        if (mul < 0)
            mul += md;
        j++;
        k--;
    }

    // dbg(mul2);

    cout << mul << endl;


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