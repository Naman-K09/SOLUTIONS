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

vector<bool> vis;
vector<ll> ans;
ll MOD = 1e9 + 7;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void dfs(ll& node, vector<vector<pair<ll, ll>>>& adj, ll& size) {
    vis[node] = true;
    size++;

    for(auto& i : adj[node]) {
        if(vis[i.first] || vis[i.second]) continue;

        dfs(i.first, adj, size);
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<vector<pair<ll, ll>>> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vis.clear();
    vis.assign(n+1, false);
    ans.clear();

    for(ll i = 1; i <= n; i++) {
        if(!vis[i]) {
            ll size = 0;
            dfs(i, adj, size);
            ans.push_back(size);
        }
    }

    ll to_output = (power(n, k))%MOD;
    for(ll& i : ans) {
        to_output = (to_output - power(i, k) + MOD) % MOD;
    }

    cout << to_output << endl;
}

int main() {
    fast_io
    solve();
    return 0;
}