#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 
    int all=M/N; 
    int left=M-all*N; 
    int other=N-left; 

    for (int i=0; i<left; i++) {
        cout<<all+1<<'\n'; 
    }

    for (int i=0; i<other; i++) {
        cout<<all<<'\n'; 
    }

    return 0;
}