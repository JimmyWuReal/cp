#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    vector<vector<int>> ppl(n); 

    for (int i = 0; i < n; i++) {
        int k; 
        cin >> k; 

        while (k--) {
            int x; 
            cin >> x; 

            ppl[x - 1].push_back(i + 1); 
        }
    }

    for (vector<int> v : ppl) {
        cout << v.size() << " "; 

        for (int x : v) cout << x << " "; 

        cout << endl; 
    }

    return 0;
}