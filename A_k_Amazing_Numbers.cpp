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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> check(n+1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        check[a[i]].push_back(i);
    }

    vector<int> ans(n+1, 1e9);
    for(int i = 0; i <= n; i++) {
        if(check[i].empty()) continue;

        int prev = -1;
        int atmost = -1;
        for(int& j : check[i]) {
            atmost = max(j - prev, atmost);
            prev = j;
        }
        atmost = max(n - prev, atmost);
        if(atmost != -1) {
            ans[atmost] = min(ans[atmost], i);
        }
    }

    int prev = 1e9;
    for(int i = 1; i <= n; i++) {
        prev = min(ans[i], prev);

        ans[i] = (prev == 1e9 ? -1 : prev);
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    fast_io
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}