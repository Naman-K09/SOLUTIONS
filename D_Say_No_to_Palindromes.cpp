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
vector<string> vec; 

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    vector<vector<int>> prefix(6, vector<int> (n + 1, 0));
    for(int j = 0; j < 6; j++) {
        string check = vec[j];
        string check_ = "";

        for(int i = 0; i < (n + 2) / 3 ; i++) {
            check_ += check;
        }

        while(check_.length() > n) {
            check_.pop_back();
        }

        for(int i = 0; i < n; i++) {
            prefix[j][i + 1] = prefix[j][i] + (s[i] != check_[i] ? 1 : 0);
        }
    }
    
    

    while(m--) {
        int l, r;
        cin >> l >> r;

        int ans = INT_MAX;
        for(int j = 0; j < 6; j++) {
            ans = min(ans, prefix[j][r] - prefix[j][l-1]);
        }

        cout << ans << "\n";
    }

    return;
}

int main() {
    fast_io

    vec = {"abc", "acb", "bac", "bca", "cab", "cba"};
    solve();
    return 0;
}