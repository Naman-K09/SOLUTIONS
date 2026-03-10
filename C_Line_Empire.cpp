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

ll calculation(ll mid, vector<ll>& suffix, vector<ll>& c, ll& a, ll& b, ll& n) {
    return b * ((mid == n ? 0 : suffix[mid+1]) - (n-mid-1)*c[mid]) + a * c[mid];
}

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> c(n+1);
    c[0] = 0;
    for(ll i = 1; i <= n; i++) cin >> c[i];   

    vector<ll> suffix(n+1, c[n]);
    for(ll i = n-1; i >= 0; i--) {
        suffix[i] = suffix[i+1] + c[i];
    }

    ll low = 0, high = n;
    while(high - low > 3) {
        ll mid1 = low + (high - low) / 3;
        ll mid2 = high - (high - low) / 3;

        if(calculation(mid1, suffix, c, a, b, n) < calculation(mid2, suffix, c, a, b, n)) {
            high = mid2;
        }
        else low = mid1;
    }

    ll ans = 2e18;
    for(ll i = low; i <= high; i++) {
        ans = min(ans, calculation(i, suffix, c, a, b, n));
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

// void solve() {
//     ll n, a, b;
//     cin >> n >> a >> b;
//     vector<ll> c(n+1);
//     c[0] = 0;
//     for(ll i = 1; i <= n; i++) cin >> c[i];

//     vector<ll> suffix(n+1, c[n]);
//     for(ll i = n - 1; i >= 0; i--) {
//         suffix[i] = suffix[i+1] + c[i];
//     }

//     ll ans = 1e18;
//     for(int i = 0; i <= n; i++) {
//             ll check = b * ((i == n ? 0 : suffix[i+1]) - (n-i-1)*c[i]) + a * c[i];
//             ans = min(check, ans);
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