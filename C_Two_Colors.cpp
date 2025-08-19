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
        vector<int>a(m);
        for(int i = 0; i < m; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        long long result = 0;
        int left = 0, right = m - 1;

        while(left < right)
        {
            if(a[left] + a[right] >= n)
            {
                int min_planks = max(1, n - a[right]);
                int max_planks = min(a[left], n - 1);
                if (min_planks <= max_planks)
                {
                    result += (max_planks - min_planks + 1) * 2;
                }
                right--;
            }
            else
            {
                left++;
            }
        }
        cout << result << '\n';
    }

    return 0;
}
