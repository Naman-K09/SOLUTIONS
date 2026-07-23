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


int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        ll sum = 0;
        bool possible = true;
        for(int i = 0; i < n; i++) {
            ll x; cin >> x;
            sum += x;
            ll check = (i+1) *(i+2)/2;
            if(sum < check) {
                possible = false;
            }
        }

        if(possible) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}