#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;

        // Length on day `m` is `m` => l' + m - 1 = r'
        int l_prime = l;     // Start from the leftmost house
        int r_prime = l_prime + m - 1; // Calculate the rightmost house

        // Output the solution for this test case
        cout << l_prime << " " << r_prime << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); // Optimize input/output
    cin.tie(nullptr);

    solve();
    return 0;
}
