#include <bits/stdc++.h>
using namespace std;

int power(int a, int b, int mod) {
    if (b==0) return 1; 

    if (b%2==0) {
        long long temp=power(a, b/2, mod)%mod; 
        return (temp*temp)%mod; 
    } else {
        return (1LL*a*power(a, b-1, mod))%mod; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int a, b, c; cin>>a>>b>>c; 

        int MOD=1e9+7; 

        long long p=power(b, c, MOD-1); 
        long long res=power(a, p, MOD);  
        res%=MOD; 

        cout<<res<<'\n'; 
    }

    return 0; 
}