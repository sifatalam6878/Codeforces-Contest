#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxScore(int n, vector<int>& a) {
    if (n < 3) return 0; // No triangle can be formed

    // If n == 3, only one triangle can be formed
    if (n == 3) return a[0] * a[1] * a[2];

    // For n >= 4, we need to select non-overlapping triangles
    // We will use dynamic programming to keep track of the maximum score
    vector<long long> dp(n + 1, 0);

    // Base cases
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = a[0] * a[1] * a[2];

    for (int i = 4; i <= n; ++i) {
        // Option 1: Do not select the i-th vertex in any triangle
        dp[i] = dp[i - 1];

        // Option 2: Select the i-th vertex in a triangle with two previous vertices
        for (int j = 1; j < i - 1; ++j) {
            dp[i] = max(dp[i], dp[j - 1] + a[j - 1] * a[i - 2] * a[i - 1]);
        }
    }

    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << maxScore(n, a) << endl;
    }
    return 0;
}