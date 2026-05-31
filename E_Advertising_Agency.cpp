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

const ll MOD = 1e9 + 7;
vector<ll> fact(1001);
vector<ll> inv_fact(1001);

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void fill_facts() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i < 1001; i++) {
        fact[i] = (fact[i-1]*i) % MOD;
    }
    inv_fact[1000] = power(fact[1000], MOD-2);
    for(int i = 999; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}

ll nCr (ll n, ll r) {
    ll num = fact[n];
    ll den = (inv_fact[r] * inv_fact[n-r]) % MOD;

    return (num * den) % MOD;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    set<ll> vals;
    for(int i = n - 1; i >= n-k; i--) {
        if(vals.size() == k) break;
        vals.insert(a[i]);
    }

    unordered_map<ll, ll> total_freq;
    for(int i = n-1; i >= 0; i--) {
        if(!vals.count(a[i])) break;

        total_freq[a[i]] = (total_freq[a[i]] + 1) % MOD;
    }

    // Remember the last value will have k - total freq of the top_all for choosing the combination, RadheShyam :)

    ll top_frequencies = 0;
    for(auto it = next(vals.begin()); it != vals.end(); it++) {
        top_frequencies = (top_frequencies + total_freq[*it]) % MOD;
    }

    ll ans = nCr(total_freq[*vals.begin()], k - top_frequencies);

    cout << ans << '\n';
}

int main() {
    fast_io

    fill_facts();

    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}