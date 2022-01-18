/**
 *    author:    vanloc1808
 *    created:   13-10-2021   19:56:30
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

int solve() {
    int n;
    cin >> n;
    
    vi a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int i = 0;
    for (i = n - 1; i > 0; i--) {
        if (a[i - 1] > a[i]) {
            break;
        }
    }
    return i;
}

int main()
{
    fastio;
    
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    cout << solve() << "\n";
    
    return 0;
}