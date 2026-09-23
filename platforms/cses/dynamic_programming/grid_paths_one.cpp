#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 
    vector<vector<char>> grid(N, vector<char>(N, 0)); 
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) cin>>grid[i][j]; 
    }

    if (grid[0][0]=='*') {
        cout<<0<<'\n'; 
        return 0; 
    }
    vector<vector<int>> times(N, vector<int>(N, 0)); 
    times[0][0]++; 
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (grid[i][j]=='*') continue; 

            if (i!=0) times[i][j]+=times[i-1][j]; 
            if (j!=0) times[i][j]+=times[i][j-1]; 

            times[i][j]%=1000000000+7; 
        }
    }

    cout<<times[N-1][N-1]<<'\n'; 

    return 0; 
}