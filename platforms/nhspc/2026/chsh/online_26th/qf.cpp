#include <bits/stdc++.h>
using namespace std;

long long dp(long long left) {
    if (left == 0) return 1; 

    if (left % 2 == 0) {
        long long a = dp(left / 2); 
        long long res = a * a; 
        res %= 1000000007; 
        return res; 
    } else {
        long long res = dp(left - 1) * 2; 
        res %= 1000000007; 
        return res; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; 
    cin >> n; 

    long long x = dp(n); 
    long long ans = (x + 1) * x / 2; 
    ans %= 1000000007; 

    cout << ans << endl; 

    return 0;
}