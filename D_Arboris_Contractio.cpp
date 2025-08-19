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
vector<vector<int>> g;
vector<int> p, d;
pair<int, int> bfs(int s, int n)
{
    d.assign(n + 1,-1);
    p.assign(n + 1,-1);
    //asjdhfgasdfjkhfg;ksldgfh
    queue<int> q;
    q.push(s);
    d[s] = 0;
    int f=s,md= 0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        //sdhjgfasdfgbaslkjh
        for(int w:g[u])
        {
            if(d[w]==-1)
            {
                d[w]=d[u]+1;
                p[w]=u;
                q.push(w);
                //ashgjvfasdfbaslhdjkfg
                if(d[w]>md)
                {
                    md=d[w];
                    //jfgklghsdfgk
                    f=w;
                }
            }
        }
    }
    return {f,md};
}
vector<int> path(int u,int v)
{
    vector<int>A,B;
    while(u!=v)
    {
        if(d[u]>=d[v])
        {
            A.push_back(u);
            //bhasfgasdhhfg
            u = p[u];
        }
        else
        {
            B.push_back(v);
            v = p[v];
        }
    }
    A.push_back(u);
    //gsdyhfksagy
    reverse(B.begin(),B.end());
    //masallah 
    A.insert(A.end(),B.begin(),B.end());
    return A;
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
    
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        g.assign(n+1,vector<int>());
        //masallah
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            //sifat alam
            g[a].push_back(b);
            //sifat alam
            g[b].push_back(a);
        }
        if(n==2)
        {
            cout << 0 << "\n";
            continue;
        }
        auto res=bfs(1,n);
        int u=res.first;
        res =bfs(u,n);
        //masallah
        int v=res.first;
        int md=res.second;
        //masallah
        vector<int> dia=path(u,v);
        int c=dia[(int)dia.size()/2];
        bfs(c, n);
        int op = 0;
        //masallah
        for(int i=1;i<=n;i++)
        {
            if(i != c&&(int)g[i].size()>1)
            //sifat alam
              op++;
        }
        cout << op << "\n";
    }
    return 0;
}