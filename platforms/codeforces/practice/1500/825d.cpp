#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t; cin>>s>>t;

    vector<long long> have(26, 0), need(26, 0);
    long long q=0;

    for (char c : s) {
        if (c=='?')
            q++;
        else
            have[c-'a']++;
    }

    for (char c:t) need[c-'a']++;

    auto possible=[&](long long k) {
        long long requiredQ=0;

        for (int c=0; c<26; c++) {
            requiredQ+=max(0LL, k*need[c]-have[c]);
            if (requiredQ>q) return false;
        }

        return true;
    };

    long long lo=0;
    long long hi=s.size()/t.size();

    while (lo<hi) {
        long long mid=(lo+hi+1)/2;

        if (possible(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    long long k=lo;

    vector<long long> add(26, 0);

    for (int c=0; c<26; c++) {
        add[c]=max(0LL, k*need[c]-have[c]);
    }

    int cur=0;

    for (char &c : s) {
        if (c!='?') continue;

        while (cur<26 && add[cur]==0) cur++;

        if (cur<26) {
            c='a'+cur;
            add[cur]--;
        } else {
            c='a';
        }
    }

    cout<<s<<'\n';
}