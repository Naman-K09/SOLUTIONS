#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define error cout << "Hare Krishna" << endl;

bool ispossible(vector<int> a, int& mid, string& s, int& k) {
    bool window_on = false;
    int window_count = 0;
    
    for(int i = 0; i < a.size(); i++) {
        if(s[i] == 'R' && window_on && a[i] > mid) window_on = false;
        else if(s[i] == 'B' && !window_on && a[i] > mid) window_on = true, window_count++;
    }

    return window_count <= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int low = 0, high = *max_element(a.begin(), a.end());
    int ans = 0;

    while(low <= high) {
        int mid = (low + (high - low) / 2);

        if(ispossible(a, mid, s, k)) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
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