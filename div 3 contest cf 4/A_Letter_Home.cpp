#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        int min_x = *min_element(x.begin(), x.end());
        int max_x = *max_element(x.begin(), x.end());
        if (s >= min_x && s <= max_x) {
            cout << (max_x - min_x) << endl;
        } else if (s < min_x) {
            cout << (max_x - s) << endl;
        } else {
            cout << (s - min_x) << endl;
        }
    }
    return 0;
}