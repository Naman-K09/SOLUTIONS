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
    int n, q;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    cin >> q;


    int xor0 = 0, xor1 = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '0') xor0 ^= a[i];
        else xor1 ^= a[i];
    }

    vector<int> prefix_xor(n+1, a[0]);
    prefix_xor[0] = 0;
    for(int i = 1; i < n; i++) prefix_xor[i+1] = prefix_xor[i] ^ a[i];

    while(q--) {
        int type;
        cin >> type;

        if(type == 2) {
            int g;
            cin >> g;
            if(g) cout << xor1 << " ";
            else cout << xor0 << " ";
        }
        else {
            int l, r;
            cin >> l >> r;
            xor0 = xor0 ^ prefix_xor[r] ^ prefix_xor[l-1];
            xor1 = xor1 ^ prefix_xor[r] ^ prefix_xor[l-1];
        }
    }

    cout << "\n";
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}