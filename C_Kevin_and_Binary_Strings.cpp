#include <iostream>
#include <bitset>
#include <climits>
using namespace std;

int xorOfSubstrings(const string& s, int l1, int r1, int l2, int r2) {
    // Convert the substrings to integers using bitset
    int num1 = bitset<32>(s.substr(l1-1, r1-l1+1)).to_ulong();
    int num2 = bitset<32>(s.substr(l2-1, r2-l2+1)).to_ulong();
    return num1 ^ num2;
}

void solve() {
    string s;
    cin >> s;
    
    int maxXOR = -1;
    int best_l1 = 1, best_r1 = 1, best_l2 = 1, best_r2 = 1;
    
    int n = s.length();
    
    // Brute-force approach to try all pairs of substrings
    for (int l1 = 1; l1 <= n; ++l1) {
        for (int r1 = l1; r1 <= n; ++r1) {
            for (int l2 = 1; l2 <= n; ++l2) {
                for (int r2 = l2; r2 <= n; ++r2) {
                    int currentXOR = xorOfSubstrings(s, l1, r1, l2, r2);
                    if (currentXOR > maxXOR) {
                        maxXOR = currentXOR;
                        best_l1 = l1;
                        best_r1 = r1;
                        best_l2 = l2;
                        best_r2 = r2;
                    }
                }
            }
        }
    }
    
    cout << best_l1 << " " << best_r1 << " " << best_l2 << " " << best_r2 << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
