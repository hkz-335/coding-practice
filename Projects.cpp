//
// Created by Hongkang (School) on 7/19/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>
#include <set>
#include <unordered_map>
using namespace std;

int64_t n;
struct project {
    int64_t start;
    int64_t end;
    int64_t reward;
} projects[200010];
set<int64_t> coordinates;

void read() {
    cin>>n;
    for (int64_t i = 0;i<n;i++) {
        int64_t a, b, c;
        cin>>a>>b>>c;
        projects[i]={a,b+1,c};
        coordinates.insert(a);
        coordinates.insert(b+1);
    }
}

int main() {
    read();
    int64_t x = 0;
    unordered_map<int64_t,int64_t> comp;
    for (auto e : coordinates) {
        comp[e]=x++;
    }
    int64_t dp[x+1];
    for (int64_t i = 0;i<=x;i++) {
        dp[i] = 0;
    }
    vector<pair<int64_t,int64_t>>proj[x+1];
    for (int64_t i = 0;i<n;i++) {
        proj[comp[projects[i].end]].push_back({comp[projects[i].start],projects[i].reward});
    }
    for (int64_t i = 0;i<x;i++) {
        if (i>0) {
            dp[i]=dp[i-1];
        }
        for (auto [start,reward]:proj[i]) {
            dp[i]=max(dp[i],dp[start]+reward);
        }
    }
    cout<<dp[x-1];
}
