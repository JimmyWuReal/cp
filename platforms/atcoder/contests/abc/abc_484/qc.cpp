#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 
    vector<int> a(N); 
    vector<int> b(N); 
    for (int &x : a) cin>>x; 
    for (int &x : b) cin>>x;

    int start, end; 
    for (int i=0; i<N; i++) {
        if (a[i]!=b[i]) {
            start=i; 
            break; 
        }
    }

    for (int i=N-1; i>=0; i--) {
        if (a[i]!=b[i]) {
            end=i; 
            break; 
        }
    }

    vector<int> ad, bd; 
    for (int i=0; i<N; i++) {
        if (i>=start && i<=end) {
            ad.push_back(a[i]); 
            bd.push_back(b[i]); 
        }
    }

    if (ad.empty()) {
        cout<<"Yes\n"; 
        return 0; 
    }

    vector<int> ta=ad; 
    vector<int> tb=bd; 

    bool pos=(ta[0]==tb[tb.size()-1]); 

    ta.erase(ta.begin()); 
    tb.pop_back(); 

    if (ta==tb && pos) {
        cout<<"Yes\n"; 
        return 0; 
    }

    ta=ad; 
    tb=bd; 

    pos=(tb[0]==ta[ta.size()-1]); 

    ta.pop_back(); 
    tb.erase(tb.begin()); 

    if (ta==tb && pos) {
        cout<<"Yes\n"; 
    } else {
        cout<<"No\n"; 
    }

    return 0;
}