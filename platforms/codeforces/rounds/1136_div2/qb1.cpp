#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int x, y, m; cin>>x>>y>>m; 
        string s; cin>>s; 

        int lim=x+y+m; 

        vector<vector<bool>> dp(lim+1, vector<bool>(lim+1, false)); 
        dp[x][y]=true; 

        int res=x+y; 

        for (char c : s) {
            vector<vector<bool>> ndp(lim+1, vector<bool>(lim+1, false)); 

            for (int a=0; a<=lim; a++) {
                for (int b=0; a+b<=lim; b++) {
                    if (!dp[a][b]) continue;

                    if (c=='+') {
                        if (a>0) {
                            ndp[a-1][b+1]=true; 
                            res=max(res, a+b); 
                        } 

                        if (b>0) {
                            ndp[a][b+1]=true; 
                            res=max(res, a+b+1); 
                        }
                    } else {
                        if (a>0) {
                            ndp[a-1][b]=true; 
                            res=max(res, a+b-1); 
                        }

                        if (b>0) {
                            ndp[a+1][b-1]=true; 
                            res=max(res, a+b); 
                        }
                    }
                }
            }

            dp.swap(ndp); 
        }

        cout<<res<<'\n'; 
    }

    return 0;
}
