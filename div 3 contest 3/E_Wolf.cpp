#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> p(n + 1);
    vector<int> pos(n + 1); // pos[i] = index where p[index] = i
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        
        // Step 1: যদি k range-এ না থাকে, তাহলে অসম্ভব
        if (pos[k] < l || pos[k] > r) {
            cout << -1 << endl;
            continue;
        }
        
        // Step 2: Binary search path গণনা
        vector<int> path;
        int curr_l = l, curr_r = r;
        bool found = false;
        while (curr_l <= curr_r) {
            int m = (curr_l + curr_r) / 2;
            path.push_back(m);
            if (p[m] == k) {
                cout << 0 << endl;
                found = true;
                break;
            } else if (p[m] < k) {
                curr_l = m + 1;
            } else {
                curr_r = m - 1;
            }
        }
        
        if (found) {
            continue; // পরের query-তে যাই
        }
        
        // Step 3: BFS দিয়ে shortest path খুঁজি
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[pos[k]] = 0;
        q.push(pos[k]);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            // path-এর প্রতিটি index চেক করি
            for (int m : path) {
                if (p[m] != k && dist[m] == -1) {
                    dist[m] = dist[u] + 1;
                    q.push(m);
                }
            }
        }
        
        // path-এর কোনো index-এ পৌঁছানো গেল কিনা চেক করি
        int min_d = -1;
        for (int m : path) {
            if (p[m] != k && dist[m] != -1) {
                if (min_d == -1 || dist[m] < min_d) {
                    min_d = dist[m];
                }
            }
        }
        
        cout << min_d << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}