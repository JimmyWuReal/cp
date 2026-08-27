// Code written by Jimmy Wu (JingZe Wu) 
// AC during the contest 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;
        vector<int> v(n); 
        for (int i = 0; i < n; i++) cin >> v[i]; 

        int ans = 0; 

        for (int i = 0; i < n; i++) {
            int pos = find(v.begin(), v.end(), i + 1) - v.begin(); 

            if (pos != i) {
                swap(v[i], v[pos]); 
                ans++; 
            }
        }

        cout << ans << endl; 
    }

    return 0;
}