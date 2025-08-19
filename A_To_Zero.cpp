#include<bits/stdc++.h>
using namespace std;
int minoperation(int n,int k)
{
    if(n%2 == 0)
    {
        return n/(k - 1)+(n % (k - 1) != 0);
    }
    else
    {
        if(n < k)
        {
            return 1;
        }
        return 1 + (n - k)/(k - 1)+((n - k)%(k - 1) != 0);
    }
}

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
        cout << minoperation(n, k) << "\n";
    }

    return 0;
}
