#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t, n, p, k, x;

	cin >> t;
	while (t--)
	{

		cin >> n >> x >> p >> k;
		int a[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		sort(a + 1, a + n + 1);

		if (a[p] == x) {
			cout << "0" << endl;
			continue;
		}

		if ((p < k) or (p == k and a[p] > x)) {
			int ind = n + 10;
			for (int i = k; i > 0; i--) {
				if (a[i] > x)
					ind = i;
			}
			if (ind <= p) {
				cout << p - ind + 1 << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if ((p > k) or (p == k and a[p] < x)) {
			int ind = 0;
			for (int i = k ; i <= n; i++) {
				if (a[i] < x)
					ind = i;
			}
			if (ind >= p) {
				cout << ind - p + 1 << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
	}
	return 0;
}

