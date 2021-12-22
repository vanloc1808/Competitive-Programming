/**
 *    author:    vanloc1808
 *    created:   22-12-2021   17:46:10
**/

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef float fl;
typedef double db;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fillArray(a, n, t) for (int i = 0; i < n; i++) {a[i] = t}
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front

const long long INF = 2e18;
const long long MOD = 1000000007;
const double PI = 3.14159;
const double EPSILON = 1e-6;

long long solve() {
    int x, n;
    cin >> x >> n;

    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        s.insert(x);
    }

    vector<int> a(s.begin(), s.end());

    n = a.size();

    vector<long long> dp(x + 1);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - a[i] >= 0) {
                dp[j] = dp[j] + dp[j - a[i]];
            }
        }
    }

    return dp[x];
}

int main() {
    fastio;

    cout << solve() << "\n";

    return 0;
}