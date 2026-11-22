
#include <bits/stdc++.h>
using namespace std;

struct st {
    int u, color, dist;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M;

    vector<vector<pair<int,int>>> adj(N+1);

    for (int i=0; i<M; i++) {
        int u, v, c; cin>>u>>v>>c;
        adj[u].push_back({v, c});
    }

    vector<int> first(N+1, -2);
    vector<int> second(N+1, -2);

    queue<st> q;
    q.push({1, -1, 0});

    while (!q.empty()) {
        auto [v, last, dist]=q.front();
        q.pop();

        if (first[v]==-2) {
            first[v]=last;
        } else if (first[v]==last) {
            continue;
        } else if (second[v]==-2) {
            second[v]=last;
        } else {
            continue;
        }

        if (v==N) {
            cout<<dist<<'\n';
            return 0;
        }

        for (auto [to, c]:adj[v]) {
            if (c!=last) q.push({to, c, dist+1});
        }
    }

    cout<<-1<<'\n';
}
