#include <bits/stdc++.h>
using namespace std;

using ll=long long;

const ll INF=4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin>>N>>Q;

    vector<ll> A(N+1), B(N+1);

    for (int i=1; i<=N; i++) cin>>A[i];
    for (int i=1; i<=N; i++) cin>>B[i];

    vector<ll> prefix(N+1, 0);

    for (int i=1; i<=N; i++) prefix[i]=prefix[i-1]+A[i];

    ll total=prefix[N];

    vector<ll> dist(N+1);

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    for (int i=1; i<=N; i++) {
        dist[i]=B[i];
        pq.push({dist[i], i});
    }

    while (!pq.empty()) {
        auto [d, u]=pq.top();
        pq.pop();

        if (d!=dist[u]) continue;

        int right=(u==N ? 1 : u+1);
        ll rightCost=A[u];

        if (dist[right]>d+rightCost) {
            dist[right]=d+rightCost;
            pq.push({dist[right], right});
        }

        int left=(u==1 ? N : u-1);

        ll leftCost=A[left];

        if (dist[left]>d+leftCost) {
            dist[left]=d+leftCost;
            pq.push({dist[left], left});
        }
    }

    auto cycleDist=[&](int s, int t) -> ll {
        if (s>t) swap(s, t);

        ll d1=prefix[t-1]-prefix[s-1];
        ll d2=total-d1;

        return min(d1, d2);
    };

    while (Q--) {
        int S, T; cin>>S>>T;

        if (T==N+1) {
            cout<<dist[S]<<'\n';
            continue;
        }

        ll aroundCycle=cycleDist(S, T);
        ll throughHub=dist[S]+dist[T];

        cout<<min(aroundCycle, throughHub)<<'\n';
    }

    return 0;
}