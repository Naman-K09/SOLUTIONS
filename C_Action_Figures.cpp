#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define error cout << "Hare Krishna" << endl;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll count = 0;
    for(ll i = n - 1; i >= 0; i--) {
        if(s[i] == '1') count++;
        else count = max(0ll, count - 1);
    }

    count = (count + 1) / 2;

    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        if(count && s[i] == '1') ans += (i+1), count--;
        else if(s[i] == '0') ans += (i+1);
    }

    cout << ans << endl;
}

int main() {
    fast_io
    ll tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}