#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    long long M;

    cin>>n>>k>>M;

    vector<long long> t(k);
    long long sum=0;

    for (auto &x : t) {
        cin>>x;
        sum+=x;
    }

    sort(t.begin(), t.end());

    long long ans=0;

    for (int full=0; full<=n; full++) {

        long long cost=1LL*full*sum;

        if (cost>M) break;

        long long remain=M-cost;
        long long score=1LL*full*(k+1);
        int left=n-full;

        for (int i=0;i<k; i++) {
            long long cnt=min(
                (long long)left,
                remain/t[i]
            );

            remain-=cnt*t[i];
            score+=cnt;
        }

        ans=max(ans, score);
    }

    cout<<ans<<'\n';

    return 0;
}