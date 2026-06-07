#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    unordered_map<int, int> m; 

    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x; 

        m[i] = x; 
    }

    bool truth = true; 

    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x; 

        if (m[x] != i) {
            truth = false; 
            break; 
        }
    }

    if (truth) {
        cout << "Yes" << endl; 
    } else {
        cout << "No" << endl; 
    }

    return 0;
}