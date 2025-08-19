#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int real = 0;
        for(char c : s)
        {
            if(c == '1')
              real++;
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
            {
                cnt += real - 1;
            }
            else
            {
                cnt += real + 1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}