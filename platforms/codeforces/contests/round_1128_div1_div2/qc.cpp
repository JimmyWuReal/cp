#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 

        int odd=0; 

        for (int i=0; i<N; i++) {
            int x; cin>>x; 
            odd+=(x&1); 
        }

        int even=N-odd; 

        if ((odd==1 && even==1) || (odd==3 && even==0)) {
            cout<<"Larpity"<<'\n'; 
        } else {
            cout<<"Moggity"<<'\n'; 
        }
    }

    return 0;
}