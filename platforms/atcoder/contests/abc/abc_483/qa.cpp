#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 

    if (N%2==0) {
        cout<<N/2<<'\n'; 
    } else {
        cout<<(N+1)/2<<'\n'; 
    }

    return 0;
}