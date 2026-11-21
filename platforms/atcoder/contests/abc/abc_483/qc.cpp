#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 

    vector<int> cnt(N);
    vector<vector<int>> sec(N); 

    for (int i=0; i<M; i++) {
        int f, s; cin>>f>>s; 
        f--; s--; 
        cnt[f]++; 
        sec[f].push_back(s); 
    }

    set<pair<int, int>> votes; 

    for (int i=0; i<N; i++) {
        votes.insert({-cnt[i], i}); 
    }

    for (int i=0; i<N; i++) {
        votes.erase({-cnt[i], i}); 

        for (int s : sec[i]) {
            votes.erase({-cnt[s], s}); 
            cnt[s]++; 
            votes.insert({-cnt[s], s}); 
        }

        cout<<votes.begin()->second+1<<'\n'; 

        for (int s : sec[i]) {
            votes.erase({-cnt[s], s});
            cnt[s]--; 
            votes.insert({-cnt[s], s}); 
        }

        votes.insert({-cnt[i], i}); 
    }

    return 0;
}