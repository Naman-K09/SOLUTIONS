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
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> _xor(n+1);
    for(int i = 1; i <= n; i++) {
        _xor[i] = i;
        if(i == r) _xor[i] = _xor[l-1];
    }

    vector<int> a(n+1);

    a[1] = _xor[1];
    for(int i = 2; i <= n; i++) {
        a[i] = _xor[i]^_xor[i-1];
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    cout << '\n';
    return;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}