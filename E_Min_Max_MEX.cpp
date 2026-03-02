#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define error cout << "Hare Krishna" << endl;

// bool ispossible(vector<int>& a, int n, int k, int m) {
//     vector<bool> nums(n, false);

//     int count = 0;
//     int curr_mex = 0;

//     for(int i = 0; i < n; i++) {
//        if(a[i] < n) nums[a[i]] = true;
//         while(curr_mex < n && nums[curr_mex]) curr_mex++;

//        if(curr_mex >= m) {
//             count++;
//             int j = 0;
//             while(j < n && nums[j]) nums[j] = false, j++;
//             curr_mex = 0;
//        }
//     }

//     return count >= k;
// }

bool ispossible(vector<int>& a, int& n, int& k, int& mid) {
    unordered_set<int> nums;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] < mid) {
            nums.insert(a[i]);
        }

        if(nums.size() == mid) {
            count++;
            nums.clear();
        }
    }

    return count >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int low = 0;
    int high = 1e9;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(ispossible(a, n, k, mid)) low = mid + 1;
        else high = mid - 1;
    }

    cout << high << endl;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}