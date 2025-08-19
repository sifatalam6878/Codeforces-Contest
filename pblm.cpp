#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    set<int> ms;
    while(q--)
    {
        int tp;
        cin >> tp;
        if(tp == 1)
        {
            int p;
            cin >> p;
            ms.insert(p);
        }
        else
        {
            if(ms.empty())
            {
                cout << "empty\n";
            }
            else
            {
                int minval = *ms.begin();
                cout << minval << '\n';
                ms.erase(minval);
            }
        }
    }
    return 0;
}