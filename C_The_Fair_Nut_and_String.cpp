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

ll mod = 1e9 + 7;

int main() {
    fast_io

    string s;
    cin >> s;

    ll ans = 0;
    ll prev_count = 0; 
    for (char c : s) {
        if (c == 'a') {
            ans = (ans + prev_count + 1) % mod;
        } 
        else if (c == 'b') {
            prev_count = ans;
        }
    }

    cout << ans << endl;
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

// ll mod = 1e9 + 7;

// int main() {
//     fast_io

//     string s;
//     cin >> s;

//     ll combinational_a_count = 0;
//     ll a_count = 0;
//     bool b_present = true;
//     vector<ll> count;

//     for(ll i = 0; i < s.size(); i++) {
//         if(s[i] == 'a') {
//             a_count++;count.push_back(combinational_a_count);
//             b_present = false;
//         }
//         else if(s[i] == 'b' && !b_present) {
//             b_present = true;
//             combinational_a_count = a_count;
//         }
//     }

//     if(!count.size()) {
//         cout << 0 << endl;
//         return 0;
//     }
//     ll check = count[0];
//     vector<ll> size;
//     ll sz = 0;
//     for(ll& i : count) {
//         if(i == check) sz++;
//         else {
//             size.push_back(sz);
//             check = i;
//             sz = 1;
//         }
//     }
//     size.push_back(sz);

//     ll ans = 1;
//     for(ll& i : size) {
//         ans = (ans*(++i))%mod;
//     }

//     cout << ((ans-1) % mod) << endl;
//     return 0;
// }