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

struct PrimeStat {
    ll sz = 0;
    ll lowest = 1e18;
    ll second_lowest = 1e18;

    void add(ll count) {
        sz++;
        if(count < lowest) {
            second_lowest = lowest;
            lowest = count;
        }
        else if(count < second_lowest) {
            second_lowest = count;
        }
    }
};

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

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    unordered_map<ll , PrimeStat> mp; // sz, lowest, second, lowest.

    for(auto& i_ : a) {
        for(ll j = 2; j*j <= i_; j++) {
            ll count = 0;
            while(i_ > 1 && i_ % j == 0) {
                i_ /= j;
                count++;
            }
            mp[j].add(count);
        }
        if(i_ > 1) mp[i_].add(1);
    }

    ll ans = 1;
    for(auto& i : mp) {
        ll val = i.first;
        PrimeStat stat = i.second;

        if(stat.sz < n-1) continue;
        ll exp = 0;
        if (stat.sz == n - 1) {
            // Missing from exactly 1 number. The 2nd smallest is the absolute minimum we tracked
            exp = stat.lowest;
        } else if (stat.sz == n) {
            // Present in ALL numbers. The 2nd smallest is our tracked second_lowest
            exp = stat.second_lowest;
        }
        if(exp == 0) continue;

        ans = ans * power(val, exp);
    }

    cout << ans << '\n';
}

int main() {
    fast_io

    solve();

    return 0;
}