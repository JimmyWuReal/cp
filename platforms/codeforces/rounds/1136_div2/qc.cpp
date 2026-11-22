#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 
    
    while (T--) {
        long long N, X; cin>>N>>X; 
        vector<long long> a(N); 
        for (long long &x : a) cin>>x; 
        sort(a.begin(), a.end()); 

        long long cur=0; 

        long long res=0; 

        for (int i=0; i<N-1; i++) {
            cur++; 
            if (cur*X<a[i]) {
                long long add=(a[i]+X-1LL)/X-cur; 
                cur+=add; 
                res+=add; 
            }
        }

        cout<<res<<'\n'; 
    }

    return 0;
}