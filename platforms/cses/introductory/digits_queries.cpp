#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 
    
    for (int i = 0; i < n; i++) {
        long long q; 
        cin >> q; 

        long long digits = 1; 
        long long cnt = 9; 
        long long start = 1; 

        while (q > digits * cnt) {
            q -= digits * cnt; 
            digits++; 
            cnt *= 10; 
            start *= 10; 
        }

        long long num = start + (q - 1) / digits; 
        long long pos = (q - 1) % digits; 
    
        string s = to_string(num); 
        cout << s[pos] << endl; 
    }


    return 0;
}