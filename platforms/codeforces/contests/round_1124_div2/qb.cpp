#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 

        vector<int> a(N); 
        for (int &x : a) cin>>x; 

        for (int i=0; i<N; i++) {
            int X=a[i]; 
            for (int t=0; t<1600; t++) {
                int temp=0; 
                while (X>0) {
                    int digit=X%10; 
                    temp+=digit*digit; 
                    X/=10; 
                }
                X=temp; 
            }
            a[i]=X; 
        }

        map<int, int> m; 
        for (int i : a) m[i]++; 

        int res=0; 
        for (auto &[k, v] : m) {
            res+=v*(v-1)/2; 
        }

        cout<<res<<'\n'; 
    }

    return 0;
}