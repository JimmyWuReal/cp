#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;

    vector<int> a(N-1), b(N-1);

    for (int &x : a) cin>>x;
    for (int &x : b) cin>>x;

    vector<vector<int>> dp(N, vector<int>(4, 0));
    vector<vector<int>> par(N, vector<int>(4, -1));

    for (int x=0; x<4; x++) {
        dp[0][x]=1;
    }

    for (int i=0; i<N-1; i++) {
        for (int x=0; x<4; x++) {
            if (!dp[i][x]) continue;

            for (int y=0; y<4; y++) {
                if ((x|y)==a[i] && (x&y)==b[i]) {
                    dp[i+1][y]=1;
                    par[i+1][y]=x;
                }
            }
        }
    }

    int last=-1;

    for (int x=0; x<4; x++) {
        if (dp[N-1][x]) {
            last=x;
            break;
        }
    }

    if (last==-1) {
        cout<<"NO\n";
        return 0;
    }

    vector<int> ans(N);

    ans[N-1]=last;

    for (int i=N-1; i>0; i--) {
        ans[i-1]=par[i][ans[i]];
    }

    cout<<"YES\n";

    for (int x : ans) {
        cout<<x<<' ';
    }

    cout<<'\n';
}