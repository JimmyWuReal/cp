#include <bits/stdc++.h>
using namespace std;

int strtoint(string s) {
    int n=s.size(); 
    bool neg=false; 
    int x=0; 
    for (int i=0; i<n; i++) {
        if (i==0 && s[i]=='-' && n>1) {
            neg=true; 
            continue;
        }

        if (!isdigit(s[i])) {
            return 0; 
        } else {
            x=x*10+(s[i]-'0'); 
        }
    }

    return neg ? -x : x; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    bool ended=false; 

    int money=0; 
    int d=0; 

    while (cin>>s) {
        if (s=="@") ended=true; 

        if (ended) continue;

        if (s=="*") d=5; 

        int x=strtoint(s); 

        if (d>=1) {
            d--; 
            money+=x*2; 
        } else {
            money+=x; 
        }
        
        money=max(money, 0); 
    }

    cout<<money<<'\n'; 

    return 0;
}