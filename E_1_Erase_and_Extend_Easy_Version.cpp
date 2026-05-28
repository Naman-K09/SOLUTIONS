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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    while(s.size() != 1 && s.back() == s[0]) s.pop_back();
    n = s.length();

    int idx = n;
    for(int i = 1; i < n; i++) {
        if(s[i] > s[0]) {
            idx = i;
            break;
        }
        else if(s[i] == s[0]) {
            int hinge_idx = i;
            int j = 0;
            while(i < n && s[i] == s[j]) {
                i++, j++;
            }
            if(i < n && s[i] > s[j]) {
                idx = hinge_idx;
                break;
            }
        }
    }

    string ans = s.substr(0, idx);

    while(ans.length() < k) {
        ans += ans;
    }

    while(ans.length() > k) {
        ans.pop_back();
    }

    cout << ans << endl;
    return;
}

int main() {
    fast_io
    solve();
    return 0;
}