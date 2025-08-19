#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    
    // Read participant ratings
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Read problem difficulties
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    
    // Sort the ratings of participants and the difficulties of problems
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Store the result for each k = 1 to m
    vector<int> result(m);
    
    // For each value of k (number of problems per contest)
    for (int k = 1; k <= m; ++k) {
        int totalRank = 0;
        
        // Simulate contests by dividing the problems into k-sized chunks
        for (int i = 0; i < m; i += k) {
            int end = min(i + k, m);
            
            // Count how many problems in the current contest each participant can solve
            vector<int> problemsSolved(n, 0);
            for (int j = i; j < end; ++j) {
                for (int p = 0; p < n; ++p) {
                    if (a[p] >= b[j]) {
                        problemsSolved[p]++;
                    }
                }
            }
            
            // Calculate Kevin's rank
            int kevinSolved = problemsSolved[0];
            int rank = 1;
            for (int p = 1; p < n; ++p) {
                if (problemsSolved[p] > kevinSolved) {
                    rank++;
                }
            }
            
            totalRank += rank;
        }
        
        // Store the result for this value of k
        result[k - 1] = totalRank;
    }
    
    // Output the result for the current test case
    for (int i = 0; i < m; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    // Process each test case
    while (t--) {
        solve();
    }
    
    return 0;
}
