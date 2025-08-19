#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll get_value(int n, int x, int y, ll base = 1)
{
    if(n == 1)
    {
        if(x == 1 && y == 1)
         return base;
        if(x == 2 && y == 2)
          return base + 1;
        if(x == 2 && y == 1)
          return base + 2;
        if(x == 1 && y == 2)
          return base + 3;
    }
    int len = 1 << (n - 1);
    ll block_size = 1LL << (2 * n - 2);

    if(x <= len && y <= len)
        return get_value(n - 1, x, y, base);
    if(x > len && y > len)
        return get_value(n - 1, x - len, y - len, base + block_size);
    if(x > len && y <= len)
        return get_value(n - 1, x - len, y, base + 2 * block_size);
    return get_value(n - 1, x, y - len, base + 3 * block_size);
}

pair<int,int> get_position(int n, ll d, ll base = 1, int x = 1, int y = 1)
{
    if(n == 1)
    {
        if(d == base)
          return {x, y};
        if(d == base + 1)
          return {x + 1, y + 1};
        if(d == base + 2)
          return {x + 1, y};
        if(d == base + 3)
          return {x, y + 1};
    }
    int len = 1 << (n - 1);
    ll block_size = 1LL << (2 * n - 2);
    if(d < base + block_size)
        return get_position(n - 1, d, base, x, y);
    if(d < base + 2 * block_size)
        return get_position(n - 1, d, base + block_size, x + len, y + len);
    if(d < base + 3 * block_size)
        return get_position(n - 1, d, base + 2 * block_size, x + len, y);
      return get_position(n - 1, d, base + 3 * block_size, x, y + len);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while
    (t--){
        int n, q;
        cin >> n >> q;
        while (q--) {
            string op;
            cin >> op;
            if (op == "->")
            {
                int x, y;
                cin >> x >> y;
                cout << get_value(n, x, y) << '\n';
            }
            else
            {
                ll d;
                cin >> d;
                pair<int, int> pos = get_position(n, d);
                cout << pos.first << ' ' << pos.second << '\n';
            }
        }
    }
    return 0;
}
