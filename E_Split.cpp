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

ll solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    unordered_map<ll, ll> mpp;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        mpp[a[i]]++;
    }

    for(auto& i : mpp) { // If any of the elements doesnot have frequency perfectly
        if(i.second % k != 0) { // divisible by k means we can't equally divide them llo k multiset.
            return 0;
        }
    }

    // since we have checked the validity, now we need to check for counts :)

    ll count = 0;

    ll l = 0, r = 0;
    unordered_map<int, int> curr_window;
    while(r < n) {
        curr_window[a[r]]++;

        while(curr_window[a[r]] > (mpp[a[r]] / k)) { // since each we cannot have more than / k freqquency in first multiset :)
            curr_window[a[l]]--;
            l++;
        }

        count += r - l + 1;
        r++;
    }


    return count;
}

int main() {
    fast_io

    ll tt;
    cin >> tt;
    while(tt--) {

        cout << solve() << '\n';;

    }
    return 0;
}


































// #include <bits/stdc++.h>
// using namespace std ;

// int main() {
//     int tt;
//     cin >> tt;

//     while(tt--) {
//         int n, k;
//         cin >> n >> k;

//         int arr[n];
//         for(int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }

//         bool divisible = true;
//         vector<int> cnt(n+1, 0);
//         for(int x : arr) cnt[x]++;

//         for(int i = 1; i <= n; i++) {
//             if(cnt[i] % k != 0) {
//                 divisible = false;
//                 break;
//             }
//         }
//         if(!divisible) {
//             cout << 0 << endl; 
//             continue;
//         }

//         vector<int> lim(n+1, 0);
//         for(int i = 1; i <= n; i++) lim[i] = cnt[i]/k;

//         vector<int> inside(n+1, 0);
        
//         long long ans = 0;
//         int l = 0, bad = 0;

//         for(int r = 0; r < n; r++) {
//             int val = arr[r];
//             inside[val]++;

//             if(inside[val] == lim[val]+1) bad++;

//             while(bad > 0 && l <= r) {
//                 int leftval = arr[l];
//                 if(inside[leftval] == lim[leftval] + 1) bad--;
//                 inside[leftval]--;
//                 l++;
//             }
//             ans += r - l + 1; 
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }