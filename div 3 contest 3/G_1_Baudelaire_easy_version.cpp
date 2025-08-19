#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Since every node is adjacent to node 1, the root must be either node 1 or another node.
    // We can assume the root is node 1 for simplicity, but need to verify.

    // First, query the sum of f(u) for all nodes u.
    cout << "? 1 " << n;
    for (int i = 1; i <= n; ++i) {
        cout << " " << i;
    }
    cout << endl;
    cout.flush();

    int total_sum;
    cin >> total_sum;

    // Now, toggle node 1 and query again to see the difference.
    cout << "? 2 1" << endl;
    cout.flush();
    // No need to read response for toggle.

    cout << "? 1 " << n;
    for (int i = 1; i <= n; ++i) {
        cout << " " << i;
    }
    cout << endl;
    cout.flush();

    int new_total_sum;
    cin >> new_total_sum;

    // The difference between total_sum and new_total_sum can help determine the value of node 1.
    int diff = total_sum - new_total_sum;
    int val1;
    if (diff > 0) {
        val1 = 1;
    } else {
        val1 = -1;
    }

    // Now, query individual nodes to find their values.
    vector<int> values(n + 1);
    values[1] = val1;

    for (int u = 2; u <= n; ++u) {
        cout << "? 1 1 " << u << endl;
        cout.flush();
        int sum;
        cin >> sum;
        values[u] = sum - (values[1] * (u != 1 ? 1 : 0)); // Simplified assumption; may need adjustment.
    }

    // Output the final values.
    cout << "!";
    for (int i = 1; i <= n; ++i) {
        cout << " " << values[i];
    }
    cout << endl;
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}