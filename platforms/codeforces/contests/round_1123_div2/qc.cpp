#include <bits/stdc++.h>
using namespace std;

vector<int> dpf(int x) {
    vector<int> res; 
    if (x%2==0) {
        res.push_back(2); 
        while(x%2==0) x/=2;  
    }

    for (int i=3; 1LL*i*i<=x; i+=2) {
        if (x%i==0) {
            res.push_back(i); 
            while (x%i==0) x/=i; 
        }
    }

    if (x>1) res.push_back(x); 
    return res; 
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 
    
    while (T--) {
        int N; cin>>N;
        int X; cin>>X; 

        vector<int> a(N); 
        for (int &x : a) cin>>x; 

        vector<int> f=dpf(X); 
        vector<long long> v(f.size(), 0); 
        int ps=v.size(); 
        
        for (int j=0; j<ps; j++) {
            int p=f[j]; 
            for (int i=0; i<N; i++) if (a[i]%p==0) v[j]+=a[i]; 
        }

        if (ps==0) {
            cout<<0<<'\n'; 
        } else {
            cout<<*max_element(v.begin(), v.end())<<'\n'; 
        }
    }

    return 0;
}