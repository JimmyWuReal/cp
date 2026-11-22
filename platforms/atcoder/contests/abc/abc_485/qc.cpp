#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 

    vector<int> c(N); 
    for (int &x : c) cin>>x; 

    vector<int> res(N, INT_MAX); 

    int ca=-1, cb=-1; 
    int ap=-1, bp=-1; 

    for (int i=0; i<N; i++) {
        int cur=c[i]; 

        if (ca==-1) {
            ca=cur; 
            ap=i; 
            continue;
        }

        if (cur==ca) {
            ap=i; 
            if (cb==-1) continue;
            res[i]=min(res[i], i-bp); 
        } else {
            res[i]=min(res[i], i-ap); 

            cb=cur; 
            bp=i; 

            swap(cb, ca); 
            swap(bp, ap); 
        }
    }

    ca=-1; cb=-1; 
    ap=-1; bp=-1; 

    for (int i=N-1; i>=0; i--) {
        int cur=c[i]; 

        if (ca==-1) {
            ca=cur; 
            ap=i; 
            continue;
        }

        if (cur==ca) {
            ap=i; 
            if (cb==-1) continue;

            res[i]=min(res[i], bp-i); 
        } else {
            res[i]=min(res[i], ap-i); 

            cb=cur; 
            bp=i; 

            swap(cb, ca); 
            swap(bp, ap); 
        }
    } 

    for (int i=0; i<N; i++) {
        cout<<res[i]<<' '; 
    }

    cout<<'\n'; 

    return 0;
}