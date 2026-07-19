//
// Created by Hongkang (School) on 7/18/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n,m;
vector<int>adj[100005];
bool vis[100005];
vector<int>cyc;

bool dfs(int s, int p){
    vis[s]=1;
    for (auto i: adj[s]) {
        cyc.push_back(i);
        if (!vis[i]) {
            if (dfs(i,s)) {
                return 1;
            }
        }
        else if (i!=p) {
            return 1;
        }
        cyc.pop_back();
    }
    return 0;
}

void read() {
    cin>>n>>m;
    for (int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
}
void solve(){
    for (int i = 1;i<n+1;i++){
        cyc.push_back(i);
        if (!vis[i] && dfs(i,0)){
            vector<int>ans={*cyc.rbegin()};
            for (auto j=cyc.rbegin()+1; j!=cyc.rend();j++) {
                ans.push_back(*j);
                if (*j==*cyc.rbegin()) {
                    break;
                }
            }
            cout<<ans.size()<<endl;
            for (auto e: ans) {
                cout<<e<<" ";
            }
            return;
        }
        cyc.pop_back();
    }
    cout<<"IMPOSSIBLE";
}

int main(){
    read();
    solve();
}