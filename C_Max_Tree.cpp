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

struct edge {
    int u, v, x, y;
};

void solve() {
    int n;
    cin >> n;
    vector<edge> e(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> e[i].u >> e[i].v >> e[i].x >> e[i].y;
        e[i].u--, e[i].v--;
    }

    vector<int> p(n, 1e9);
    int l = 1, h = 2;
    for(int k = 0; k < n - 1; k++) {
        int i = e[k].u;
        int j = e[k].v;
        int cost_1 = e[k].x;
        int cost_2 = e[k].y;

        if(cost_1 < cost_2) {
            if(p[i] != 1e9 && p[j] != 1e9 && p[i] > p[j]) {
                swap(p[i], p[j]);
            }

            if(p[i] == 1e9) {
                p[i] = l;
                l--;
            }
            if(p[j] == 1e9) {
                p[j] = h;
                h++;
            }
        }
        else {

            if(p[i] != 1e9 && p[j] != 1e9 && p[i] < p[j]) {
                swap(p[i], p[j]);
            }

            if(p[i] == 1e9) {
                p[i] = h;
                h++;
            }
            if(p[j] == 1e9) {
                p[j] = l;
                l--;
            }
        }
    }

    int to_add = 1 - *min_element(p.begin(), p.end());

    for(int i = 0; i < n; i++) {
        cout << p[i] + to_add << " \n"[i == n - 1];
    }

    return;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}




































// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// struct edge {
//     int u, v, x, y;
// };

// void solve() {
//     int n;
//     cin >> n;

//     vector<vector<int>> adj(n);
//     vector<int> degree(n, 0);
//     vector<edge> inputs(n-1);
    
//     for(auto &e : inputs) {
//         cin >> e.u >> e.v >> e.x >> e.y;
//         e.u--, e.v--;
        
//         if(e.x > e.y) adj[e.v].push_back(e.u), degree[e.u]++;
//         else adj[e.u].push_back(e.v), degree[e.v]++;
//     }
    
//     queue<int> q;
//     for(int i = 0; i < n; i++) {
//         if(degree[i] == 0) q.push(i);
//     }
    
    
//     vector<int> sol(n);
//     for(int i = 1; i <= n; i++) {
//         int u = q.front();
//         sol[u] = i;
//         q.pop();
        
//         for(const auto &node : adj[u]) {
//             degree[node]--;
//             if(degree[node] == 0) q.push(node);
//         }
//     }

//     for(int x : sol) cout << x << " ";
//     cout << endl;
// }

// int main() {
//     int tt;
//     cin >> tt;
//     while(tt--) solve();
//     return 0;
// }