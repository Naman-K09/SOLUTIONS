#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define error cout << "Hare Krishna" << endl;

// PBDS Ordered Set: s.find_by_order(k), s.order_of_key(x)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<int> ispalindrome;
const int MOD = 1e9 + 7;

void solve(vector<int>& curr) {
    int n;
    cin >> n;

    cout << curr[n] << '\n';
}

int32_t main() {
    fast_io

    for(int i = 1; i <= 4e4; i++) {
        string s = to_string(i);
        int l = 0, r = s.size() - 1;
        bool check = true;
        while(l < r) {
            if(s[l] != s[r]) {
                check = false;
                break;
            }

            l++, r--;
        }

        if(check) ispalindrome.push_back(i);
    }

    vector<int> curr(4e4+1, 0), next(4e4 + 1, 0);
    curr[0] = 1;
    next[0] = 1;
    for(int j = (int)ispalindrome.size() - 1; j >= 0; j--) {
        for(int i = 1; i <= 4e4; i++) {
             int notpick = next[i];

            int pick = 0;
            if(i - ispalindrome[j] >= 0) {
                pick = curr[i - ispalindrome[j]];
            }

            curr[i] = (pick + notpick) % MOD;
        }
        next = curr;
    }

    int tt;
    cin >> tt;
    while (tt--) {
        solve(curr);
    }
    return 0;
}
































// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define int long long
// #define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define error cout << "Hare Krishna" << endl;

// // PBDS Ordered Set: s.find_by_order(k), s.order_of_key(x)
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// vector<int> ispalindrome;
// const int MOD = 1e9 + 7;

// int f(int i, int val, vector<vector<int>>& dp) {
//     if(val == 0) return 1;
//     if(i >= ispalindrome.size()) return 0;

//     if(dp[val][i] != -1) return dp[val][i];

//     int notpick = f(i+1, val, dp);

//     int pick = 0;
//     if(val - ispalindrome[i] >= 0) {
//         pick = f(i, val - ispalindrome[i], dp);
//     }

//     return dp[val][i] = (pick + notpick) % MOD;
// }

// void solve(vector<vector<int>>& dp) {
//     int n;
//     cin >> n;

//     cout << dp[n][0] << '\n';
// }

// int32_t main() {
//     fast_io

//     for(int i = 1; i <= 4e4; i++) {
//         string s = to_string(i);
//         int l = 0, r = s.size() - 1;
//         bool check = true;
//         while(l < r) {
//             if(s[l] != s[r]) {
//                 check = false;
//                 break;
//             }

//             l++, r--;
//         }

//         if(check) ispalindrome.push_back(i);
//     }

//     vector<vector<int>> dp(4e4+1, vector<int> (ispalindrome.size() + 1, -1));
//     for(int i = 1; i <= 4e4; i++) {
//         f(0, i, dp);
//     }

//     int tt;
//     cin >> tt;
//     while (tt--) {
//         solve(dp);
//     }
//     return 0;
// }