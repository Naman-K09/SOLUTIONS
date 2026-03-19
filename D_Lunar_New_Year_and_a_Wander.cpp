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

set<int> options;
vector<bool> vis;
vector<int> ans;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis.clear();
    vis.assign(n + 1, false);
    ans.clear();
    options.clear();

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        vis[node] = true;
        ans.push_back(node);

        for(auto& i : adj[node]) {
            if(vis[i]) continue;

            options.insert(i);
        }

        if(options.size() == 0) break;
        int next = *options.begin();
        options.erase(options.begin());
        q.push(next);
    }

    for(int& i : ans) {
        cout << i << " ";
    }

    cout << endl;
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

// set<int> options;
// vector<bool> vis;
// vector<int> ans;

// void dfs(int node, vector<vector<int>>& adj) {
//     vis[node] = true;
//     ans.push_back(node);

//     for(auto& i : adj[node]) {
//         if(vis[i]) continue;

//         options.insert(i);
//     }

//     if(options.size() == 0) return;
//     int next = *options.begin();
//     options.erase(options.begin());
//     dfs(next, adj);
// }

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);

//     for(int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     vis.clear();
//     vis.assign(n + 1, false);
//     ans.clear();
//     options.clear();

//     dfs(1, adj);

//     for(int& i : ans) {
//         cout << i << " ";
//     }

//     cout << endl;
// }

// int main() {
//     fast_io
//     solve();
//     return 0;
// }