#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin>>N>>Q; 

    vector<int> cards(N); 
    for (int i=0; i<N; i++) cards[i]=i+1; 

    while (Q--) {
        int X; cin>>X; 

        vector<int> temp=cards; 

        for (int i=0; i<X; i++) {
            temp[X-i-1]=-1*cards[i]; 
        }

        cards=temp; 
    }

    for (int i=0; i<N; i++) {
        cout<<cards[i]<<'\n'; 
    }

    return 0;
}