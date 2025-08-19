#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node* children[2];
    {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};
void insert(Node* root,int num)
{
    Node* node = root;
    for(int i=30; i>=0; i--)
    {
        int bit = (num >> i) & 1;
        if(!node->children[bit])
        {
            node->children[bit] = new Node();
        }
        node = node->children[bit];
    }
}
int findmx(Node* root, int num)
{
    int max_xor = 0;
    Node* node = root;
    for(int i=30; i>=0; i--)
    {
        int bit = (num >> i) & 1;
        int toggle_bit = 1 - bit;
        if(node->children[toggle_bit])
        {
            max_xor += (1 << i);
            node = node->children[toggle_bit];
        }
        else
        {
            node = node->children[bit];
        }
    }
    return max_xor;
}

void deletetrie(Node* root)
{
    if(!root)
      return;
    deletetrie(root->children[0]);
    deletetrie(root->children[1]);
    delete root;
}

int shortest(const vector<int>& a, int k)
{
    int n = a.size();
    int min_ln = n + 1;
    for(int l = 0; l < n; l++)
    {
        Node* root = new Node();
        insert(root, a[l]);
        int curr_mx = 0;
        for(int r = l; r < n; r++)
        {
            if(r > l)
            {
                curr_mx = max(curr_mx, findmx(root, a[r]));
                insert(root, a[r]);
            }
            if(curr_mx >= k)
            {
                min_ln = min(min_ln, r - l + 1);
                break;
            }
        }
        deletetrie(root);
        if(min_ln == 1)
          break;
    }
    return min_ln <= n ? min_ln : -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int p, q;
        cin >> p >> q;
        vector<int> a(p);
        for(int i=0; i<p;i++)
        {
            cin >> a[i];
        }
        cout << shortest(a,q) << '\n';
    }
    return 0;
}