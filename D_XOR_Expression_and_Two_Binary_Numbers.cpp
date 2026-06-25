#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    ll n, k;
    cin >> n >> k;
    string s1, s2;
    cin >> s1 >> s2;

    ll count_x_one = 0; 
    ll count_y_one = 0; 
    ll count_z_one = 0;
    
    for(ll i = 0; i < n; i++) {
        ll x = s1[i] - '0';
        ll y = s2[i] - '0';

        if(x) count_x_one++;
        if(y) count_y_one++;
        if(x^y) count_z_one++;
    }

    ll sz = (1LL << k) - 1; 
    ll count_x = 0, count_y = 0, count_z = 0;

    if (k % 2 == 0) {
        count_x = sz / 3;
        count_y = sz / 3;
        count_z = sz / 3;
    } else {
        count_x = (sz - 1) / 3;
        count_y = (sz - 1) / 3;
        count_z = (sz - 1) / 3 + 1;
    }
    
    count_x++;
    count_y++;

    ll x_contri = count_x * count_x_one * (n - count_x_one);
    ll y_contri = count_y * count_y_one * (n - count_y_one);
    ll z_contri = count_z * count_z_one * (n - count_z_one);

    ll ans = x_contri + y_contri + z_contri;

    cout << ans << "\n";
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}