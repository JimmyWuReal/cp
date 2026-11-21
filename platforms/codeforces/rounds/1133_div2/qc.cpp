
#include <bits/stdc++.h>
using namespace std;

using ll=long long;

bool check(const vector<ll>& a, ll x) {
    int N=a.size();
    vector<int> bad;

    for (int i=0; i+1<N; i++) {
        if (abs(a[i]-a[i+1])>x) {
            bad.push_back(i);
            if (bad.size()>2) return false;
        }
    }

    if (bad.empty()) return true;

    if (bad.size()==2) {
        int i=bad[0], j=bad[1];
        int l=i+1, r=j;

        for (int k=l; k<r; k++) {
            if (2*abs(a[k]-a[k+1])>x) return false;
        }
        
        if (abs(a[l-1]-2*a[r])>x) return false;

        if (abs(2*a[l]-a[r+1])>x) return false;

        return true;
    }

    int i=bad[0];

    int l=i+1;

    for (int r=l; r<N; r++) {
        if (r>l && 2*abs(a[r-1]-a[r])>x) break;

        bool left=abs(a[i]-2*a[r])<=x;
        bool right=(r==N-1 || abs(2*a[l]-a[r+1])<=x);

        if (left && right) return true;
    }

    int r=i;

    for (int l=r; l>=0; l--) {
        if (l<r && 2*abs(a[l]-a[l+1])>x) break;

        bool right=abs(2*a[l]-a[i+1])<=x;
        bool left=(l==0 || abs(a[l-1]-2*a[r])<=x);

        if (left && right) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 

        vector<ll> a(N); 
        for (auto &v : a) cin>>v; 
        
        ll low=0, high=0; 

        for (int i=0; i+1<N; i++) {
            high=max(high, abs(a[i]-a[i+1])); 
        }

        while (low<high) {
            ll mid=(low+high)/2; 

            if (check(a, mid)) {
                high=mid; 
            } else {
                low=mid+1; 
            }
        }

        cout<<low<<'\n'; 
    }

    return 0;
}
