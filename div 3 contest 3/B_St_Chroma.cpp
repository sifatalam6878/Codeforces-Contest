#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> p;

    // Step 1: Add 0 to x-1
    for (int i = 0; i < x; i++) {
        p.push_back(i);
    }

    // Step 2: Add n-1 to x+1 (in reverse order, excluding x)
    for (int i = n - 1; i > x; i--) {
        p.push_back(i);
    }

    // Step 3: Add x at last (so MEX = x happens for long)
    if (x != n) {
        p.push_back(x);
    }

    // If x == n, then push only missing number which is n-1 to x
    // Remaining numbers
    for (int i = x; i < n; i++) {
        if (i != x) p.push_back(i);
    }

    // Final print
    for (int val : p) {
        cout << val << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}