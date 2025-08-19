/// ------------------------- بسم الله الرحمن الرحيم ------------------------- ///
/*
||-------------------------------------------||
||                 Author :                  ||
||              Sifat Alam                   ||
|| Dept. of Computer Science and Engineering ||
||     Southeast University (SEU), Dhaka     ||
||     Email : sifaterabbi20@gmail.com       ||
||     ID    : 2024200000174                 ||
||-------------------------------------------||
*/
#include<bits/stdc++.h>
using namespace std;
bool a()
{
    int b;
    cin >> b;
    vector<int> c(b);
    for(int i=0;i<b;i++)
    {
        cin >> c[i];
    }
    for(int i=0;i<=b-3;i++)
    {
        bool d = false;
        for(int j=0;j<3;j++)
        {
            if(c[i+j]==-1)
            {
                d = true;
                break;
            }
        }
        if(!d)
        {
            int e=min(c[i],min(c[i+1],c[i+2]));
            int f=max(c[i],max(c[i+1],c[i+2]));
            set<int> g;
            for(int j=0;j<3;j++)
            {
                g.insert(c[i+j]);
            }
            int h = 0;
            while(g.count(h))
            {
                h++;
            }
            if(h!=f-e)
            {
                return false;
            }
        }
    }
    int x = -1;
    for(int i=0;i<b;i++)
    {
        if(c[i]!=-1)
        {
            if(x==-1)
            {
                x = c[i];
            }
            else if(x!=c[i])
            {
                return false;
            }
        }
    }
    return true;
}
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define loop(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define read(arr,n) for(int i=0;i<n;i++) cin >> arr[i];
#define print(arr,n) for(int i=0;i<n;i++) cout << arr[i] << ' '; cout << endl;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

template<typename T>
void debug_vec(const vector<T>& v) {
    cerr << "[ ";
    for(const T& val : v) cerr << val << " ";
    cerr << "]\n";
}

int main() {
    FAST;
    
    int m;
    cin>>m;
    while(m--)
    {
        if(a())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}