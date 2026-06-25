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

bool solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    // we will try to match both string by value value from front and extension of 0 and 1 from back.
    // store all indices of 0's and 1's.
    vector<int> ones, zeroes;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == '0') zeroes.push_back(i);
        else ones.push_back(i);
    }

    string a_ = a;
    bool possible1 = true;
    for(int i = 0; i < n; i++) {
        if(a_[i] == b[i]) {
            continue;
        }

        // here a_[i-1] will be last matched value :).
        int last_matched = a_[0] - '0';
        if(i > 0) {
            last_matched = a_[i-1] - '0';
        }

        // next idx of 1 and 0.
        auto it0 = upper_bound(zeroes.begin(), zeroes.end(), i);
        auto it1 = upper_bound(ones.begin(), ones.end(), i);

        int next_zero = 1e9, next_one = 1e9;
        if(it0 != zeroes.end()) next_zero = *it0;
        if(it1 != ones.end()) next_one = *it1;

        int needed = b[i] - '0';
        if((needed && (next_zero <= next_one) && !last_matched) || (!needed && (next_zero >= next_one) && last_matched)) {
            possible1 = false;
            break;
        }
        else a_[i] = b[i];
    }

    bool possible2 = true;
    for(int i = n-1; i >= 0; i--) {
        if(a[i] == b[i]) {
            continue;
        }

        // here a[i-1] will be last matched value :).
        int last_matched = a[n-1] - '0';
        if(i < n-1) {
            last_matched = a[i+1] - '0';
        }

        // next idx of 1 and 0.
        auto it0 = lower_bound(zeroes.begin(), zeroes.end(), i);
        auto it1 = lower_bound(ones.begin(), ones.end(), i);

        int next_zero = -1e9, next_one = -1e9;
        if(it0 != zeroes.begin()) next_zero = *prev(it0);
        if(it1 != ones.begin()) next_one = *prev(it1);

        int needed = b[i] - '0';
        if((needed && (next_zero >= next_one) && !last_matched) || (!needed && (next_zero <= next_one) && last_matched)) {
            possible2 = false;
            break;
        }
        else a[i] = b[i];
    }

    if(possible1 || possible2) return 1;

    return 0;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    return 0;
}