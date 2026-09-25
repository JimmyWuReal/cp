#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; long long K; cin>>N>>M>>K; 
    long long X, Y; cin>>X>>Y; 

    vector<long long> A(N), B(M);

    for (auto &a : A) cin>>a;
    for (auto &b : B) cin>>b;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> prefixA(N+1, 0);

    for (int i=0; i<N; i++) prefixA[i+1]=prefixA[i]+A[i]; 

    long long totalMoney=X+K*Y; 

    long long drinkCost=0;  
    long long kBillsUsed=0; 

    int ans=0;

    for (int d=0; d<=M; d++) {
        if (kBillsUsed>Y) break;
        if (drinkCost>totalMoney) break;

        long long remaining=totalMoney - drinkCost;

        int desserts=upper_bound(
            prefixA.begin(),
            prefixA.end(),
            remaining
        ) - prefixA.begin() - 1;

        ans=max(ans, d+desserts);

        if (d == M) break;

        drinkCost+=B[d];

        kBillsUsed+=B[d]/K+(B[d]%K != 0);
    }

    cout<<ans<<'\n';

    return 0;
}