#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin>>N>>Q; 

    vector<vector<int>> g(N), rg(N); 
    vector<Edge> edges(Q); 

    for (auto &e : edges) {
        int t, u, v; 
        cin>>t>>u>>v; 

        u--; v--; 

        e={u, v, t}; 

        g[u].push_back(v); 
        rg[v].push_back(u); 
    }

    vector<bool> vis(N, false); 
    vector<int> order; 

    for (int s=0; s<N; s++) {
        if (vis[s]) continue; 

        vector<pair<int,int>> st; 
        st.push_back({s, 0}); 
        vis[s]=true; 

        while (!st.empty()) {
            int v=st.back().first; 
            int &i=st.back().second; 

            if (i<(int)g[v].size()) {
                int to=g[v][i++]; 

                if (!vis[to]) {
                    vis[to]=true; 
                    st.push_back({to, 0}); 
                }
            } else {
                order.push_back(v); 
                st.pop_back(); 
            }
        }
    }

    reverse(order.begin(), order.end()); 

    vector<int> comp(N, -1); 
    int C=0; 

    for (int s : order) {
        if (comp[s]!=-1) continue; 

        stack<int> st; 
        st.push(s); 
        comp[s]=C; 

        while (!st.empty()) {
            int v=st.top(); 
            st.pop(); 

            for (int to : rg[v]) {
                if (comp[to]==-1) {
                    comp[to]=C; 
                    st.push(to); 
                }
            }
        }

        C++; 
    }

    vector<vector<pair<int,int>>> dag(C); 
    vector<int> indegree(C, 0); 

    for (auto e : edges) {
        int cu=comp[e.u]; 
        int cv=comp[e.v]; 

        if (cu==cv) {
            if (e.w==1) {
                cout<<"No\n"; 
                return 0; 
            }
        } else {
            dag[cu].push_back({cv, e.w}); 
            indegree[cv]++; 
        }
    }

    queue<int> que; 
    vector<int> dp(C, 1); 

    for (int i=0; i<C; i++) {
        if (indegree[i]==0) {
            que.push(i); 
        }
    }

    while (!que.empty()) {
        int v=que.front(); 
        que.pop(); 

        for (auto [to, w] : dag[v]) {
            dp[to]=max(dp[to], dp[v]+w); 
            indegree[to]--; 
            if (indegree[to]==0) que.push(to); 
        }
    }

    vector<int> A(N); 
    for (int i=0; i<N; i++) A[i]=dp[comp[i]]; 

    cout<<"Yes\n"; 

    for (int i=0; i<N; i++) {
        if (i) cout<<" "; 
        cout<<A[i]; 
    }

    cout<<"\n"; 

    return 0;
}