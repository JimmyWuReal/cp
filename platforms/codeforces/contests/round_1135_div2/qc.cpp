#include <bits/stdc++.h>
using namespace std;

using ll=long long; 

const ll MOD=1e9+7; 

ll pow(ll x, ll a) {
    if (a==0) return 1; 

    if (a%2==0) {
        ll temp=pow(x, a/2LL); 
        temp=temp%MOD; 

        return (temp*temp)%MOD; 
    } else {
        ll temp=pow(x, a-1LL); 

        return (x*temp)%MOD; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 

        vector<ll> a(N); 
        for (ll &x : a) cin>>x; 

        sort(a.begin(), a.end(), greater<ll>()); 

        ll res=0; 

        for (int i=0; i<N; i++) {
            if (i!=N-1 && a[i]==a[i+1]) break; 

            res+=pow(a[i]-1LL, i+1LL); 
            res%=MOD; 
        }

        res+=1LL; 
        res%=MOD; 

        cout<<res<<'\n'; 
    }

    return 0;
}