#include<bits/stdc++.h>
using namespace std;
bool real(const vector<int>& a,const vector<int>& b, int pos, int val)
{
    vector<int> s = a;
    s.insert(s.begin() + pos,val);
    int k = 0;
    for(int i=0; i<s.size() && k<b.size();i++)
    {
        if(s[i] >= b[k])
        {
            k++;
        }
    }
    return k==b.size();
}
int ans()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++)
       cin >> a[i];
    for(int i=0;i<m;i++)
       cin >> b[i];
    {
        int k=0;
        for (int i=0; i<n && k<m;i++)
        {
            if(a[i] >= b[k])
            {
                k++;
            }
        }
        if(k == m)
        {
            return 0;
        }
    }
    int l = 1;
    int r = 1e9;
    int solve = -1;
    while(l <= r)
    {
        int md = (l + r)/2;
        bool ptv = false;
        for(int pos=0;pos<=n;pos++)
        {
            if(real(a,b,pos,md))
            {
                ptv = true;
                break;
            }
        }
        if(ptv)
        {
            solve = md;
            r=md - 1;
        }
        else
        {
            l=md+1;
        }
    }
    
    return solve;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        cout << ans() << '\n';
    }
    return 0;
}