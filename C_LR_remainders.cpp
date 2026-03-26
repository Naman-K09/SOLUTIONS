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


int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s;
        cin >> s;

        vector<ll> ans;
        int l = 0, r = n - 1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') ans.push_back(a[l]), l++;
            else ans.push_back(a[r]), r--;
        }

        reverse(ans.begin(), ans.end());
        ll multiply = 1;
        vector<ll> solution;
        for(ll& i : ans) {
           multiply = (multiply * i) % m;
            solution.push_back(multiply);
        }

        reverse(solution.begin(), solution.end());
        for(ll& i : solution) {
            cout << i << " ";
        }

        cout << '\n';
    }
    return 0;
}