#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> r(n);
        for (int i = 0; i < n; i++) {
            int maxa = max_element(a.begin(), a.begin() + i + 1) - a.begin();
            int maxb = max_element(b.begin(), b.begin() + i + 1) - b.begin();

            if (a[maxa] < b[maxb]) {
                r[i] = (1 << b[maxb]) + (1 << a[i - maxb]);
            } else if (a[maxa] > b[maxb]) {
                r[i] = (1 << b[i - maxa]) + (1 << a[maxa]);
            } else {
                if(a[i - maxb] > b[i - maxa]) {
                    r[i] = (1 << b[maxb]) + (1 << a[i - maxb]);
                } else {
                    r[i] = (1 << b[i - maxa]) + (1 << a[maxa]);
                }
            }
        }

        for (auto x : r) cout << x << " ";
        cout << endl;
    }
    return 0;
}
