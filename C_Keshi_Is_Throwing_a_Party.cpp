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

int mid;
vector<pair<int, int>> a;

bool check() {
    int poor_needed = 0, rich_needed = mid - 1, count = 0;

    for(int i = 0; i < a.size(); i++) {
        int rich = a[i].first;
        int poor = a[i].second;
        
        if(poor >= poor_needed && rich >= rich_needed) {
            count++;
            poor_needed++;
            rich_needed--;

            if(count >= mid) return true;
        }
        
    }
    
    return count >= mid;
}

void solve() {
    int n;
    cin >> n;
    a.clear();
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    int low = 1, high = n, ans = 1;
    while(low <= high) {
        mid = (low + high) / 2;

        if(check()) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
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