#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define error cout << "Hare Krishna" << endl;

// PBDS Ordered Set: s.find_by_order(k), s.order_of_key(x)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// should we just use dp, huh ?
// lets try.
// lets try with bool swap variable.

const ll MOD = 998244353;
vector<int> a, b;
vector<vector<int>> dp;

ll f(int idx, bool prev_swapped) {
    if(idx >= a.size()) {
        return 1;
    }

    if(dp[idx][prev_swapped] != -1) return dp[idx][prev_swapped];
    int prev_a, prev_b;
    if(prev_swapped) {
        prev_a = b[idx-1];
        prev_b = a[idx-1];
    }
    else {
        prev_a = a[idx-1];
        prev_b = b[idx-1];
    }

    int curr_a = a[idx];
    int curr_b = b[idx];

    int ways = 0;
    if(curr_a >= prev_a && curr_b >= prev_b) {
        ways = (ways + f(idx + 1, false)) % MOD; // no swap
    }

    if(curr_a >= prev_b && curr_b >= prev_a) {
         ways = (ways + f(idx + 1, true)) % MOD; // swap
    }

    return dp[idx][prev_swapped] = ways;
}


void solve() {
    int n;
    cin >> n;
    a.clear(), b.clear(), dp.clear();
    a.resize(n), b.resize(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    dp.assign(n+1, vector<int> (2, -1));
    ll ans = f(1, true) % MOD;
    ans = (ans + f(1, false)) % MOD;

    cout << ans << '\n';
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}