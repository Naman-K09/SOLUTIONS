#include <bits/stdc++.h>
using namespace std ;
#define ll long long
int main() {
    ll tt;
    cin >> tt;

    while(tt--) {
        ll n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < n; i++) {
            int x = a[i] % (k+1);
            a[i] += x*k;
        }

        for(int x : a) cout << x << " ";
        cout << endl ;
    }
    return 0;
}