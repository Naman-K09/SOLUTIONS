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

int ans;

int dfs(int node, int p, vector<vector<int>>& adj) {
    int sz = 1;
    for(auto& i : adj[node]) {
        if(i == p) continue;

        sz += dfs(i, node, adj);
    }

    if(!(sz & 1)) {
        ans++;
        sz = 0;
    }
    return sz;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n&1) {
        cout << -1 << endl;
        return;
    }

    ans = 0;

    dfs(1, -1, adj);

    cout << --ans << endl;
    return;
}

int main() {
    fast_io
    solve();
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

// vector<bool> vis;
// int ans;

// int dfs(int node, vector<vector<int>>& adj) {
//     vis[node] = true;

//     int sz = 1;
//     for(auto& i : adj[node]) {
//         if(vis[i]) continue;

//         sz += dfs(i, adj);
//     }

//     if(!(sz & 1)) {
//         ans++;
//         sz = 0;
//     }
//     return sz;
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<vector<int>> adj(n+1);
//     for(int i = 1; i < n; i++) {
//         int u, v;
//         cin >> u >> v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     vis.clear();
//     vis.assign(n+1, false);

//     if(n&1) {
//         cout << -1 << endl;
//         return;
//     }

//     ans = 0;

//     dfs(1, adj);

//     cout << --ans << endl;
//     return;
// }

// int main() {
//     fast_io
//     solve();
//     return 0;
// }


