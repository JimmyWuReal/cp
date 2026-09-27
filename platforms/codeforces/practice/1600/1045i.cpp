#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 

    unordered_map<int, long long> freq;
    long long res=0;

    for (int i=0; i<N; i++) {
        string s; cin>>s; 
        int mask=0; 

        for (char ch : s) mask^=(1<<(ch-'a'));

        res+=freq[mask];

        for (int b=0; b<26; b++) res+=freq[mask^(1<<b)];

        freq[mask]++;
    }

    cout << res << '\n';
}