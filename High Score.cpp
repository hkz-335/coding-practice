//
// Created by Hongkang (School) on 7/22/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <unordered_map>
using namespace std;


using namespace std;


struct Edge {
    int64_t a, b, c;
} edges[5010];

int64_t n, m;
int64_t dp[2510];
bool visited[2510], visited_reverse[2510];
vector<int64_t> adj[2510], adj_reverse[2510];

void dfs(int64_t u){
    visited[u] = true;
    for(int64_t v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}

void dfs_reverse(int64_t u){
    visited_reverse[u] = true;
    for(int64_t v : adj_reverse[u]) {
        if(!visited_reverse[v]) {
            dfs_reverse(v);
        }
    }
}
void read() {
    cin>>n>>m;
    for (int64_t i = 0;i<m;i++) {
        int64_t a, b,c;
        cin>>a>>b>>c;
        edges[i]={a,b,-c};
        adj[a].push_back(b);
        adj_reverse[b].push_back(a);
    }
}

int main(){
    read();
    dfs(1);
    dfs_reverse(n);
    fill(dp+2, dp+n+1, INT_MAX);
    bool improvement = true;
    for(int64_t iter = 0; iter < n && improvement; iter++){
        improvement = false;
        for(int64_t i = 0; i < m; i++){
            int64_t u = edges[i].a;
            int64_t v = edges[i].b;
            int64_t w = edges[i].c;

            if(dp[v] > dp[u]+w){
                dp[v] = dp[u]+w;
                improvement = true;

                if(iter == n-1 && visited[v] && visited_reverse[v]){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    cout<<-dp[n];
}