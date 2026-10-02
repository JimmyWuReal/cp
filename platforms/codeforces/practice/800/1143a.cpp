#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 
    vector<int> doors(N); 
    for (auto &x : doors) cin>>x; 

    int first=doors[N-1]; 

    for (int i=N-1; i>=0; i--) {
        if (doors[i]!=first) {
            cout<<i+1<<'\n'; 
            break; 
        }
    }

    return 0; 
}