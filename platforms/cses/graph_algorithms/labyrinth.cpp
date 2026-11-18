#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 

    vector<vector<bool>> seen(N, vector<bool> (M, false)); 

    int sx, sy, tx, ty; 

    for (int i=0; i<N; i++) {
        string x; cin>>x; 
        for (int j=0; j<M; j++) {
            if (x[j]=='A') {
                sx=i;
                sy=j; 
            } else if (x[j]=='B') {
                tx=i; 
                ty=j; 
            } else if (x[j]=='#') {
                seen[i][j]=true; 
            }
        }
    }

    vector<vector<char>> dir(N, vector<char> (M)); 

    queue<pair<int, int>> q; 
    q.push({sx, sy}); 
    seen[sx][sy]=true; 

    while (!q.empty()) {
        pair<int, int> cur=q.front(); 
        q.pop(); 
        int cx=cur.first, cy=cur.second; 

        if (cx==tx && cy==ty) break; 

        vector<int> xc={1, -1, 0, 0}; 
        vector<int> yc={0, 0, 1, -1}; 
        vector<char> mv={'D', 'U', 'R', 'L'}; 

        for (int i=0; i<4; i++) {
            int x=cx+xc[i]; 
            int y=cy+yc[i]; 

            if (x<0 || x>=N) continue;
            if (y<0 || y>=M) continue;
            if (seen[x][y]) continue;

            seen[x][y]=true; 
            dir[x][y]=mv[i]; 
            q.push({x, y}); 
        }
    }

    if (!seen[tx][ty]) {
        cout<<"NO\n"; 
    } else {
        cout<<"YES\n"; 

        string res; 
        int x=tx, y=ty; 

        while (x!=sx || y!=sy) {
            res.push_back(dir[x][y]); 

            char c=dir[x][y]; 

            if (c=='R') y--; 
            if (c=='L') y++; 
            if (c=='D') x--; 
            if (c=='U') x++; 
        }

        reverse(res.begin(), res.end()); 

        cout<<res.size()<<'\n'; 
        cout<<res<<'\n'; 
    }

    return 0;
}