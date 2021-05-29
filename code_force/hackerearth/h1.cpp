using namespace std;
#include<bits/stdc++.h>
typedef long long ll;
#define int long long
#define ff first
#define ss second
#define md 1000000007
#define md1 998244353
#define pb push_back
#define in insert
#define mkp make_pair
#define f(i,yha,wha) for(ll i=yha;i<wha;i++)
#define rf(i,wha,yha) for(ll i=wha;i>=yha;i--)
#define f0(n) for(ll i=0;i<n;i++)
#define f1(n) for(ll i=1;i<=n;i++)
#define fg(i,yha,wha,gap) for(ll i=yha;i<wha;i+=gap)
#define mpll map<ll,ll>
#define len(p) (ll)p.size()
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mem(a,t) memset(a,t,sizeof(a))
#define endl "\n"
#define ar array
#define vl vector<ll>
#define vpll vector<pair<ll,ll>>



int N, Q;

// Variables, that hold current "state" of computation
long long current_answer;
long long cnt[500500];

// Array to store answers (because the order we achieve them is messed up)
long long answers[500500];
int BLOCK_SIZE;
int arr[500500];
ll h[500500];
ll vis[500500];
// We will represent each query as three numbers: L, R, idx. Idx is
// the position (in original order) of this query.
pair< pair<int, int>, int> queries[100500];


// Essential part of Mo's algorithm: comparator, which we will
// use with std::sort. It is a function, which must return True
// if query x must come earlier than query y, and False otherwise.
inline bool mo_cmp(const pair< pair<int, int>, int> &x, const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if (block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

ll hpy[500500];



void flash()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll m;

void solve()
{


    cin >> N >> m;

    BLOCK_SIZE = sqrt(N);

    // Read input array
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    f(i, 1, N + 5)
    hpy[i] = 1;

    f(i, 1, m + 1)
    cin >> h[i];

    cin >> Q;

    // Read input queries, which are 0-indexed. Store each query's
    // original position. We will use it when printing answer.
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    // Sort queries using Mo's special comparator we defined.
    sort(queries, queries + Q, mo_cmp);

    // Set up current segment [mo_left, mo_right].
    int mo_left = 0, mo_right = -1;

    ll tot = 0;



    for (int i = 0; i < Q; i++) {
        // [left, right] is what query we must answer now.
        int left = queries[i].first.first - 1;
        int right = queries[i].first.second - 1;

        // Usual part of applying Mo's algorithm: moving mo_left
        // and mo_right.
        while (mo_right < right) {
            mo_right++;
//            add(arr[mo_right]);
            cnt[arr[mo_right]]++;

            if (hpy[arr[mo_right]] == 1 and cnt[arr[mo_right]] < h[arr[mo_right]])
            {
                tot--;
                hpy[arr[mo_right]] = 0;
            }
            if (cnt[arr[mo_right]] == h[arr[mo_right]] and hpy[arr[mo_right]] == 0)
            {
                tot++;
                hpy[arr[mo_right]] = 1;
            }
            if (hpy[arr[mo_right]] == 1 and cnt[arr[mo_right]] > h[arr[mo_right]])
            {
                tot--;
                hpy[arr[mo_right]] = 0;
            }

        }
        while (mo_right > right) {
            cnt[arr[mo_right]]--;

            if (hpy[arr[mo_right]] == 1 and cnt[arr[mo_right]] < h[arr[mo_right]])
            {
                tot--;
                hpy[arr[mo_right]] = 0;
            }
            if (cnt[arr[mo_right]] == h[arr[mo_right]] and hpy[arr[mo_right]] == 0)
            {
                tot++;
                hpy[arr[mo_right]] = 1;
            }
            if (hpy[arr[mo_right]] == 1 and cnt[arr[mo_right]] > h[arr[mo_right]])
            {
                tot--;
                hpy[arr[mo_right]] = 0;
            }

            if (cnt[arr[mo_right]] == 0)
            {
                if (hpy[arr[mo_right]] == 0)
                {
                    tot++;
                    hpy[arr[mo_right]] = 1;
                }
            }



            mo_right--;
        }

        while (mo_left < left) {
            cnt[arr[mo_left]]--;

            if (hpy[arr[mo_left]] == 1 and cnt[arr[mo_left]] < h[arr[mo_left]])
            {
                tot--;
                hpy[arr[mo_left]] = 0;
            }
            if (cnt[arr[mo_left]] == h[arr[mo_left]] and hpy[arr[mo_left]] == 0)
            {
                tot++;
                hpy[arr[mo_left]] = 1;
            }
            if (hpy[arr[mo_left]] == 1 and cnt[arr[mo_left]] > h[arr[mo_left]])
            {
                tot--;
                hpy[arr[mo_left]] = 0;
            }

            if (cnt[arr[mo_left]] == 0)
            {
                if (hpy[arr[mo_left]] == 0)
                {
                    tot++;
                    hpy[arr[mo_left]] = 1;
                }
            }

            mo_left++;
        }
        while (mo_left > left) {
            mo_left--;
            cnt[arr[mo_left]]++;

            if (hpy[arr[mo_left]] == 1 and cnt[arr[mo_left]] < h[arr[mo_left]])
            {
                tot--;
                hpy[arr[mo_left]] = 0;
            }
            if (cnt[arr[mo_left]] == h[arr[mo_left]] and hpy[arr[mo_left]] == 0)
            {
                tot++;
                hpy[arr[mo_left]] = 1;
            }
            if (hpy[arr[mo_left]] == 1 and cnt[arr[mo_left]] > h[arr[mo_left]])
            {
                tot--;
                hpy[arr[mo_left]] = 0;
            }
        }

        // Store the answer into required position.
//        cout<<left<<" "<<right<<" "<<queries[i].second<<" "<<tot<<endl;
        if (tot == 0)
            answers[queries[i].second] = 1;
        else
            answers[queries[i].second] = 0;

    }
//  cout<<endl;
    // We output answers *after* we process all queries.
    for (int i = 0; i < Q; i++)
        cout << answers[i] << "\n";






}


int32_t main()
{
    flash();
    int t;
    t = 1;
//  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
