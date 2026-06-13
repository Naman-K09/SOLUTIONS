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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(auto& i : a) cin >> i;

    sort(a.begin(), a.end());

    ll bonus = 0;
    ll target = x;

    int l = 0, r = n - 1;

    ll curr_sum = 0;
    vector<ll> ans;
    while(l <= r) {
        if(curr_sum + a[r] >= target) {
            curr_sum += a[r];
            bonus += a[r];
            target += x;
            ans.push_back(a[r]);
            r--;   

            continue;
        }

        curr_sum += a[l];
        ans.push_back(a[l]);
        l++;
    }

    cout << bonus << '\n';

    for(ll& i : ans) cout << i << " ";
    cout << '\n';
}

int main() {
    fast_io

    int tt;
    cin >> tt;
    while(tt--) {

        solve();

    }
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

// void solve() {
//     ll n, x;
//     cin >> n >> x;
//     vector<ll> a(n);
//     vector<ll> prefix(n);
//     for(auto& i : a) cin >> i;

//     sort(a.begin(), a.end());

//     for(int i = 0; i < n; i++) {
//         if(i == 0) {
//             prefix[i] = a[i];
//         }
//         else {
//             prefix[i] = prefix[i-1] + a[i];
//         }
//     }

//     ll bonus = 0;
//     ll curr_val = 0;
//     for(int i = 0; i < n; i++) {
//         ll val = prefix[i] / x;
//         if(val > curr_val) {
//             bonus += a[i];
//             curr_val = val;
//         }
//     }

//     cout << bonus << '\n';

//     for(ll& i : a) cout << i << " ";
//     cout << '\n';
// }

// int main() {
//     fast_io

//     int tt;
//     cin >> tt;
//     while(tt--) {

//         solve();

//     }
//     return 0;
// }































// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// ll int_sqrt(ll n) {
//     ll low = 0, high = n, ans = 0;
//     while (low <= high) {
//         ll mid = low + (high - low) / 2;
//         if (mid * mid <= n) {
//             ans = mid;
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }
//     return ans;
// }

// ll int_pow(ll a, ll b) {
//     ll res = 1;
//     while (b > 0) {
//         if (b % 2) res *= a;
//         a *= a;
//         b /= 2;
//     }
//     return res;
// }

// void solve() {
//     int n, X;
//     cin >> n >> X;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];

//     sort(a.begin(), a.end());
//     ll l = 0;
//     ll r = n - 1;
//     ll bonus = 0;
//     ll target = X;
//     bool flag = true;
//     vector<int> res;
    
//     while(l <= r) {
//         if(target <= a[r]) {
//             bonus += a[r];
//             target = X;
//             flag = false;
//             res.push_back(a[r]);
//             r--;
//         }
//         else {
//             target -= a[l];
//             res.push_back(a[l]);
//             l++;
//         } 
//     }

//     cout << bonus << endl;

//     for(int i : res) {
//         cout << i << " ";
//     }

//     cout << endl;
// }

// int main() {
//     int tt;
//     cin >> tt;
//     while(tt--) solve();
//     return 0;
// }