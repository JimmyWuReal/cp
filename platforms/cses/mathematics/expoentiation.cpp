#include <bits/stdc++.h>
using namespace std;

long long MOD=1e9+7; 

long long solve(long long a, long long b) {
    if (b==0) return 1; 
    
    if (b%2==0) {
        long long half=solve(a, b / 2); 
        half%=MOD; 
        half*=half; 
        half%=MOD; 

        return half; 
    } else {
        return (solve(a, b-1)*a)%MOD; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin>>N; 
    for (long long i=0; i<N; i++) {
        long long a, b; cin>>a>>b; 
        long long res=solve(a, b); 
        cout<<res<<'\n'; 
    }

    return 0; 
}