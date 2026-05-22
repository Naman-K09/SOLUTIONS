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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<char, int>> freq(26);

    for(int i = 0; i < 26; i++) {
        freq[i].first = 'a' + i;
        freq[i].second = 0;
    }

    for(int i = 0; i < n; i++) {
        freq[s[i] - 'a'].second++;
    }

    sort(freq.rbegin(), freq.rend(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    int optimial_char = 1;
    int changed = n;
    for(int i = 1; i <= 26; i++) {
        if (n % i) continue;

        int char_allowed = i;
        int freq_allowed = n / i;
        int unchange = 0;

        for(int j = 0; j < char_allowed; j++) {
            unchange += min(freq_allowed, freq[j].second);
        }

        if(changed > n - unchange) {
            optimial_char = i;
            changed = n - unchange;
        }
    }

    // Construct a string;
    string ans(n, ' ');
    map<char, int> mpp;
    for(int i = 0; i < optimial_char; i++) {
        mpp[freq[i].first] = n / optimial_char;
    } 

    for(int i = 0; i < n; i++) {
        if(mpp[s[i]]) {
            ans[i] = s[i];
            mpp[s[i]]--;
        }
    }

    for(int i = 0; i < n; i++) {
        if(ans[i] != ' ') continue;

        while(!mpp.empty() && (*mpp.begin()).second == 0) mpp.erase(mpp.begin());
        ans[i] = (*mpp.begin()).first;
        mpp[(*mpp.begin()).first]--;
    }

    cout << changed << '\n' << ans << '\n';
    return;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}