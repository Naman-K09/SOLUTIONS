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

map<int, vector<int>> adj;

// This only works when We have perfect cycle no messy web.
// Isiliye odd even hojayega, kyunki jiss node se shuru kiya ussi pe khtm krenge.
// A weird way or trial to find odd or even cycle.
bool dfs (int i, vector<int>& vis, bool cycle, int par) {
    vis[i] = 1;

    bool len = !cycle; // cycle false means even.
    for(auto& node : adj[i]) {
        if(vis[node] == 2 || node == par) continue;
        if(vis[node] == 1) {
            if(len) return true; // len true mean even.
            else return false;
        }

        len = dfs(node, vis, len, i);
    }

    vis[i] = 2;
    return len;
}

void solve() {
    adj.clear();

    int n;
    cin >> n;
    bool fault = 0;
    vector<int> degree(n + 1, 0);

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);

        degree[x]++, degree[y]++;

        if(x == y) fault = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(degree[i] > 2) fault = true;
    }

    if(fault) {
        cout << "NO" << "\n";
        return;
    }

    vector<int> vis(n+1, 0);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = true;

            bool odd_length = dfs(i, vis, false, -1);

            if(odd_length) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
    return;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}