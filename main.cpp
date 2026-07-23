#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;


int64_t n, m, p[510];
int64_t cap[510][510];
vector<int64_t> adj[510];

int64_t bfs(int64_t s = 1, int64_t t = n){
    fill(p+1, p+n+1, -1);
    p[s] = -2;

    queue<pair<int64_t,int64_t>> queue;
    queue.push({s, INT_MAX});
    while(!queue.empty()){
        int64_t u = queue.front().first;
        int64_t f = queue.front().second;
        queue.pop();
        for(int64_t v : adj[u]){
            if(p[v] == -1 && cap[u][v]){
                p[v] = u;
                int64_t aug = min(f, cap[u][v]);
                if(v == t)  return aug;
                queue.push({v, aug});
            }
        }
    }
    return 0;
}

int64_t maxflow(int64_t s = 1, int64_t t = n){
    int64_t flow = 0, aug = 0;
    while(aug = bfs()){
        flow += aug;
        int64_t u = t;
        while(u != s){
            int64_t v = p[u];
            cap[v][u] -= aug;
            cap[u][v] += aug;
            u = v;
        }
    }
    return flow;
}

void read() {
    cin>>n>>m;
    for (int64_t i = 0;i<m;i++) {
        int64_t a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b]+=c;
    }
}

int main(){
    read();
    cout<<maxflow();
}