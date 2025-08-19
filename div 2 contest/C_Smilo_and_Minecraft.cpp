#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        vector<vector<int>> gold(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'g') {
                    gold[i][j] = 1;
                }
            }
        }

        int max_gold = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '.') {
                    int collected = 0;
                    for (int di = -k; di <= k; ++di) {
                        for (int dj = -k; dj <= k; ++dj) {
                            if (abs(di) == k || abs(dj) == k) {
                                int ni = i + di;
                                int nj = j + dj;
                                if (ni >= 0 && ni < n && nj >= 0 && nj < m && gold[ni][nj] == 1) {
                                    collected++;
                                    gold[ni][nj] = 0; // Mark as collected to avoid double-counting
                                }
                            }
                        }
                    }
                    max_gold = max(max_gold, collected);
                }
            }
        }

        cout << max_gold << '\n';
    }

    return 0;
}