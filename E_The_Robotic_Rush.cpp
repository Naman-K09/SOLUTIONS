#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> robots(n);
    for(int i = 0; i < n; i++) cin >> robots[i];
    vector<ll> spikes(m);
    for(int i = 0; i < m; i++) cin >> spikes[i];

    string s;
    cin >> s;

    vector<bool> dead(n, false);
    sort(spikes.begin(), spikes.end());
    map<int, vector<int>> deadondistance;
    
    for(int  i = 0; i < n; i++) {
        auto it = lower_bound(spikes.begin(), spikes.end(), robots[i]);
        if(it != spikes.end()) {
            deadondistance[*(it) - robots[i]].push_back(i);
        }

        if(it != spikes.begin()) {
            deadondistance[-(robots[i] - *prev(it))].push_back(i);
        }
    }

    ll count = 0, alive = n;
    for(char &c : s) {
        if(c == 'L') count--;
        else count++;

        for(int &i : deadondistance[count]) {
            if(dead[i]) continue;
            dead[i] = true;

            alive--;
        }
        deadondistance[count].clear();
        cout << alive << " ";
    }

    cout << endl;
}

int main() {
    fast_io;
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}