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
    vector<pair<pair<int, int>, int>> range(n);
    for(int i = 0; i < n; i++) {
        cin >> range[i].first.first;
        cin >> range[i].first.second;
        range[i].second = i;
    }

    sort(range.begin(), range.end());

    vector<int> ans(n);
    int check = n;
    int max_r = -1;
    for(int i = 1; i < n; i++) {
        max_r = max(max_r, range[i-1].first.second);
        if(max_r < range[i].first.first) {
            check = i;
            break;
        }
    }

    for(int i = 0; i < check; i++) {
        ans[range[i].second] = 1;
    }
    for(int i = check; i < n; i++) {
        ans[range[i].second] = 2;
    }

    if(check == n) {
        cout << -1 << endl;
    }
    else {
        for(int& i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }

}


int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}