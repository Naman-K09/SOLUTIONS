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
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    // calculating prefix sum to check the contribution range of certain a[i].
    vector<ll> prefix(n, b[0]);
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + b[i];
    }

    // Initialize answer as all contributes to their fullest.
    vector<ll> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i] = (i+1) * b[i];
    }

    // Initialize as all contributes but stores where the contribution stops.
    vector<ll> contribution_decrease(n,0);

    for(int i = 0; i < n; i++) {
        // Check for lower bounds for range of contribution.
        ll target = a[i] + (i > 0 ? prefix[i-1] : 0); 
        auto it = lower_bound(prefix.begin(), prefix.end(), target);

        // increase the lower bound index in contribution_decrease.
        ll idx = distance(prefix.begin(), it);
        if(idx < n) {
            contribution_decrease[idx]++;

            // Add the last contribution at lower_bound index.
            ans[idx] += target - (idx > 0 ? prefix[idx-1] : 0);
        }
    }

    // Now remove the extra contributions from ans vector.
    ll count = 0; // This counts how many contribution are there to be removed.
    for(int i = 0; i < n; i++) {
        count += contribution_decrease[i]; 

        ans[i] -= count*b[i];
    }

    for(ll& i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}