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

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];

//     vector<int> dp(n + 1, 1e9);
//     dp[n] = 0;

//     for(int i = n-1; i >= 0; i--) {
//         int not_take = 1 + dp[i+1];

//         int take = 1e9;
//         if(i + a[i] + 1 <= n) {
//             take = dp[i + a[i] + 1];
//         }
        
//         dp[i] = min(take, not_take);    
//     }

//     cout << dp[0] << endl;
// }


int f(int i, int n, vector<int>& a, vector<int>& dp) {
    if(i == n) return 0;
    if(i > n)return 1e9;

    if(dp[i] != -1) return dp[i];

    int take = f(i + a[i] + 1, n, a, dp);
    int not_take = 1 + f(i+1, n, a, dp);

    return dp[i] = min(take, not_take);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int maxi = *max_element(a.begin(), a.end());
    vector<int> dp(n +  + 2, -1);
    int ans = min(f(0, n, a,  dp), f(0, n, a,  dp));

    cout << ans << endl;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}





