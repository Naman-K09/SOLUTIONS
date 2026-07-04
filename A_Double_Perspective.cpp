#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define error cout << "Hare Krishna" << endl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct curr_Segment {
    int start, end;
};

struct Element {
    int first, second, id;
};

bool cmp(const Element& x, const Element& y) {
    if(x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

void solve() {
    int n; cin >> n;
    vector<Element> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].id = i + 1;
    }
    sort(a.begin(), a.end(), cmp);
    
    vector<int> indices;
    indices.push_back(a[0].id);

    curr_Segment seg;
    seg.start = a[0].first;
    seg.end = a[0].second;

    for(int i = 1; i < n; i++) {
        int curr_front = a[i].first;
        int curr_back = a[i].second;

        if(curr_front > seg.end) {
            indices.push_back(a[i].id);
            seg.start = curr_front;
            seg.end = curr_back;
        }
        else {
            if(curr_back <= seg.end) continue; 

            indices.push_back(a[i].id);
            seg.end = curr_back;
        }
    }

    cout << indices.size() << '\n';
    for(int i = 0; i < indices.size(); i++) {
        cout << indices[i] << " \n"[i == (int)indices.size() - 1];
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




































// CODE 1 :

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// void solve() {
//     int n;
//     int a[1000010], b[1000010];
//     cin >> n;

//     for(int i = 0; i <= n; i++) cin >> a[i] >> b[i];

//     vector<int> tag(n+4, 1), ans;

//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= n; j++) {
//             if(i == j) continue;
//             if(a[j] <= a[i] && b[i] <= b[j]) tag[i] = 0;
//         }
//         if(tag[i]) ans.push_back(i);
//     }

//     cout << ans.size() << endl;
//     for(auto& i : ans) {
//         cout << i << " ";
//     }

//     cout << '\n';
//     return;
// }

// int main() {
//     int tt;
//     cin >> tt;
//     while(tt--) solve();
//     return 0;
// }





// CODE 2 :
// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// struct edge {
//     int x, y;
// };

// void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, set<int> nodes, int& cyclesize) {
//     vis[node] = 1;
//     nodes.erase(node);

//     for(auto& adjnode : adj[node]) {
//         if(!vis[adjnode]) dfs(adjnode, adj, vis, nodes, cyclesize);
//     }
// }

// void solve() {
//     int n;
//     cin >> n;
    
//     vector<edge> inputs(n-1);
//     vector<vector<int>> adj(2*n);
//     set<int> nodes;
//     vector<int> vis(2*n, 0);
//     int components = 0;
//     for(auto& e : inputs) {
//         cin >> e.x >> e.y;

//         nodes.insert(e.x);
//         nodes.insert(e.y);
//         adj[e.x].push_back(e.y);
//         adj[e.y].push_back(e.x);
//     }

//     int fs = *nodes.begin() - *nodes.end(); 
//     int cyclesize = 0;
//     int gs = 0;

//     while(nodes.size() != 0) {
//         components++;
//         cyclesize = 0;
//         dfs(*nodes.begin(), adj, vis, nodes, cyclesize);
//     }
//     fs -= (components - 1);
// }

// int main() {
//     int tt;
//     cin >> tt;
//     while(tt--) solve();
//     return 0;
// }
