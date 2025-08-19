#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solve() {
    int n, m;
    cin >> n >> m;
    
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<string>> b(m, vector<string>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }
    
    // Check feasibility: for each j, exists i with b[i][j] == a[j]
    vector<bool> feasible(n, false);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            if (b[i][j] == a[j]) {
                feasible[j] = true;
                break;
            }
        }
        if (!feasible[j]) {
            return -1;
        }
    }
    
    // Compute max k: maximum number of positions that any single b[i] matches with a
    int max_k = 0;
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (b[i][j] == a[j]) {
                cnt++;
            }
        }
        if (cnt > max_k) {
            max_k = cnt;
        }
    }
    
    return 2 * n - max_k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    
    return 0;
}