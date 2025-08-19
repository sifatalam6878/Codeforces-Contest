#include<bits/stdc++.h>
using namespace std;

long long sqdis(int x1, int y1, int x2, int y2)
{
    return(long long)(x1 - x2) * (x1 - x2) + (long long)(y1 - y2) * (y1 - y2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int I, r, d, u;
        cin >> I >> r >> d >> u;

        int x1 = -I, y1 = 0;
        int x2 = r, y2 = 0;
        int x3 = 0, y3 = -d;
        int x4 = 0, y4 = u;

        vector<long long> distances =
        {
            sqdis(x1, y1, x2, y2),
            sqdis(x1, y1, x3, y3),
            sqdis(x1, y1, x4, y4),
            sqdis(x2, y2, x3, y3),
            sqdis(x2, y2, x4, y4),
            sqdis(x3, y3, x4, y4)
        };

        sort(distances.begin(), distances.end());
        if(distances[0] > 0 &&
            distances[0] == distances[1] &&
            distances[1] == distances[2] &&
            distances[2] == distances[3] &&
            distances[4] == distances[5] &&
            distances[4] == 2 * distances[0])
            {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}