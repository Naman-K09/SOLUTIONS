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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<bool> dp(n+1, false);
    dp[0] = true;

    for(int i = 1; i <= n; i++) {
        if(dp[i-1] && i + a[i-1] <= n) dp[i+a[i-1]] = true;
        if(i - a[i-1] - 1 >= 0) dp[i] = (dp[i] || dp[i-a[i-1]-1]);
    }

    cout << (dp[n] ? "YES" : "NO") << '\n';
    return;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}


































// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define ll long long
// #define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define error cout << "Hare Krishna" << endl;

// // PBDS Ordered Set: s.find_by_order(k), s.order_of_key(x)
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// bool check(int idx, bool isprevlen, vector<int>& b, string s, vector<vector<int>>& dp) {
//     if(idx == b.size()) return isprevlen;
//     if(idx > b.size()) return false;

//     if(dp[isprevlen][idx] != -1) return dp[isprevlen][idx];

//     bool use_this = false;
//     if(isprevlen) {
//         s += to_string(idx + b[idx] + 1);
//         use_this = check(idx + b[idx] + 1, true, b, s, dp);
//     }
//     else {
//         if(s.back() - '0' == -1 || s.back() - '0' == idx - b[idx] - 1) {
//             s += to_string(idx);
//             use_this = check(idx + 1, true, b, s, dp);
//         }
//     }

//     bool not_use_this = check(idx + 1, false, b, s, dp);

//     return dp[isprevlen][idx] = (use_this || not_use_this);
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> b(n);
//     for(int i = 0; i < n; i++) cin >> b[i];

//     vector<vector<int>> dp(2, vector<int> (n+1, -1));
//     string s = "-1";
//     cout << (check(0, true, b, s, dp) ? "YES" : "NO") << '\n';
//     return;
// }

// int main() {
//     fast_io
//     int tt;
//     cin >> tt;
//     while(tt--) solve();
//     return 0;
// }