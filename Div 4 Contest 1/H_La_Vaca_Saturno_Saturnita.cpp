#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Compute smallest prime factor for fast factorization
vector<int> smallest_prime_factor(int max_n) {
    vector<int> spf(max_n + 1);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= max_n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= max_n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    return spf;
}

// Factorize a number into prime factors and exponents
void factorize(int x, const vector<int>& spf, map<int, int>& factors) {
    factors.clear();
    while (x > 1) {
        int p = spf[x];
        factors[p]++;
        x /= p;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Precompute smallest prime factors
    const int MAX_N = 100000;
    static vector<int> spf = smallest_prime_factor(MAX_N);
    
    // Factorize a[i] and collect all primes
    vector<map<int, int>> a_factors(n + 1);
    set<int> all_primes;
    for (int i = 1; i <= n; i++) {
        factorize(a[i], spf, a_factors[i]);
        for (const pair<int, int>& p : a_factors[i]) {
            all_primes.insert(p.first);
        }
    }
    
    while (q--) {
        ll k;
        int l, r;
        cin >> k >> l >> r;
        
        map<int, int> k_factors;
        factorize(k, spf, k_factors);
        
        ll ans = 0;
        // For each index i from l to r
        for (int i = l; i <= r; i++) {
            map<int, int> curr_k = k_factors;
            // Remove factors based on a[i]'s factorization
            for (const pair<int, int>& p : a_factors[i]) {
                int prime = p.first;
                int exp = p.second;
                curr_k[prime] -= exp;
                if (curr_k[prime] <= 0) {
                    curr_k.erase(prime);
                }
            }
            // Compute current k
            ll val = 1;
            for (const pair<int, int>& p : curr_k) {
                int prime = p.first;
                int exp = p.second;
                for (int j = 0; j < exp; j++) {
                    val *= prime;
                }
            }
            ans += val;
        }
        
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}