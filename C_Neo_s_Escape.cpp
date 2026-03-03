#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define error cout << "Hare Krishna" << endl;

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;

        vector<ll> a;
        a.push_back(-1);
        for(int i = 0; i < n; i++)  {
            ll x;
            cin >> x;

            if(x != a.back()) a.push_back(x); 
        }
        a.push_back(-1);
        

        ll count = 0;
        for(int i = 1; i < a.size() - 1; i++) {
            if(a[i] > a[i-1] && a[i] > a[i+1]) count++;
        }

        cout << count << endl;
    }
    return 0;
}






























// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define error cout << "Hare Krishna" << endl;

// void solve() {
//     int n;
//     cin >> n;
//     priority_queue<pair<ll, int>> pq;
//     for(int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         pq.push({x, i});
//     }

//     vector<int> robot_at(n, 0);
//     ll robocount = 0;

//     while(!pq.empty()) {
//         int val = pq.top().first;
//         int idx = pq.top().second;
//         pq.pop();

//         bool left_found = false;
//         bool right_found = false;
//         for(int i = idx-1; i >= 0; i--) {
//             if(robot_at[i] == 2) {
//                 robot_at[i] = 1;
//                 left_found = true;
//                 break;
//             }
//             else if(!robot_at[i]) break;
//         }
//         if(!left_found) {
//             for(int i = idx+1; i < n; i++) {
//                 if(robot_at[i] == 2) {
//                     robot_at[i] = 1;
//                     right_found = true;
//                     break;
//                 }
//                 else if(!robot_at[i]) break;
//             }
//         }

//         if(!left_found && !right_found) robocount++;
//         robot_at[idx] = 2;
//     }

//     cout << robocount << endl;
//     return;
// }

// int main() {
//     fast_io
//     int tt;
//     cin >> tt;

//     while(tt--) solve();
//     return 0;
// }