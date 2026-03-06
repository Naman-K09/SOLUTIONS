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
    string s;
    cin >> s;
    ll q;
    cin >> q;

    ll countplus = 0;
    for(ll i = 0; i < n; i++) {
        if(s[i] == '+') countplus++;
    }
    ll countminus = n - countplus;

    if(countminus == countplus) {
        while(q--) cout << "YES" << endl;
        return;
    }

    while(q--) {
        ll a, b;
        cin >> a >> b;

        if (countplus == countminus) {
            cout << "YES\n";
            continue;
        }
        if (a == b) {
            cout << "NO\n";
            continue;
        }

        ll num = b * (countminus - countplus);
        ll den = a-b;
        ll D = num / den;
            
        if(num % den == 0 && D >= -countminus && D <= countplus) {
            cout << "YES\n"; 
            continue;
        }
        cout << "NO\n";
    }
}

int main() {
    solve();
    return 0;
}