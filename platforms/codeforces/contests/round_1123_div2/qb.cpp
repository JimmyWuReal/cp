#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if ((a.second>0)!=(b.second>0)) return a.second>0;
    return a.first>b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 

        vector<pair<int, int>> times;
        map<int, int> temp;

        for (int i=0; i<N; i++) { 
            int x; cin>>x; 
            temp[x]++;
        }

        for (auto [key, value] : temp) times.push_back({key, value});
        sort(times.begin(), times.end(), comp);

        while (!times.empty() && times[0].second>0) {
            for (int i=0; i<(int)times.size(); i++) {
                if (times[i].second<=0) break;
                cout<<times[i].first<<' ';
                times[i].second--;
            }

            sort(times.begin(), times.end(), comp);
        }

        cout<<'\n';
    }

    return 0;
}