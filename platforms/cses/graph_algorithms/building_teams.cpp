#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 
    vector<vector<int>> f(N); 

    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b; 
        a--; b--; 
        f[a].push_back(b); 
        f[b].push_back(a); 
    }

    vector<int> team(N, 0); 

    for (int i=0; i<N; i++) {
        if (team[i]!=0) continue; 

        queue<int> q; 
        q.push(i); 
        team[i]=1; 

        while (!q.empty()) {
            int x=q.front(); 
            q.pop(); 

            for (int y : f[x]) {
                if (team[y]==0) {
                    team[y]=3-team[x]; 
                    q.push(y); 
                } else if (team[y]==team[x]) {
                    cout<<"IMPOSSIBLE\n"; 
                    return 0; 
                }
            }
        }
    }

    for (int i : team) {
        cout<<i<<' '; 
    }

    cout<<'\n'; 

    return 0; 
}