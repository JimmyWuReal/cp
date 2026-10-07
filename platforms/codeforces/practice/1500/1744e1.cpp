// the same solution as 1744e2
#include <bits/stdc++.h>
using namespace std;

using ll=long long; 

vector<pair<ll, int>> fac(ll n) {
    vector<pair<ll, int>> f; 

    for (ll p=2; p*p<=n; p++) {
        if (n%p==0) {
            int cnt=0; 
            while (n%p==0) {
                n/=p; 
                cnt++; 
            }

            f.push_back({p, cnt}); 
        }
    }

    if (n>1) f.push_back({n, 1}); 

    return f; 
}

void div(int idx, ll cur, const vector<pair<ll, int>> &fac, vector<ll> &divs) {
    if (idx==(int)fac.size()) {
        divs.push_back(cur); 
        return; 
    }

    auto [p, cnt]=fac[idx]; 

    ll val=1; 

    for (int e=0; e<=cnt; e++) {
        div(idx+1, cur*val, fac, divs); 
        val*=p; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        ll a, b, c, d; cin>>a>>b>>c>>d; 

        map<ll, int> mp;

        for (auto [p, cnt] : fac(a)) mp[p]+=cnt;
        for (auto [p, cnt] : fac(b)) mp[p]+=cnt;

        vector<pair<ll, int>> factor(mp.begin(), mp.end());

        vector<ll> divs;
        div(0, 1, factor, divs);

        ll P=a*b;

        ll ansX=-1;
        ll ansY=-1;

        for (ll g : divs) {
            ll h=P/g;

            ll x=(a/g+1)*g;
            ll y=(b/h+1)*h;

            if (x<=c && y<=d) {
                ansX=x;
                ansY=y;
                break;
            }
        }

        cout<<ansX<<' '<<ansY<<'\n';
    }
}