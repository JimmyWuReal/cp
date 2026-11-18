#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 
    vector<vector<bool>> a(N, vector<bool> (M, false));  

    for (int i=0; i<N; i++) {
        string x; cin>>x; 
        for (int j=0; j<M; j++) {
            if (x[j]=='#') a[i][j]=true; 
        }
    }

    queue<pair<int, int>> q; 

    int res=0; 

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!a[i][j]) {
                q.push({i, j}); 
                a[i][j]=true; 

                while (!q.empty()) {
                    pair<int, int> cur=q.front(); 
                    int px=cur.first, py=cur.second; 
                    q.pop(); 

                    vector<int> x={1, -1, 0, 0}; 
                    vector<int> y={0, 0, 1, -1}; 

                    for (int i=0; i<4; i++) {
                        int cx=px+x[i], cy=py+y[i]; 

                        if (cx<0 || cx>=N) continue;
                        if (cy<0 || cy>=M) continue; 
                        if (a[cx][cy]) continue;

                        a[cx][cy]=true; 
                        q.push({cx, cy}); 
                    }
                }

                res++; 
            }
        }
    }

    cout<<res<<'\n'; 

    return 0;
}