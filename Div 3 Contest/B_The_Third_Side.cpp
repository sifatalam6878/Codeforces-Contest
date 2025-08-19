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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        priority_queue<int> pq(a.begin(), a.end());
        while(pq.size() > 1)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            pq.push(x + y - 1);
        }

        cout << pq.top() << '\n';
    }

    return 0;
}