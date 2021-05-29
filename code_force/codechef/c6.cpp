///////////////////////////////////////////////////

/*
   * * * *    *     *   * * *      * *       * * *    * * *
   *      *   *   *     *    *   *     *    *        *
   * * * *    * *       * * *   *       *    * * *    * * *
   *     *    *   *     *    *   *     *          *        *
   *      *   *     *   * * *      * *       * * *    * * *
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

#define I                 cin>>
#define O                 cout<<
#define PI                3.141592653589793238
#define INF               16331239353195370

////////////////////////////////////////////////////

void flash()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

///////////////////////////////////////////////////

#ifndef ONLINE_JUDGE
#include"../debugger.h"
#else
#define dbg(x...)
#endif

////////////////////////////////////////////////////

void solve() {
	ll n;
	cin >> n;
	V<array<ll, 2>>arr1(n), arr2(n);
	V<array<ll, 3>>v(n);
	V<float>angle(n);
	f(i, 0, n) {
		ll x, y;
		cin >> x >> y;
		arr1[i] = {x, y};
	}

	auto findangle = [&](array<ll, 3> a)->float{
		float angle1;
		if (a[0] == 0 or a[1] == 0) {
			if (a[0] == 0) {
				if (a[1] > 0)
					angle1 = 90.0;
				else if (a[1] < 0)
					angle1 = 270.0;
				else
					angle1 = 0.0;
			}
			else {
				if (a[0] >= 0)
					angle1 = 0.0;
				if (a[0] < 0)
					angle1 = 180.0;
			}
		}
		else {
			float val = (float)abs(a[1]) / abs(a[0]);
			angle1 = atan(val) * 180 / PI;
			if (a[0] < 0 and a[1] < 0) {
				angle1 += 180;
			}
			else if (a[0] < 0) {
				angle1 = 180 - angle1;
			}
			else if (a[1] < 0) {
				angle1 = 360 - angle1;
			}
		}
		return angle1;
	};

	f(i, 0, n) {
		arr2[i] = {arr1[(i + 1) % n][0] - arr1[i][0], arr1[(i + 1) % n][1] - arr1[i][1]};
		v[i] = {arr2[i][0], arr2[i][1], i + 1};
		angle[i] = findangle(v[i]);
	}

	sort(all(v), [&](array<ll, 3>a, array<ll, 3>b) {
		return findangle(a) < findangle(b);
	});
	sort(all(angle));
	float tmp = angle.back();
	tmp = -(360 - tmp);
	angle.insert(angle.be(), tmp);
	v.insert(v.be(), v.back());
	// v.pb(v[1]);
	ll m = len(v);
	ll m2 = m;
	f(i, 1, m) {
		v.pb(v[i]);
		angle.pb(angle[i] + 360);
	}
	// f(k, 0, n) {
	// 	cout << arr2[k][0] << " " << arr2[k][1] << "  ";
	// }
	// cout << endl;

	// for (auto it : v) {
	// 	cout << (float)findangle(it) << " " << it[0] << " " << it[1] << " " << it[2] << endl;
	// }
	// cout << endl;
	// cout << setprecision(6) << fixed;
	m = len(v);
	// f(i, 0, m) {
	// 	cout << i << " " << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
	// }
	auto check = [&](ll x, ll y)->ll {
		ll cnt1 = 0;
		ll cnt2 = 0;
		ll ok = 1;
		f(k, 0, n) {
			if (arr2[k][0] * x + y * arr2[k][1] > 0) {
				cnt1++;
				while (k < n and (arr2[k][0] * x + y * arr2[k][1]) > 0) {
					k++;
				}
				k--;
			}
			else if (arr2[k][0] * x + y * arr2[k][1] < 0) {
				cnt2++;
				while (k < n and (arr2[k][0] * x + y * arr2[k][1]) < 0) {
					k++;
				}
				k--;
			}
			else {
				ok = 0;
			}
		}
		// cout << ok << " " << cnt1 << " " << cnt2 << endl;

		if (!ok) {
			return 0;
			// 	cout << (1 / 0) << endl;
		}
		if (cnt1 == 1 or cnt2 == 1) {
			return 1;
		}
		else {
			return 0;
			// 	cout << (1 / 0) << endl;
		}

	};


	f(i, 1, m2 ) {
		vl freq(n + 5, 0);
		ll st = 1;
		ll en = n;
		ll mnind = m + 1;
		ll mxind = 0;
		f(j, i, m - 1) {
			if (j != i and v[i][2] == v[j][2])
				break;
			float ang1 = 0, ang2 = 0, ang3 = 0, ang4 = 0, ang5 = 0, ang6 = 0;

			ang1 = angle[i];
			ang2 = angle[j];
			ang3 = angle[i - 1] + 90;
			ang4 = angle[j + 1] - 90;
			// cout << ang1 << " " << ang2 << " " << ang3 << " " << ang4 << endl;

			mnind = min(mnind, v[j][2]);
			mxind = max(mxind, v[j][2]);
			freq[v[j][2]]++;
			while (freq[st])
				st++;
			while (freq[en])
				en--;
			if (ang2 - ang1 > 180.0)
				continue;
			if (ang3 > ang4)
				continue;
			ang5 = max(ang3, ang2 - 90);
			ang6 = min(ang4, ang1 + 90);

			// if (ang5 >= ang6)
			// 	continue;
			// cout << "ok" << endl;
			// cout << i << " " << j << endl;
			if (st - 1 + n - en == j - i + 1 or mxind - mnind + 1 == j - i + 1) {
				// cout << ang1 << " " << ang2 << " " << ang3 << " " << ang4 << endl;
				// cout << ang5 << " " << ang6 << " " << mnind << " " << mxind << " " << st << " " << en << " " << i << " " << j << endl;
				// cout << "hello" << endl;

				float fangle = (ang5 + ang6) / 2.0;
				// if(fangle==)
				// cout << fangle << endl;
				// if (fangle >= 360)
				// 	fangle -= 360;
				double slop = tan(fangle * PI / 180);
				ll y, x;
				// cout << slop << " " << fangle << endl;
				if (fangle >= 360)
					fangle -= 360;
				if (fangle == 90) {
					y = 1000000000;
					x = 0;
				}
				else if (fangle == 270 or fangle == -90) {
					y = -1000000000;
					x = 0;
				}
				else if (fangle == 180 or fangle == -180) {
					y = 0;
					x = -1000000000;
				}
				else if (fangle == 0) {
					y = 0;
					x = 1000000000;
				}
				else {
					y = (slop * 1000000000);
					x = 1000000000;
				}
				if (fangle > 90 and fangle < 180) {
					x *= -1;
					y *= -(1.0);
				}
				else if (fangle > 180 and fangle < 270) {
					x *= -1;
					y *= -(1.0);
				}
				ll limit = 2000000000;
				// cout << x << " h " << abs(y) << endl;
				while (abs(y) > limit) {
					y /= 10;
					x /= 10;
				}
				// while (val != slop) {
				// 	slop *= 10;
				// 	val = slop;
				// 	x *= 10;
				// }

				// f(k, 0, n) {
				// 	cout << arr2[k][0] << " " << arr2[k][1] << "  ";
				// }
				// cout << endl;

				// cout << endl;
				// cout << x << " h " << y << endl;
				if (check(x, y)) {
					cout << x << " " << y << endl;
					return;
				}
				if (check(x, y - 1)) {
					cout << x << " " << y - 1 << endl;
					return;
				}
				if (check(x, y + 1)) {
					cout << x << " " << y + 1 << endl;
				}
				if (check(x - 1, y)) {
					cout << x - 1 << " " << y << endl;
					return;
				}
				if (check(x - 1, y - 1)) {
					cout << x - 1 << " " << y - 1 << endl;
					return;
				}
				if (check(x - 1, y + 1)) {
					cout << x - 1 << " " << y + 1 << endl;
					return;
				}
				if (check(x + 1, y)) {
					cout << x + 1 << " " << y << endl;
					return;
				}
				if (check(x + 1, y - 1)) {
					cout << x + 1 << " " << y - 1 << endl;
					return;
				}
				if (check(x + 1, y + 1)) {
					cout << x + 1 << " " << y + 1 << endl;
					return;
				}
			}
		}
	}
	cout << "0 0" << endl;

}

///////////////////////////////////////////////////

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

///////////////////////////////////////////////////