#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<long long> x(n), r(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> x[i];
        }
        for(int i = 0; i < n; ++i)
        {
            cin >> r[i];
        }
        long long max_r = *max_element(r.begin(), r.end());

        long long total_points = 0;

        for(int y = -max_r; y <= max_r; ++y)
        {
            vector<pair<int, int>> ranges;
            for(int i = 0; i < n; ++i)
            {
                if (y * y > r[i] * r[i]) continue;
                long long x_range = sqrt(r[i] * r[i] - y * y);
                int x_min = x[i] - x_range;
                int x_max = x[i] + x_range;
                ranges.push_back({x_min, x_max});
            }

            sort(ranges.begin(), ranges.end());
            vector<pair<int, int>> merged;
            for(auto &range : ranges)
            {
                if(merged.empty() || merged.back().second < range.first)
                {
                    merged.push_back(range);
                }
                else
                {
                    merged.back().second = max(merged.back().second, range.second);
                }
            }
            for(auto &range : merged)
            {
                total_points += range.second - range.first + 1;
            }
        }

        cout << total_points << '\n';
    }

    return 0;
}