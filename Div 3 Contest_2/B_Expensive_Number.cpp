#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
       long long sum=0,  result=0;
        for(char c : s)
        {
            if(c == '0')
            {
                sum++;
            }
            else
            {
               result = max(result,sum + 1);
            }
        }
        cout << s.size() -result << endl;
    }
    return 0;
}