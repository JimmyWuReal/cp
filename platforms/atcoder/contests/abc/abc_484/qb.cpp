#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 
    vector<int> a(N); 
    for (auto &x : a) cin>>x; 

    sort(a.begin(), a.end()); 
    
    if (a[N-1]!=9) {
        cout<<-1<<'\n'; 
    } else {
        cout<<a[0]<<'\n'; 
    }

    return 0;
}