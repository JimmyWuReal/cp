#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; 
    cin >> n >> x;
    vector<int> w(n); 
    for (int i = 0; i < n; i++) cin >> w[i]; 

    sort(w.begin(), w.end(), greater<int>()); 
    
    int pos = n; 

    int ans = 0; 

    for (int i = 0; i < pos; i++) {
        if (w[i] + w[pos - 1] <= x) pos--; 
        ans++; 
    }

    cout << ans << endl; 

    return 0;
}