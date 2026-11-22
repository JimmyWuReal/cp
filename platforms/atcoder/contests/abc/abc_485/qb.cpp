#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 
    
    bool found=false; 

    string s; 

    for (int i=0; i<N; i++) {
        cin>>s; 
        if (found) continue;
        if (count(s.begin(), s.end(), 'o')==0) {
            cout<<"Faucet "<<i+1<<'\n'; 
            found=true; 
        }
    }

    if (!found) cout<<"Drain "<<find(s.begin(), s.end(), 'x')-s.begin()+1<<'\n'; 

    return 0;
}