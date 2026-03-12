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

ll dfs(ll node, vector<bool>& vis, vector<vector<ll>>& adj, vector<ll>& a) {
    vis[node] = true;

    ll sum = a[node];
    for(ll& i : adj[node]) {
        if(vis[i]) continue;

        sum += dfs(i, vis, adj, a);
    }
    return sum;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    // adj created
    vector<vector<ll>> adj(n);
    for(ll i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        x--, y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<pair<ll, ll>> nodecost;
   for(ll i = 0; i < n; i++) {
    ll degree = (ll)adj[i].size();
    if (degree > 1) { 
        nodecost.push_back({a[i], degree - 1});
    }
}

    vector<bool> vis(n, false);
    ll sum = dfs(0, vis, adj, a);
    vector<ll> ans(n-1, sum);
    sort(nodecost.begin(), nodecost.end());

    for(ll i = 1; i < n - 1; i++) {
    while(!nodecost.empty() && nodecost.back().second == 0) {
        nodecost.pop_back();
    }

    if(!nodecost.empty()) {
        sum += nodecost.back().first;
        nodecost.back().second--;
    }
    ans[i] = sum;
}

    for(ll& i : ans) cout << i << " ";
    cout << endl;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}


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

int dfs(int node, vector<bool>& vis, vector<vector<int>>& adj) {
    vis[node] = true;

    int sum = 0;
    for(auto& i : adj[node]) {
        if(vis[i]) continue;

        sum += dfs(i, vis, adj);
    }

    return sum;
}