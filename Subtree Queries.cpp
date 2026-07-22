//
// Created by Hongkang (School) on 7/21/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <unordered_map>
using namespace std;


int n,q, curr;
int in[200010], out[200010];
int64_t k[200010], ds[2*200010];
vector<int> adj[200010];

void update(int idx, int64_t val){
    for(int i = idx; i < 2*200010; i += i&-i)
        ds[i] += val;
}

int64_t query(int idx){
    int64_t sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += ds[i];
    return sum;
}

void dfs(int u, int p = 0){
    in[u] = ++curr;
    for(int v : adj[u])
        if(v != p)
            dfs(v, u);
    out[u] = ++curr;
}

void read() {
    cin>>n>>q;
    for (int i = 1;i<=n;i++) {
        cin>>k[i];
    }
    for (int i = 0;i<n-1;i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main(){
    read();
    curr = 0;
    dfs(1);
    for(int i = 1; i <= n; i++)
        update(out[i], k[i]);
    while (q--){
        int t,s;
        cin>>t>>s;
        if(t == 1){
            update(out[s], -k[s]);
            cin>>k[s];
            update(out[s], k[s]);
        } else if(t == 2){
            cout<<query(out[s])-query(in[s])<<endl;
        }
    }
}