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

const ll mod = 1e9 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll count = 0;

    vector<int> prefix(n-1, 1);

    for(int j = 0; j < k; j++) {
        if(j == 0) {
            count = (count + 1) % mod;
            continue;
        } 
        else if(j == 1) {
            count = (count + n) % mod;
            continue;
        }
        for(int i = 0; i < n - 1; i++) {
            if(i > 0) {
                prefix[i] = (prefix[i] + prefix[i-1]) % mod;
            }
            count = (count + prefix[i]) % mod;
        }
        reverse(prefix.begin(), prefix.end());
    }

    cout << count << endl;
    return;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}