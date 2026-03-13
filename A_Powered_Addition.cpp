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

// TC O(N);
// SC O(1);
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll maxi = -1;
    for(int i = 1; i < n; i++) {
        if(a[i-1] > a[i]) {
            maxi = max(maxi, a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }

    cout << ( maxi == -1  ? 0 : 63 - __builtin_clzll(maxi) + 1 ) << endl;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}



















// TC : O(NlogN) 
// SC : O(2*42) 
// vector<ll> precompute(42, 0);
// vector<ll> precompute_prefix(42, 0);

// void solve() {
//     ll n, ans = 0, val = -1e9, lowest = 1e9;
//     cin >> n;
//     bool check = false;
//     vector<ll> a(n);
//     for(ll i = 0; i < n; i++){
//         cin >> a[i];
//         if(i > 0 && a[i-1] > a[i] && !check) {
//             val = a[i-1], check = true; 
//             lowest = min(lowest, a[i]);
//         }
//         else if(check) lowest = min(lowest, a[i]);
//         if(check && a[i] >= val) {
//             check = false;
//             ll target = val - lowest;
//             auto it = lower_bound(precompute_prefix.begin(), precompute_prefix.end(), target);
//             ans = max(ans, 1LL * distance(precompute_prefix.begin(), it));
//             lowest = 1e9;
//         } 
//     }

//     if(check) {
//             ll target = val - lowest;
//             auto it = lower_bound(precompute_prefix.begin(), precompute_prefix.end(), target);
//             ans = max(ans, 1LL * distance(precompute_prefix.begin(), it));
//     }

//     cout << ans << endl;
// }

// int main() {
//     fast_io

//     for(ll i = 1; i < 42; i++) precompute[i] = 1ll << (i-1);
//     for(ll i = 1; i < 42; i++) precompute_prefix[i] = precompute_prefix[i-1] + precompute[i];

//     ll tt;
//     cin >> tt;
//     while(tt--) solve();
//     return 0;
// }