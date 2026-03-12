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

// Tabulation
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> curr(2, 0);
    vector<int> next2(2, 0);
    vector<int> next1(2, 0);

    for(int i = n - 1; i >= 0; i--) {
        for(int dost = 0; dost < 2; dost++) {
            int one = ((a[i] == 1 && dost) ? 1 : 0) +  next1[!dost];
            int two = ((a[i] == 1 && dost) ? 1 : 0) + ((i + 1 < n && a[i+1] && dost) == 1 ? 1 : 0) + next2[!dost];

            curr[dost] = min(one, two);
        }
        next2 = next1;
        next1 = curr;
    }

    int count = next1[1];

    cout << count << endl;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}

// Memoization
// int f(int i, int n, vector<int>& a, vector<vector<int>>& dp, bool dost) {
//     if(i >= n) return 0;

//     if(dp[i][dost] != -1) return dp[i][dost];

//     int one = ((a[i] == 1 && dost) ? 1 : 0) +  f(i+1, n, a, dp, !dost);
//     int two = ((a[i] == 1 && dost) ? 1 : 0) + ((i + 1 < n && a[i+1] && dost) == 1 ? 1 : 0) + f(i+2, n, a, dp, !dost);

//     return dp[i][dost] = min(one, two);
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];

//     vector<vector<int>> dp(n+2, vector<int> (2, -1));
//     bool dost = true;
//     int count = f(0, n, a, dp, dost);

//     cout << count << endl;
// }