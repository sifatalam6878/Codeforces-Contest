#include <bits/stdc++.h>
using namespace std;

// Function to count the number of necessary Quadtree nodes
int countNodes(int l1, int r1, int l2, int r2) {
    int nodes = 0;

    while (l1 < r1 && l2 < r2) {
        // Compute the largest power of 2 that can fit within the given range
        int size = 1 << (31 - __builtin_clz(max(r1 - l1, r2 - l2)));

        // Traverse the region by filling it with maximum possible squares
        for (int x = l1; x < r1; ) {
            for (int y = l2; y < r2; ) {
                int side = min(size, min(r1 - x, r2 - y));
                nodes++;
                y += side;
            }
            x += size;
        }
        break;
    }

    return nodes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << countNodes(l1, r1, l2, r2) << "\n";
    }

    return 0;
}
