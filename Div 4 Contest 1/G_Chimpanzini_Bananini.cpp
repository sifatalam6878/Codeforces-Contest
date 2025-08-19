#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int q;
    cin >> q;
    deque<ll> arr;
    ll riz = 0;
    ll sum = 0;
    ll n = 0;
    bool rev = false;
    while (q--)
    {
        int s;
        cin >> s;
        if (s == 1)
        {
            if(n <= 1)
            {
                cout << riz << "\n";
                continue;
            }
            if(rev)
            {
                ll front = arr.front();
                arr.pop_front();
                arr.push_back(front);
                riz = riz + sum - front * n;
            }
            else
            {
                ll back = arr.back();
                arr.pop_back();
                arr.push_front(back);
                riz = riz + sum - back * n;
            }
        }
        else if(s == 2)
        {
            if(n <= 1)
            {
                cout << riz << "\n";
                continue;
            }
            rev = !rev;
            riz = (n + 1) * sum - riz;
        }
        else if(s == 3)
        {
            ll k;
            cin >> k;
            n++;
            if(rev)
            {
                arr.push_front(k);
            }
            else
            {
                arr.push_back(k);
            }
            sum += k;
            riz = riz + k * n;
        }
        cout << riz << "\n";
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
        solve();
    }
    
    return 0;
}