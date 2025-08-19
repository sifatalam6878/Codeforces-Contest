#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    // If there is only one right-side vertex (m = 1), we can assign all edges the same color
    if (m == 1) {
        cout << "YES" << endl;
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << 1 << " ";  // Color all edges with color 1
            }
            cout << endl;
        }
    }
    // If there are exactly two right-side vertices (m = 2), we alternate between colors
    else if (m == 2) {
        cout << "YES" << endl;
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Alternate colors between 1 and 2
                cout << (j % 2 == 0 ? 1 : 2) << " ";
            }
            cout << endl;
        }
    }
    // If there are more than two right-side vertices (m > 2), we use a repeating pattern of colors
    else {
        cout << "YES" << endl;
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Use a repeating pattern of colors from 1 to n
                cout << (j % n + 1) << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
