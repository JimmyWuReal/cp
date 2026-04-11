#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<int> apples(n); 
    long long total = 0; 

    for (int i = 0; i < n; i++) {
        cin >> apples[i]; 
        total += apples[i]; 
    } 

    long long res = LLONG_MAX; 

    for (int i = 0; i < (1 << n); i++) {

        long long sum = 0; 

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sum += apples[j]; 
        }

        if (abs(total - 2 * sum) < res) res = abs(total - 2 * sum); 
    }

    cout << res; 

    return 0;
}