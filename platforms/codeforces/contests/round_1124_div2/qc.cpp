#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin>>N>>K;

        vector<long long> a(N);
        for (auto &x : a) cin>>x;

        int remain=K-1;
        int removed=N-K+1;
        int pairs=min(remain, removed);

        long long ans=0;

        for (int i=0; i<pairs; i++) ans+=max(a[i], a[N-1-i]);

        if (removed>remain) {
            for (int i=remain; i<N-remain; i++) ans+=a[i];
        }

        cout<<ans<<'\n';
    }
}