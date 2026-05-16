// Solution for Snowy Hills Problem

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

int lsb(int curr) {
    int ans = 1;
    while(curr % ans != 0) ans *= 2;

    return ans;
}

int find(int curr, int& target, int &h, int &k) {
    if(curr >= target) return k*(curr - target);

    int jump = lsb(curr);
    if(curr + jump < target) return find(curr + jump, target, h, k);

    return min(find(curr+jump, target, h, k), find(curr + 1, target, h, k));
}

void solve() {
    int n, h, k, ans = 0;
    cin >> n >> h >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> n;

    for(int i = 0; i < n - 1; i++) {
        ans += find(a[i], a[i+1], h, k);
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