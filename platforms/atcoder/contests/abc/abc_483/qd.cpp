#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;

    vector<long long> a(N);
    for (auto &x : a) cin>>x;

    vector<long long> prefix(N+1, 0);
    for (int i=0; i<N; i++) prefix[i+1]=prefix[i]+a[i];

    vector<long long> sufmx(N+1), sufmn(N+1);

    sufmx[N]=sufmn[N]=prefix[N];

    for (int i=N-1; i>=0; i--) {
        sufmx[i]=max(sufmx[i+1], prefix[i]);
        sufmn[i]=min(sufmn[i+1], prefix[i]);
    }

    long long res=sufmx[0]-sufmn[0]+1;
    long long premx=0, premn=0;

    for (int i=0; i<N; i++) {
        long long mx=max(premx, sufmx[i+1]-2*a[i]);
        long long mn=min(premn, sufmn[i+1]-2*a[i]);

        res=max(res, mx-mn+1);

        premx=max(premx, prefix[i+1]);
        premn=min(premn, prefix[i+1]);
    }

    cout<<res<<"\n";

    return 0;
}