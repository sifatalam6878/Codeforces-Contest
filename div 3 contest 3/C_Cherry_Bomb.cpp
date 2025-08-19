#include<bits/stdc++.h>
using namespace std;
void ans()
{
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n),b(n);
    for(int i=0; i<n; i++)
       cin >> a[i];
    for(int i = 0; i < n; ++i)
       cin >> b[i];
    set<long long> s;
    for(int i=0; i<n; i++)
    {
        if(b[i] != -1)
        {
            s.insert(a[i] + b[i]);
        }
    }
    if(s.size() > 1)
    {
        cout << 0 << '\n';
        return;
    }
    if(!s.empty())
    {
        long long x = *s.begin();
        for(int i=0; i<n; i++)
        {
            if(b[i] == -1)
            {
                long long val = x-a[i];
                if (val<0 || val>m)
                {
                    cout << 0 << '\n';
                    return;
                }
            }
        }
        cout << 1 << '\n';
        return;
    }
    long long l = *max_element(a.begin(), a.end());
    long long r = *min_element(a.begin(), a.end())+m;
    if(l>r)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << r-l+1 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        ans();
    }
    return 0;
}
