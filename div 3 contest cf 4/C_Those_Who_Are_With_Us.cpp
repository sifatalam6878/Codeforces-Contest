#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        int min_max = INT_MAX;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                int current_max = INT_MIN;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        int val = a[i][j];
                        if (i == r || j == c) {
                            val--;
                        }
                        if (i == r && j == c) {
                            val++;
                        }
                        if (val > current_max) {
                            current_max = val;
                        }
                    }
                }
                if (current_max < min_max) {
                    min_max = current_max;
                }
            }
        }
        cout << min_max << '\n';
    }
    return 0;
}