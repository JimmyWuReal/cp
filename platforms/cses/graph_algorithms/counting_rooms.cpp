#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 
    
    vector<vector<bool>> g(N, vector<bool>(M, false)); 

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char c; cin>>c; 
            if (c=='.') g[i][j]=true; 
        }
    }

    vector<vector<bool>> seen(N, vector<bool>(M, false)); 
 
    int res=0; 
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (seen[i][j] || g[i][j]==false) continue;

            queue<pair<int, int>> q; 
            q.push({i, j}); 

            seen[i][j]=true; 

            while (!q.empty()) {
                pair<int, int> cur=q.front(); 
                q.pop(); 

                if (cur.first>0 && !seen[cur.first-1][cur.second] && g[cur.first-1][cur.second]) {
                    seen[cur.first-1][cur.second]=true; 
                    q.push({cur.first-1, cur.second}); 
                } 

                if (cur.first<N-1 && !seen[cur.first+1][cur.second] && g[cur.first+1][cur.second]) {
                    seen[cur.first+1][cur.second]=true; 
                    q.push({cur.first+1, cur.second}); 
                } 
                
                if (cur.second>0 && !seen[cur.first][cur.second-1] && g[cur.first][cur.second-1]) {
                    seen[cur.first][cur.second-1]=true; 
                    q.push({cur.first, cur.second-1}); 
                } 
                
                if (cur.second<M-1 && !seen[cur.first][cur.second+1] && g[cur.first][cur.second+1]) {
                    seen[cur.first][cur.second+1]=true; 
                    q.push({cur.first, cur.second+1}); 
                } 
            }

            res++; 
        }
    }

    cout<<res<<'\n'; 

    return 0;
}