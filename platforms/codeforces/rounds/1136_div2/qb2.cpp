#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 

        string s; 
        s.push_back('+'); 
        for (int i=0; i<N-1; i++) s=s+"--+"; 

        cout<<s<<endl; 

        int x; cin>>x; 

        if (x==0) {
            cout<<N<<endl; 
        } else if (x==1) {
            cout<<N+1<<endl; 
        } else {
            cout<<(x-1)/3+N+1<<endl; 
        }
    }

    return 0;
}