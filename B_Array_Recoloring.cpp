#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        long long sum = 0;
        for(int i=0;i<k;++i)
        {
            sum += a[i];
        }
        sum += a[k];

        cout << sum << '\n';
    }

    return 0;
}