#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

// PBDS Ordered Set: s.find_by_order(k), s.order_of_key(x)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    vector<ll> pref(n);
    ll total_sum = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
        pref[i] = total_sum; 
    }
    
    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--; // CRITICAL FIX: Convert 1-based Codeforces input to 0-based index
    }
    
    sort(b.begin(), b.end());
    
    ll min_subarray_sum = 0; 
    ll max_prev_pref = -1e18; // Start infinitesimally small
    
    for(int j = 0; j < m; j++) {
        int R = b[j];
        int L = b[j]; 
        
        // The value we are allowed to subtract is pref[L-1]
        ll current_L_pref = (L > 0) ? pref[L - 1] : 0;
        
        // Keep track of the most beneficial (largest) prefix we can subtract
        max_prev_pref = max(max_prev_pref, current_L_pref);
        
        // Calculate the smallest subarray sum ending at R
        ll current_subarray_sum = pref[R] - max_prev_pref;
        
        // Track the absolute most negative subarray found so far
        min_subarray_sum = min(min_subarray_sum, current_subarray_sum);
    }
    
    // Total sum minus twice the flipped negative subarray
    ll ans = total_sum - 2 * min_subarray_sum;
    
    cout << ans << '\n';
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}