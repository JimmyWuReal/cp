#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin>>S; 

    int N=S.size(); 
    vector<int> z(N); 

    int l=0, r=0; 
    
    for (int i=1; i<N; i++) {
        if (i<r) z[i]=min(r-i, z[i-l]);

        while (i+z[i]<N && S[z[i]]==S[i+z[i]]) z[i]++;

        if (i+z[i]>r) {
            l=i;
            r=i+z[i];
        }
    }

    for (int i=1; i<N; i++) {
        if (z[i]>=N-i) {
            cout<<i<<' ';
        }
    }

    cout<<N<<'\n';

    return 0;
}