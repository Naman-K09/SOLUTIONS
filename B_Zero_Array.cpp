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
    int n;
    cin >> n;

    ll total_sum = 0;
    ll max_element = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        total_sum += x;
        max_element = max(max_element, x);
    }


    if (total_sum % 2 == 0 && max_element <= total_sum - max_element) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    fast_io
    solve();
    return 0;
}