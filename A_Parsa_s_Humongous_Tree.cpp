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
vector<pair<ll,ll>> lr;
vector<vector<ll>> adj;
vector<vector<ll>> dp;

ll f(ll idx, bool state, ll par) {
    ll l = 0, r = 0;

    if(dp[state][idx] != -1) return dp[state][idx];

    ll val = (state) ? lr[idx].second : lr[idx].first;

    ll total = 0;
    for(auto& node : adj[idx]) {
        if(node == par) continue;

        l = abs(val -  lr[node].first) + f(node, 0, idx);
        r = abs(val -  lr[node].second) + f(node, 1, idx);

        total += max(l, r);
    }

    return dp[state][idx] = total;
}

void solve() {
 // ----------------------INPUTS----------------------------

    ll n;
    cin >> n;

    lr.clear();
    lr.resize(n+1);
    adj.clear();
    adj.resize(n+1);

    for(ll i = 1; i <= n; i++) {
        cin >> lr[i].first >> lr[i].second;
    }

    for(ll i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    // ----------------------LOGIC----------------------------

    dp.clear();
    dp.assign(2, vector<ll>(n+1, -1));
    ll sum_1 = f(1, 0, -1);
    ll sum_2 = f(1, 1, -1);

    cout << max(sum_1, sum_2) << endl;
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
// vector<pair<ll,ll>> lr;
// vector<vector<ll>> adj;
// vector<vector<ll>> dp;

// ll f(ll idx, bool state, ll par) {
//     ll l = 0, r = 0;

//     if(dp[state][idx] != -1) return dp[state][idx];

//     ll val = (state) ? lr[idx].second : lr[idx].first;

//     ll total = 0;
//     for(auto& node : adj[idx]) {
//         if(node == par) continue;

//         l = abs(val -  lr[node].first) + f(node, 0, idx);
//         r = abs(val -  lr[node].second) + f(node, 1, idx);

//         total += max(l, r);
//     }

//     return dp[state][idx] = total;
// }

// void solve() {
//  // ----------------------INPUTS----------------------------

//     ll n;
//     cin >> n;

//     lr.clear();
//     lr.resize(n+1);
//     adj.clear();
//     adj.resize(n+1);

//     for(ll i = 1; i <= n; i++) {
//         cin >> lr[i].first >> lr[i].second;
//     }

//     for(ll i = 0; i < n - 1; i++) {
//         ll x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
    
//     // ----------------------LOGIC----------------------------

//     dp.clear();
//     dp.assign(2, vector<ll>(n+1, -1));
//     ll sum_1 = f(1, 0, -1);
//     ll sum_2 = f(1, 1, -1);

//     cout << max(sum_1, sum_2) << endl;
// }

// int main() {
//     fast_io
//     int tt;
//     cin >> tt;
//     while(tt--) solve();
//     return 0;
// }