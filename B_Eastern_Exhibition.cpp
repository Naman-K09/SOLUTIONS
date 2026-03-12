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
    vector<ll> x(n);
    vector<ll> y(n);
    for(ll i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
    }

    sort(x.begin(), x.end());
    ll x_count;
    if(!(n&1)) {
        x_count = x[n/2] - x[n/2 - 1] + 1;
    }
    else {
        cout << 1 << endl;
        return;
    }
    sort(y.begin(), y.end());
    ll y_count;
        y_count = y[n/2] - y[n/2 - 1] + 1;

    cout << x_count*y_count << endl;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}