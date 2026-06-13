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

vector<vector<vector<int>>> permutations;

void calculate() { // precalculate the permutations.
    vector<int> v = {1, 2};
    vector<vector<int>> q;
    
    do {
        q.push_back(v);
        
    } while (next_permutation(v.begin(), v.end()));

    permutations.push_back(q);
    q.clear();

    v = {1, 2, 3};
    do {
        q.push_back(v);
        
    } while (next_permutation(v.begin(), v.end()));

    permutations.push_back(q);
    q.clear();

    v = {1, 2, 3, 4};
    do {
        q.push_back(v);
        
    } while (next_permutation(v.begin(), v.end()));

    permutations.push_back(q);
}

void solve() {
    int n, i, j;
    cin >> n >> i >> j;
    i--, j--;

    int idx;
    if(n == 12) idx = 0; 
    else if(n == 123) idx = 1;
    else idx = 2;

    int sz = idx + 2;

    int count_a = 0;

    for(int k = 0; k < sz; k++) {
        if(permutations[idx][i][k] == permutations[idx][j][k]) {
            count_a++;
        }
    }



    cout << count_a << "A" << sz - count_a << "B" << endl;
}

int main() {
    fast_io

    permutations.clear();
    calculate();

    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }

    return 0;
}