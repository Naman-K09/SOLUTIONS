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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        
        // Check for first K elements only.
        bool check = true;
        for(int i = 0; i < k; i++) {
            int c1 = 0, c0 = 0;
            for(int j = i; j < n; j += k) {
                if(s[j] == '1') c1++;
                else if(s[j] == '0') c0++;
            }
            
            if(c1 && c0) {
                check = false;
                break;
            }
            if(c1) {
                for(int j = i; j < n; j += k) s[j] = '1';
            } else if(c0) {
                for(int j = i; j < n; j += k) s[j] = '0';
            }
        }

        if(!check) {
            cout << "NO" << '\n';
            continue;
        }
        
        // check for first window.
        int c1 = 0, c0 = 0;
        for(int i = 0; i < k; i++) {
            if(s[i] == '1') c1++;
            else if(s[i] == '0') c0++;
        }
        
        if(c1 <= k/2 && c0 <= k/2) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}