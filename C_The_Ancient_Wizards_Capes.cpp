#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define error cout << "Hare Krishna" << endl;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool check = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0 && (abs(a[i] - a[i-1]) > 1)) check = true;
    }

    if(check) {
        cout << 0 << endl;
        return;
    }

    string s1 = "L";
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i-1] == 0) {
            if(s1.back() == 'L') s1 += 'R';
            else s1 += 'L';
        }
        else if(a[i] - a[i-1] == 1) {
            if(s1.back() == 'R') ;
            else s1 += 'L';
        }
        else {
            if(s1.back() == 'L') ;
            else s1 += 'R';
        }
    }
    
    int count = 2;
    if(s1.length() == n) {
        int sum = 0;
        vector<int> prefix(n, 0);
        for(int i = 0; i < n; i++) {
            prefix[i] = sum;
            if(s1[i] == 'L') sum++; 
        }
        sum = 0;
        vector<int> suffix(n, 0);
        for(int i = n-1; i >= 0; i--) {
            suffix[i] = sum;
            if(s1[i] == 'R') sum++;
        }
        vector<int> checker(n);
        for(int i = 0; i < n; i++) {
            checker[i] = prefix[i] + suffix[i] + 1;
        }

        for(int i = 0; i < n; i++) {
            if(checker[i] != a[i]) {
                count--; 
                break;
            }
        }
    }
    else count--; 
    
    string s2 = "R";
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i-1] == 0) {
            if(s2.back() == 'L') s2 += 'R';
            else s2 += 'L';
        }
        else if(a[i] - a[i-1] == 1) {
            if(s2.back() == 'R') ;
            else s2 += 'L';
        }
        else {
            if(s2.back() == 'L') ;
            else s2 += 'R';
        }
    }

    if(s2.length() == n) {
        int sum = 0;
        vector<int> prefix(n, 0);
        for(int i = 0; i < n; i++) {
            prefix[i] = sum;
            if(s2[i] == 'L') sum++; 
        }
        sum = 0;
        vector<int> suffix(n, 0);
        for(int i = n-1; i >= 0; i--) {
            suffix[i] = sum;
            if(s2[i] == 'R') sum++;
        }
        vector<int> checker(n);
        for(int i = 0; i < n; i++) {
            checker[i] = prefix[i] + suffix[i] + 1;
        }

        for(int i = 0; i < n; i++) {
            if(checker[i] != a[i]) {
                count--; 
                break;
            }
        }
    }
    else count--; 


    cout << count << endl;
}

int main() {
    fast_io
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}