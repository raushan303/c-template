#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <map>
using namespace std;

int flag = 0;
long long readInt(long long l, long long r, char endd) {
	flag += 1;
	long long x = 0;
	int cnt = 0;
	int fi = -1;
	bool is_neg = false;
	while (true) {
		char g = getchar();
		if (g == '-') {
			assert(fi == -1);
			is_neg = true;
			continue;
		}
		if ('0' <= g && g <= '9') {
			x *= 10;
			x += g - '0';
			if (cnt == 0) {
				fi = g - '0';
			}
			cnt++;
			assert(fi != 0 || cnt == 1);
			assert(fi != 0 || is_neg == false);
			assert(!(cnt > 19 || ( cnt == 19 && fi > 1) ));
		} else if (g == endd) {
			if (is_neg) {
				x = -x;
			}
			assert(l <= x && x <= r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l, int r, char endd) {
	string ret = "";
	int cnt = 0;
	while (true) {
		char g = getchar();
		assert(g != -1);
		if (g == endd) {
			break;
		}
		cnt++;
		ret += g;
	}
	assert(l <= cnt && cnt <= r);
	return ret;
}
long long readIntSp(long long l, long long r) {
	return readInt(l, r, ' ');
}
long long readIntLn(long long l, long long r) {
	return readInt(l, r, '\n');
}
string readStringLn(int l, int r) {
	return readString(l, r, '\n');
}
string readStringSp(int l, int r) {
	return readString(l, r, ' ');
}

int main()
{
	int T = readIntLn(1, 30); // Ensures that an integer in the range [1, 3] is inputted, and that there is a New Line (Ln) right after that. This needs Unix-style line endings (ie. \n instead of \r\n). So generate the test files on an Unix machine (eg. Linux, Mac).
	int count = 0;
	while (T--) {
		int n = readIntLn(1, 1000);
		for (int i = 1; i < n; i++) {
			readIntSp(1, 1000);
			readIntLn(1, 1000);
		}
		for (int i = 1; i <= n; i++) {
			if (i == n) {
				readIntLn(1, 1000);
			} else {
				readIntSp(1, 1000);
			}
		}
	}
	assert(getchar() == -1); // Ensures that there are no extra characters at the end.
	cerr << "SUCCESS\n"; // You should see this on the http://campus.codechef.com/files/stderr/SUBMISSION_ID page, at the bottom.
}