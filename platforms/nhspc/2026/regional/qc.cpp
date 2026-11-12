#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 

    vector<vector<bool>> g(N, vector<bool> (M, true)); 

    for (int i=0; i<N; i++) {
        string s; 
        cin>>s; 
        for (int j=0; j<M; j++) {
            if (s[j]=='-') g[i][j]=false; 
        }
    }

    int sm=min(N, M); 
    int res=0; 

    for (int sz=1; sz<=sm; sz++) {
        for (int x=0; x<N-sz+1; x++) { 
            for (int y=0; y<M-sz+1; y++) { 
                bool pos=true; 
                
                for (int cx=0; cx<sz; cx++) {
                    for (int cy=0; cy<sz; cy++) {
                        if (!g[x+cx][y+cy]) {
                            pos=false; 
                            break; 
                        }
                    }
                    if (!pos) break; 
                }

                if (pos) res++; 
            }
        }
    }

    cout<<res<<'\n'; 

    return 0;
}