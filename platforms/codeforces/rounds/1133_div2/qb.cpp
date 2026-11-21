#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T; 

    while (T--) { 
        int N; cin>>N; 

        cout<<"? 1 "<<N<<endl; 
        int k; cin>>k; 

        if (k==0 || k==N) {
            cout<<"! NO"<<endl; 
            continue; 
        }

        cout<<"? 1 "<<k<<endl; 
        int x; cin>>x; 

        if (x==k) {
            cout<<"! NO"<<endl; 
        } else {
            cout<<"! YES"<<endl; 
        }
    }

    return 0;
}