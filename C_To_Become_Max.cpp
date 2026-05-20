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

bool ispossible(ll val, int n, ll k, vector<int>& a) {
    for(int i = 0; i < n; i++) {
        ll change = k;
        ll target = val;
        bool success = false;
        
        for(int j = i; j < n; j++) {
            if(a[j] >= target) {
                success = true;
                break;
            }
            if(j == n - 1) {
                break;
            }

            change -= (target - a[j]);

            if(change < 0) {
                break;
            }
            target--; 
        }
        if(success) return true;
    }

    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int low = *max_element(a.begin(), a.end());
    int high = low + k, mid;

    while(low <= high) {
        mid = high + (low - high) / 2;

        if(ispossible(mid, n, k, a)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << high << '\n';
    return;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}























// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define ll long long
// #define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define error cout << "Hare Krishna" << endl;

// // PBDS Ordered Set: s.find_by_order(k), s.order_of_key(x)
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// int f(int i, int k, vector<int>& a, int& n, int maxi, int stay, int prev) {
//     if(k == 0 || i < 0) return maxi;

//     int move = f(i-1, k, a, n, maxi, 1, a[i] + stay - 1);

//     if ((a[i] + stay - 1) <= prev) {
//         maxi = max(maxi, a[i] + stay);
//         return max({f(i, k - 1, a, n, maxi, stay + 1, prev), f(i-1, k - 1, a, n, maxi, 1, a[i] + stay), move});
//     } 

//     return move;
// }

// void solve() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];

//     int maxi = *max_element(a.begin(), a.end());
//     cout << f(n-2, k, a, n, maxi, 1, a[n-1]) << '\n';
//     return;
// }

// int main() {
//     fast_io
//     int tt;
//     cin >> tt;
//     while(tt--) solve();
//     return 0;
// }