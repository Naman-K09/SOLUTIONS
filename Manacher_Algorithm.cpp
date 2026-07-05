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

struct manacher {
    vector<int> p;

    void run_manacher(string t) {
        int n = t.length();
        p.clear();
        p.assign(n, 1);
        int l = 1, r = 1;

        for(int i = 1; i < n; i++) {
            p[i] = max(0, min(r - i, p[r + l - i]));

            while(i + p[i] < n && i - p[i] >= 0 && t[i + p[i]] == t[i - p[i]]) {
                p[i]++;
            }

            if(i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
        for(auto v : p) {
            cout << v << " ";
        }
    
        cout << '\n';
    }


    void build (string s) {
        string t = "@";

        for(auto v : s) {
            t += string("#") + v;
        }
        run_manacher(t + "#");
    }

    int getlongest(int cen, bool odd) {
        int pos = 2*cen + 1 + (!odd);

        return p[pos] - 1;
    }

    bool checkPalin(int l, int r) {
        if(r-l+1 <= getlongest((l+r)/2, l%2 == r%2)) {
            return 1;
        }
        else return 0;
    }
    
}m;

void solve() {
    string s = "babbabbabc";
    m.build(s);
}

int main() {
    fast_io
    solve();
    return 0;
}