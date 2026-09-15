#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 
    vector<vector<int>> grid(N, vector<int>(N, -1)); 

    grid[0][0]=0; 

    queue<pair<int, int>> q; 
    q.push({0, 0}); 

    while (!q.empty()) {
        pair<int, int> pos=q.front(); q.pop(); 
        int x=pos.first; int y=pos.second; 

        int ori=grid[x][y]; 

        vector<int> xc={-2, -2, -1, 1, 2, 2, 1, -1}; 
        vector<int> yc={-1, 1, 2, 2, 1, -1, -2, -2}; 

        for (int i=0; i<8; i++) {
            if (x+xc[i]>=0 && x+xc[i]<N && y+yc[i]>=0 && y+yc[i]<N) {
                if (grid[x+xc[i]][y+yc[i]]==-1) {
                    grid[x+xc[i]][y+yc[i]]=ori+1; 
                    q.push({x+xc[i], y+yc[i]}); 
                }
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout<<grid[i][j]<<' '; 
        }
        cout<<'\n'; 
    }

    return 0; 
}