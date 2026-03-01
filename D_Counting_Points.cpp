#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> xr(n);
    for(int i = 0; i < n; i++) cin >> xr[i].first; // center
    for(int i = 0; i < n; i++) cin >> xr[i].second; // raduis

    sort(xr.begin(), xr.end());
    // Grouping Circles
    if (n == 0) { cout << 0 << endl; return; }

    sort(xr.begin(), xr.end());

    ll edge = xr[0].first + xr[0].second;
    int gno = 0;
    vector<vector<pair<ll, ll>>> group(1);
    vector<ll> min_x(1, xr[0].first - xr[0].second);
    vector<ll> max_x(1, xr[0].first + xr[0].second);
    
    group[0].push_back({xr[0].first, xr[0].second});

    for(int i = 1; i < n; i++) {
        ll L = xr[i].first - xr[i].second;
        ll R = xr[i].first + xr[i].second;

        if(L > edge) {
            gno++;
            group.push_back({});
            min_x.push_back(L);
            max_x.push_back(R);
        } else {
            // We are in the same group, update its global boundaries
            min_x[gno] = min(min_x[gno], L);
            max_x[gno] = max(max_x[gno], R);
        }
        // Always update the furthest reach of the current group
        edge = max(edge, R);
        group[gno].push_back({xr[i].first, xr[i].second});
    }

    // Now lets simulate;
    ll count = 0;
    for(int g = 0; g < group.size(); g++) {
        ll size =  max_x[g] - min_x[g] + 1; 
        vector<ll> ymax(size,0);

        // one circle at a time.
        for(auto c : group[g]) {
            // each circle xi-ri to xi+ri
            ll leftrange = c.first - c.second; 
            ll rightrange = c.second + c.first;
            ll center = c.first;
            ll raduis = c.second;
            
            // Calculating ymax from circle c and from upcomig circles.
            for(ll i = leftrange; i <= rightrange; i++) {
                ll r2 = 1LL * raduis * raduis;
                ll dx2 = 1LL * (center - i) * (center - i);
                
                // 2. Calculate height as an integer (adding 0.5 for precision)
                ll current_h = (ll)(sqrt(r2 - dx2 + 0.5));
                
                // 3. Update the max for this specific x-coordinate
                int idx = i - min_x[g];
                if (current_h > ymax[idx]) {
                    ymax[idx] = current_h;
                }
                
            }
        }

        // Adding components in count for particular group.
        for(ll c : ymax) {
            count += 1LL*(2*c + 1);
        }
    }

    // Output
    cout << 1LL*count << endl;
}
int main() {
    fast_io;
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

// void solve() {
//     int n, m_unused;
//     if (!(cin >> n >> m_unused)) return;

//     // Use a struct for clarity
//     struct Circle {
//         ll x, r, l, r_edge;
//     };
//     vector<Circle> xr(n);
//     vector<ll> centers(n), radii(n);

//     for(int i = 0; i < n; i++) cin >> centers[i];
//     for(int i = 0; i < n; i++) cin >> radii[i];
    
//     for(int i = 0; i < n; i++) {
//         xr[i] = {centers[i], radii[i], centers[i] - radii[i], centers[i] + radii[i]};
//     }

//     // 1. Sort by LEFT EDGE (Crucial for grouping intervals)
//     sort(xr.begin(), xr.end(), [](const Circle& a, const Circle& b) {
//         if (a.l != b.l) return a.l < b.l;
//         return a.r_edge < b.r_edge;
//     });

//     // 2. Grouping Circles
//     vector<vector<Circle>> groups;
//     if (n > 0) {
//         ll current_group_far_edge = -2e18; // Far right reach of current group

//         for(int i = 0; i < n; i++) {
//             if (xr[i].l > current_group_far_edge) {
//                 // Gap found, start new group
//                 groups.push_back({});
//                 current_group_far_edge = xr[i].r_edge;
//             } else {
//                 // Overlap or touch, extend current group reach
//                 current_group_far_edge = max(current_group_far_edge, xr[i].r_edge);
//             }
//             groups.back().push_back(xr[i]);
//         }
//     }

//     // 3. Simulation per group
//     ll total_count = 0;
//     for(auto& g : groups) {
//         ll g_min_x = 2e18;
//         ll g_max_x = -2e18;
//         for(auto& c : g) {
//             g_min_x = min(g_min_x, c.l);
//             g_max_x = max(g_max_x, c.r_edge);
//         }

//         ll size = g_max_x - g_min_x + 1;
//         vector<int> ymax(size, 0);

//         for(auto& c : g) {
//             ll r2 = c.r * c.r;
//             for(ll i = c.l; i <= c.r_edge; i++) {
//                 ll dx = abs(c.x - i);
//                 // Calculate max height at this vertical scanline
//                 int h = (int)(sqrt(r2 - dx * dx + 0.5));
//                 int idx = (int)(i - g_min_x);
//                 if (h > ymax[idx]) ymax[idx] = h;
//             }
//         }

//         for(int h : ymax) {
//             total_count += (2LL * h + 1);
//         }
//     }

//     cout << total_count << "\n";
// }

// int main() {
//     fast_io;
//     int tt;
//     if (!(cin >> tt)) return 0;
//     while(tt--) solve();
//     return 0;
// }