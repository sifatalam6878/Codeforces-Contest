#include <bits/stdc++.h>
using namespace std;

int query(int i, int j, int k) {
    cout << "? " << i << " " << j << " " << k << endl;
    cout.flush();
    int response;
    cin >> response;
    if (response == -1) {
        exit(0); // Invalid query or too many queries
    }
    return response;
}

void answer(int i, int j, int k) {
    cout << "! " << i << " " << j << " " << k << endl;
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Start with the first three points
        vector<int> hull = {1, 2, 3};

        // Iteratively build the convex hull
        for (int i = 4; i <= n; ++i) {
            int m = hull.size();
            int left = 0, right = m - 1;
            bool onHull = false;

            while (left <= right) {
                int mid = (left + right) / 2;
                int p = hull[mid];
                int q = hull[(mid + 1) % m];
                int response = query(p, q, i);

                if (response == 0) {
                    onHull = true;
                    break;
                } else if (response == i) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (!onHull) {
                hull.insert(hull.begin() + left, i);
            }
        }

        // Select any three consecutive points on the hull
        answer(hull[0], hull[1], hull[2]);
    }

    return 0;
}