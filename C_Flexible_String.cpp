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

vector<string> combos;

void build_combos(ll i, vector<char>& v, ll& k, string s) {
    if(s.length() == k) { // If maximum character allowed has been taken.
        combos.push_back(s);
        return;
    }
    if(i >= v.size()) return;


    //Take
    build_combos(i+1, v, k, s + v[i]);
    // Move
    build_combos(i+1, v, k, s);
}

void solve() {
    ll n, k;
    cin >> n >> k; // k <= 10
    string a, b;
    cin >> a >> b;

    // GENERATE COMBOS
    vector<char> v;
    for(ll i = 0; i < n; i++) { // Taking char to built combos
        if(find(v.begin(), v.end(), a[i]) == v.end()) {
            v.push_back(a[i]);
        }
    }

    combos.clear(); // clear for garbage value.
    string s = ""; // We build on this.
    ll max_chars_to_take = min(k, (ll)v.size());
    build_combos(0, v, max_chars_to_take, s); // To build all combos.

    // Try each combo and find the maximum lr count.
    ll count = 0; // final ans
    for(string s : combos) {
        string new_string = "";

        // new_string built.
        for(ll i = 0; i < n; i++) {
            bool found = find(s.begin(), s.end(), a[i]) != s.end(); // check the curr a[i] is present in trial string.
            if(found) { // if yes, make a[i] = b[i];
                new_string += b[i];
            } else new_string += a[i];
        }

        // Now evaluate lr count.
       ll curr_count = 0; 
       ll len = 0;

        for(ll i = 0; i < n; i++) {
            if(new_string[i] == b[i]) {
                len++; 
            } else {
                curr_count += (len * (len + 1)) / 2;
                len = 0;
            }
        }

        // when r goes beyond n, but still there are segments.
        curr_count += (len)*(len+1) / 2; // add the curr_count

        count = max(count, curr_count);
    }

    cout << count << endl;
    return;
}

int main() {
    fast_io
    ll tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}