#include<bits/stdc++.h>
using namespace std;

int compute_mx(const vector<int>& a)
{
    set<int> s(a.begin(), a.end());
    int mex = 0;
    while(s.count(mex))
      mex++;
    return mex;
}

bool is_possible(const vector<int>& a, int k, int x)
{
    if(x == 0)
       return true;
    int n = a.size();
    vector<bool> present(x, false);
    int count = 0;
    int segment = 0;
    for(int num : a)
      {
        if(num < x && !present[num])
        {
            present[num] = true;
            count++;
        }
        if (count == x)
        {
            segment++;
            if(segment == k)
              return true;
            present.assign(x, false);
            count = 0;
        }
    }
    return segment >= k;
}

int max_min_mx(const vector<int>& a, int k)
{
    int n = a.size();
    int total_mx = compute_mx(a);
    if(k == 1)
      return total_mx;
    int low = 0, high = total_mx;
    int answer = 0;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(is_possible(a, k, mid))
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return answer;
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
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << max_min_mx(a, k) << '\n';
    }
    return 0;
}