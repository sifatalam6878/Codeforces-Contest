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
long long zz(long long tt,long long ll,long long uu,long long xx,long long yy)
{
    long long pp = 0, qq = 0;
    if(tt >= ll)
    {
        pp = (tt - ll)/xx +1;
    }
    if(tt>= uu)
    {
        qq =(tt-uu)/yy+1;
    }
    long long rr = max(pp, qq);
    if(tt>= ll)
    {
        long long aa = (tt - ll)/xx + 1;
        long long bb = tt - aa * xx;
        long long cc = 0;
        if(bb>= uu)
        {
            cc= (bb-uu)/yy+1;
        }
        rr = max(rr,aa+cc);
    }
    if(tt>=uu)
    {
        long long dd=(tt - uu)/yy + 1;
        long long ee=tt - dd * yy;
        long long ff= 0;
        if(ee>=ll)
        {
            ff=(ee-ll)/xx+ 1;
        }
        rr = max(rr, dd + ff);
    }
    return rr;
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
    
    int gg;
    cin >> gg;
    while(gg--)
    {
        long long tt,ll,uu,xx,yy;
        cin >> tt >> ll >> uu >> xx >> yy;
        cout << zz(tt,ll,uu,xx,yy) << "\n";
    }
    return 0;
}