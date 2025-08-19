#include <iostream>
#include <vector>
using namespace std;

// Helper function to create the permutation
vector<int> createPermutation(int n, int k) {
    vector<int> permutation(n);
    
    // Fill the permutation array in a way that minimizes the sum of the minimums of all subarrays of length k
    int num = 1;
    for (int i = 0; i < n; i++) {
        permutation[i] = num++;
    }

    return permutation;
}

// Function to print the permutation
void printPermutation(const vector<int>& permutation) {
    for (int i = 0; i < permutation.size(); i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    // Process each test case
    while (t--) {
        int n, k;
        cin >> n >> k;

        // Generate and print the permutation
        vector<int> permutation = createPermutation(n, k);
        printPermutation(permutation);
    }

    return 0;
}
