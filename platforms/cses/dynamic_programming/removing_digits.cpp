#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 
    vector<int> dp(N+1, INT_MAX); 
    dp[0]=0; 
    
    for (int x=1; x<=N; x++) {
        int tmp=x; 
        while (tmp>0) {
            int digit=tmp%10; 
            tmp/=10; 
            
            if (digit!=0) {
                dp[x]=min(dp[x], dp[x-digit]+1); 
            }
        }
    }

    cout<<dp[N]<<'\n'; 
}