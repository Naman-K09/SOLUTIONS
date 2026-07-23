#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> p(n);
    for(auto& i : p) cin >> i;

    int g = gcd(x, y);

    for(int i = 0; i < n; i++) {
        int dis = abs(p[i] - 1 - i);

        if(dis % g) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}