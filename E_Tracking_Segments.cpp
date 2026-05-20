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

bool possible(int mid, vector<pair<int, int>> segements, int n, vector<int> one_order) {
    vector<int> mark(n, 0);
    for(int i = 0; i <= mid; i++) {
        mark[one_order[i]] = 1; 
    }

    vector<int> pref_mark(n, 0);
    pref_mark[0] = mark[0];
    for(int i = 1; i < n; i++) {
        pref_mark[i] = pref_mark[i-1] + mark[i];
    }

    for(int i = 0; i < segements.size(); i++) {
        int l = segements[i].first;
        int r = segements[i].second;

        int len = (r - l + 1) / 2;
        int ones = pref_mark[r] - pref_mark[l];
        if(mark[l] == 1) ones++;

        if(ones > len) return true;
    }

    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> segments(m);
    for(int i = 0; i < m; i++) {
        cin >> segments[i].first >> segments[i].second;
        segments[i].first--;
        segments[i].second--;
    }

    int q;
    cin >> q;
    vector<int> one_order(q);
    for(int i = 0; i < q; i++) {
        cin >> one_order[i];
        one_order[i]--;
    }

    int low = 0, high = q-1, ans = -1;
    while(low <= high) {
        int mid = high + (low - high)/2;

        if(possible(mid, segments, n, one_order)) {
            ans = mid + 1; // we are using 0-based, question is 1-based.
            high = mid - 1;
        }
        else low = mid + 1;
    }

    cout << ans << '\n';
    return;
}
int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}