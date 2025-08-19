#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // Choose y as x XOR (x - 1)
        int y = x ^ (x - 1);

        // Check if y < x and the triangle inequalities are satisfied
        if (y < x && x + y > (x ^ y) && x + (x ^ y) > y && y + (x ^ y) > x) {
            cout << y << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}