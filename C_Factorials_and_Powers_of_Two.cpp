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

vector<ll> factorial(17, 1);

ll pops(ll n) {
    return __builtin_popcountll(n);
}

ll bit(ll n) {
    return 63 - __builtin_clzll(n);
}

void solve() {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> sum(1 << 17);
    sum[0] = {0, 0};
    for(int i = 1; i < (1 << 17); i++) {
        int first_bit = bit(i);
        sum[i].first = sum[i ^ (1 << first_bit)].first + factorial[first_bit];
        sum[i].second = pops(i);
    }

    ll res = pops(n);
    for(auto i : sum) {
        if(i.first <= n) {
            res = min(res, i.second + pops(n - i.first));
        }
    }

    cout << res << endl;
}

int main() {
    fast_io
    for(int i = 2; i < 17; i++) factorial[i] = factorial[i-1]*i; 

    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}