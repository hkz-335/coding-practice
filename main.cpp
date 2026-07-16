#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int64_t n,m,k;
priority_queue<int64_t> best[200010];
vector<pair<int64_t,int64_t>> adj[200010];
priority_queue<pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> pq;

void read() {
    cin>>n>>m>>k;
    for (int64_t i = 0;i<m;i++) {
        int64_t a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
}

int main() {
    read();
    best[1].push(0);
    pq.push({0,1});
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        if (curr.first>best[curr.second].top()) {
            continue;
        }
        for (auto e : adj[curr.second]) {
            int64_t d = curr.first+e.second;
            if (best[e.first].size()<k) {
                best[e.first].push(d);
                pq.push({d,e.first});
            }else if (d<best[e.first].top()) {
                best[e.first].pop();
                best[e.first].push(d);
                pq.push({d,e.first});
            }
        }
    }
    vector<int64_t> ans;
    while (!best[n].empty()) {
        ans.push_back(best[n].top());
        best[n].pop();
    }
    reverse(ans.begin(),ans.end());
    for (auto e : ans) {
        cout<<e<<" ";
    }
}