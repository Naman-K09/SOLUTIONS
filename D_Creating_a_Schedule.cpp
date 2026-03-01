#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];

    sort(a.begin(), a.end());
    vector<pair<ll, ll>> floors;

    int idx = 0;
    int check = n;
    while(n > 0) {
        ll first = a[idx];
        ll second = a[m - 1 - idx];
        floors.push_back({first, second});

        idx++;
        n = n - 2;
    }

    for(auto& i : floors) {
        for(int j = 0; j < 3; j++) {
            cout << i.first << " " << i.second << " ";
        }
        cout << endl;
        if(check > 1) {
            for(int j = 0; j < 3; j++) {
                cout << i.second << " " << i.first << " ";
            }
            cout << endl;
        }
        check -= 2;
    }
}

int main() {
    fast_io;
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}