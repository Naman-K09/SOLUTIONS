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

int check(string s) {
    int count = 0;

    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        if(st.empty()) {
            if(s[i] == '(') st.push(s[i]);
        }
        else {
            if(st.top() == '(' && s[i] == ')') {
                count++;
                st.pop();
            }
            else if(s[i] == '(') {
                st.push(s[i]);
            }
        }
    }

    return count;
}

string solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string s1 = "", s2 = "";
    string s1_(n, '0'), s2_(n, '0');

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(' && count < k) {
            s1_[i] = '1';
            count++;
        }
        else s1 += s[i];
    }

    count = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == ')' && count < k) {
            s2_[i] = '1';
            count++;
        }
        else s2 += s[i];
    }

    if(check(s1) > check(s2)) {
        return s2_;
    }

    return s1_;
}

int main() {
    fast_io

    int t;
    cin >> t;
    while(t--) {

        cout << solve() << '\n';

    }

    return 0;
}


































// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define ll long long
// #define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define error cout << "Hare Krishna" << endl;

// // PBDS Ordered Set: s.find_by_order(k), s.order_of_key(x)
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// struct collection {
//     int idx;
//     int count = 0;

//     bool operator < (const collection& other) const {
//         return count < other.count;
//     }
// };

// string solve() {
//     int n, k;
//     cin >> n >> k;
//     string s;
//     cin >> s;

//     vector<collection> v;

//     for(int i = 0; i < n; i++) {
//         if(s[i] == '(') {
//             collection c;
//             c.idx = i;
//             for(int j = i + 1; j < n; j++) {
//                 if(s[j] == ')') {
//                     c.count++;
//                 }
//             }
//             v.push_back(c);
//         }
//     }

//     for(int i = n - 1; i >= 0; i--) {
//         if(s[i] == ')') {
//             collection c;
//             c.idx = i;
//             for(int j = i - 1; j >= 0; j--) {
//                 if(s[j] == '(') {
//                     c.count++;
//                 }
//             }
//             v.push_back(c);
//         }
//     }

//     sort(v.rbegin(), v.rend());

//     string s_(n, '0');

//     for(int i = 0; i < min(k, (int)v.size()); i++) {
//         s_[v[i].idx] = '1';
//     }

//     return s_;
// }

// int main() {
//     fast_io

//     int tt;
//     cin >> tt;
//     while(tt--) {
        
//         cout << solve() << '\n';

//     }
//     return 0;
// }































// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define ll long long
// #define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define error cout << "Hare Krishna" << endl;

// // PBDS Ordered Set: s.find_by_order(k), s.order_of_key(x)
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// void solve() {
//     int n, k;
//     cin >> n >> k;
//     string s;
//     cin >> s;

//     stack<pair<char, int>> st; // contains ( or ) and their idx.

//     vector<string> v; // this contains the RBS poosiblities sequences.

//     for(int i = 0; i < n; i++) {
//         if(st.empty() && s[i] == '(') { // there is no need to push ) if there is no ( to balance it.
//             st.push({s[i], i});
//             continue;
//         }

//         if(!st.empty()) {
//             char ch = st.top().first; // take the top most char of stack.

//             if(ch == ')' && s[i] == '(') {

//                 // i.e either a possiblity of RBS is found, from here new will start.
//                 continue; // this means new sequence has started.
//             }

//             st.push({s[i], i}); // push to stack :)

//             // this can form
//             // ())) like this
//             // (()) like this
//             // ((() like this.. and variation of these.
//         }
//     }
// }

// int main() {
//     fast_io

//     int tt;
//     cin >> tt;
//     while(tt--) {

//         solve();

//     }
//     return 0;
// }