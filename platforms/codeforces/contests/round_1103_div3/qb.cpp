#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        int n, k; 
        cin >> n >> k; 

        string s; 
        cin >> s; 

        vector<int> cnt(k); 
        int place = 0; 

        for (char c : s) { 
            if (c == '1') {
                cnt[place]++; 
            }

            place++; 
            if (place == k) place = 0; 
        } 

        bool found = false; 

        for (int i : cnt) {
            if (i % 2 == 1) {
                found = true; 
                break; 
            }
        }

        cout << (found ? "NO" : "YES") << endl; 
    }

    return 0;
}