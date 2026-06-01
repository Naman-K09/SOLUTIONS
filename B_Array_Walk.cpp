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
    ll n, k, z;
    cin >> n >> k >> z;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll max_pairs = 0;
    ll ans = 0;
    ll current_sum = 0;

    for(int i = 0; i <= k; i++) {
        current_sum += a[i];
        
        if(i > 0) max_pairs = max(max_pairs, a[i] + a[i-1]);

        ll rem = min(z, (k - i) / 2);

        ll score = (current_sum) + (rem * max_pairs);

        if (z > rem && (k - i) % 2 == 1 && i > 0) {
            score += a[i - 1];
        }

        ans = max(ans, score);
    }

    cout << ans << endl;
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

// ll count_z, k;
// vector<ll> a;
// vector<ll> prefix;

// void solve() {
//     ll n, k_, z;
//     cin >> n >> k_ >> z;

//     count_z = z, k = k_;

//     a.resize(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
//     //-------------------------------------

//     prefix.clear();
//     prefix.resize(n);
//     prefix[0] = a[0];
//     for(int i = 1; i < n; i++) {
//         prefix[i] = prefix[i-1] + a[i];
//     }

//     //-------------------------------------

//     ll ans = 0;
//     for(int idx = 0; idx <= k; idx++) {
//         if(k - idx < count_z) {
//             count_z = k - idx;
//         } 

//         ll point_to_reverse = prefix[idx];
//         ll k_rem = k - idx;
//         ll contri_1 = min((k_rem + 1) / 2, count_z) ;
//         ll contri_2 = (k_rem >= 2*contri_1) ? contri_1 : contri_1 - 1;
//         k_rem = k_rem - contri_1 - contri_2;
//         if(idx > 0 && contri_1) {
//             point_to_reverse += (contri_1 * a[idx - 1] + contri_2 * a[idx]);
//             point_to_reverse += prefix[idx + k_rem] - prefix[idx];
//         }

//         ans = max(point_to_reverse, ans);
//     }

//     cout << ans << endl;
// }

// int main() {
//     fast_io

//     int tt;
//     cin >> tt;
//     while(tt--) solve();

//     return 0;
// }
































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

// ll count_z, k;
// vector<ll> a;
// vector<ll> prefix;
// vector<ll> dp;

// ll max_sum(ll idx) {
//     if(idx > k) return 0;

//     if(dp[idx] != -1) return dp[idx];

//     if(k - idx < count_z) {
//         count_z = k - idx;
//     } 

//     ll point_to_reverse = a[idx];
//     ll k_rem = k - idx;
//     ll contri_1 = min((k_rem + 1) / 2, count_z) ;
//     ll contri_2 = (k_rem >= 2*contri_1) ? contri_1 : contri_1 - 1;
//     k_rem = k_rem - contri_1 - contri_2;
//     if(idx > 0 && contri_1) {
//         point_to_reverse += (contri_1 * a[idx - 1] + contri_2 * a[idx]);
//         point_to_reverse += prefix[idx + k_rem] - prefix[idx];
//     }

//     ll just_add = a[idx] + max_sum(idx + 1);

//     return dp[idx] = max(point_to_reverse, just_add);
// }

// void solve() {
//     ll n, k_, z;
//     cin >> n >> k_ >> z;

//     count_z = z, k = k_;

//     a.resize(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
//     //-------------------------------------

//     prefix.clear();
//     prefix.resize(n);
//     prefix[0] = a[0];
//     for(int i = 1; i < n; i++) {
//         prefix[i] = prefix[i-1] + a[i];
//     }

//     //-------------------------------------
//     dp.clear();
//     dp.assign(n, -1);

//     ll ans = max_sum(0);
//     cout << dp[0] << endl;
// }

// int main() {
//     fast_io

//     int tt;
//     cin >> tt;
//     while(tt--) solve();

//     return 0;
// }