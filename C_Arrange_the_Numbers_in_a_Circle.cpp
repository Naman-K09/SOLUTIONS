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
    ll n;
    cin >> n;
    vector<ll> a(n);

    ll ans = 0;
    ll count_ones = 0;
    ll count_ones_og = 0;
    for(auto & i : a) {
        cin >> i;
        if(i > 1) ans += i;
        else count_ones++, count_ones_og++;
    }

    if(n == 1) {
        cout << (a[0] > 2 ? a[0] : 0) << '\n';
        return;
    }

    for(auto& i : a) {
        ll count =  i;
        if(count >= 4) {
            ll can_be_taken = (count / 2) - 1;

            ans += min(can_be_taken, count_ones);
            count_ones -= can_be_taken;

            if(count_ones <= 0) break;
        }
    }

    if(count_ones_og == n - 1 && count_ones > 0) ans++;

    cout << ans << '\n';
}

int main() {
    fast_io

    ll tt;
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
//     ll n;
//     cin >> n;
//     vector<ll> c(n);
//     for(ll i = 0; i < n; i++) cin >> c[i];

//     sort(c.begin(), c.end());

//     if(n == 1) {
//         cout << c[0] << '\n';
//         return;
//     }

//     ll count = 0;
//     ll j = n - 1, i = 0;
//     while(i <= j) {
//         if(c[i] == 1) {
//             if(c[j] > 3) {
//                 c[j] -= 4;
//                 count += 5;
//                 i++;
//             }
//             else {
//                 if(c[j] > 1) count += c[j];
//                 j--;
//             }
//         }
//         else {
//             for(int k = i; k <= j; k++) {
//                 count += c[k];
//             }
//             break;
//         }
//     }

//     cout << count << '\n';
//     return;
// }

// int main() {
//     fast_io
//     ll tt;
//     cin >> tt;
//     while(tt--) solve();
//     return 0;
// }