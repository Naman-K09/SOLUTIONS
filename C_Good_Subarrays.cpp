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

    vector<ll> p(n);
    p[0] = s[0] - '0';
    for(ll i = 1; i < n; i++) {
        p[i] = p[i-1] + (s[i] - '0');
    }

    
    map<ll, ll> mp;
    mp[1] = 1;
    for(ll i = 0; i < n; i++) {
        mp[p[i] - i]++;
    }

    ll ans = 0;
    for(auto i : mp) {
        ans += i.second*(i.second-1)/2;
    }

    cout << ans << endl;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}