#include<bits/stdc++.h>
using namespace std;
void ans()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<int> p(2*n);
    set<int>s;
    for(int k=2; k<=2*n; k++)
    {
        int i=max(1,k-n);
        int j = k-i;
        if(i<=n && j<=n)
        {
            p[k-1] = grid[i-1][j-1];
        }
    }
    set<int> pr;
    for(int i=1; i<2*n; i++)
    {
        pr.insert(p[i]);
    }
    for(int l=1; l<=2*n; l++)
    {
        if(pr.find(l) == pr.end())
        {
            p[0] = l;
            break;
        }
    }

    for(int l : p)
    {
        cout << l << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        ans();
    }
    return 0;
}