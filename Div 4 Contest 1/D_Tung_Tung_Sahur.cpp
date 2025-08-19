#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string p, s;
        cin >> p >> s;
        int i = 0, j = 0;
        bool pos = true;
        while(i<p.size() && j<s.size())
        {
            if(p[i] == 'L')
            {
                if(s[j] == 'L')
                {
                    j++;
                    if(j < s.size() && s[j] == 'L')
                    {
                        j++;
                    }
                }
                else
                {
                    pos = false;
                    break;
                }
            }
            else if(p[i] == 'R')
            {
                if(s[j] == 'R')
                {
                    j++;
                    if(j < s.size() && s[j] == 'R')
                    {
                        j++;
                    }
                }
                else
                {
                    pos = false;
                    break;
                }
            }
            i++;
        }
        if(pos && j < s.size())
        {
            pos = false;
        }

        cout << (pos ? "YES" : "NO") << endl;
    }
    return 0;
}