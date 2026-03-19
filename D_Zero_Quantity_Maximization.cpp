#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<pair<ll, ll>, ll> ans;
    int count = 0;
    ll maxi = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (b[i] == 0) count++;
        } else {
            ll num = -b[i];
            ll den = a[i];
            
            ll common = abs(gcd(num, den));
            num /= common;
            den /= common;

            if (den < 0) {
                num = -num;
                den = -den;
            }

            ans[{num, den}]++;
            maxi = max(maxi, ans[{num, den}]);
        }
    }

    cout << maxi + count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}