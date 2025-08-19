#include<bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    if(n <= 1)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(int i = 3; i <= sqrt(n); i += 2)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x, k;
        cin >> x >> k;
        if(k == 1)
        {
            cout << (is_prime(x) ? "YES" : "NO") << endl;
        }
        else
        {
            if(x == 1 && k == 2)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}