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

        vector<long long> a(n); 
        for (auto &x : a) cin >> x; 

        auto b = max_element(a.begin(), a.end()); 
        long long bn = *b;
        a.erase(b); 

        auto bb = max_element(a.begin(), a.end()); 
        long long bbn = *bb; 
        a.erase(bb); 

        queue<long long> even; 
        queue<long long> odd; 

        for (int i = 0; i < n - 2; i++) {
            if (a[i] % 2 == 0) {
                even.push(a[i]); 
            } else {
                odd.push(a[i]); 
            }
        }
        long long is_even = bn % 2 == 1; 

        long long res = 0; 
        long long last = bn; 

        for (int i = 0; i < n - 2; i++) {
            if ((is_even && !even.empty()) || odd.empty()) {
                long long x = even.front(); 
                even.pop(); 

                res += (x + last) / 2; 
                last = x; 

                is_even = false; 
            } else {
                long long x = odd.front(); 
                odd.pop(); 

                res += (x + last) / 2; 
                last = x; 

                is_even = true; 
            }
        }

        res += (bbn + last) / 2; 
        cout << res << endl; 
    }

    return 0;
}
