#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> p;
    for(int i=0;i<x;i++)
    {
        p.push_back(i);
    }
    for (int i = n - 1; i > x; i--)
    {
        p.push_back(i);
    }
    if(x != n) {
        p.push_back(x);
    }
    for (int i = x; i < n; i++)
    {
        if (i != x) p.push_back(i);
    }
    for (int val : p)
    {
        cout << val << " ";
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}