#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> x, vector<int> y) {
    if (x[2] != y[2]) return x[2] > y[2]; 
    if (x[1] != y[1]) return x[1] > y[1]; 
    return x[0] < y[0]; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 
    
    vector<vector<int>> c(n); 

    for (int i = 0; i < n; i++) {
        int a, b; 
        cin >> a >> b; 

        c[i] = {i, a, b}; 
    }

    sort(c.begin(), c.end(), comp); 

    for (vector<int> x : c) {
        cout << x[0] + 1 << endl; 
    }

    return 0;
}