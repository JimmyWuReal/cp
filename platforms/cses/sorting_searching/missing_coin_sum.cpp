#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<int> coins(n); 
    
    for (int i = 0; i < n; i++) cin >> coins[i]; 

    sort(coins.begin(), coins.end()); 

    long long reach = 0; 

    for (int c : coins) {
        if (c > reach + 1) {
            cout << reach + 1 << endl; 
            return 0; 
        }

        reach += c; 
    }

    cout << reach + 1 << endl; 

    return 0;
}

// NOTE 
// because it can form to x, it can form to x + 1 only if the next one <= x + 1, if so it could form up to next one + x. 