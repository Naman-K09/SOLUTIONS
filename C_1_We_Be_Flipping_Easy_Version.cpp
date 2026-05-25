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
    for(ll i = 0; i < n; i++) cin >> a[i];

    vector<ll> ans;
    bool parity = true;
    ll mul = 1;
    for(ll i = n - 1; i >= 0; i--) {
        if(mul*a[i] > 0) {
            ans.push_back(i+1);
            if(parity) {
                parity = false;
                mul = -1;
            }
            else {
                parity = true;
                mul = 1;
            }
        }
    }

    cout << ans.size() << endl;
    for(ll& i : ans) cout << i << " ";
    cout << endl;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}