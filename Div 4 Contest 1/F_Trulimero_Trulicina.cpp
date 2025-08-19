#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        // Initialize the grid
        vector<vector<int>> grid(n, vector<int>(m));

        // Fill the grid with numbers from 1 to k in a balanced way
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Alternate rows for neighbor constraints
                grid[i][j] = (i * m + j) % k + 1;
            }

            // If the row number is odd, reverse the row to maintain the adjacency constraints
            if (i % 2 != 0) {
                reverse(grid[i].begin(), grid[i].end());
            }
        }

        // Output the grid for this test case
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
