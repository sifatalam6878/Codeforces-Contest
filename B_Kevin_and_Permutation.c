#include <stdio.h>

void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int permutation[n];
    
    // Initialize the permutation
    int num = 1;
    
    // Fill the permutation in blocks to minimize the sum of minimums
    for (int i = 0; i < n; i++) {
        // Fill elements in the blocks (group of k elements)
        if (i % k == 0) {
            permutation[i] = num++;
        }
    }

    // Fill the remaining elements
    for (int i = 0; i < n; i++) {
        if (permutation[i] == 0) {
            permutation[i] = num++;
        }
    }

    // Output the permutation for the current test case
    for (int i = 0; i < n; i++) {
        printf("%d ", permutation[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}
