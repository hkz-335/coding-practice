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

int n, q;
int curr_count = 0;
vector<int> adj[200010];
int parent[200010][20];
int in[200010], out[200010];

void dfs(int u, int par) {
    in[u] = ++curr_count;
    parent[u][0] = par;
    for (int i = 1; i < 20; i++) {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }
    for (int v: adj[u]) {
        if (v != par) {
            dfs(v, u);
        }
    }
    out[u] = ++curr_count;
}

bool ancestor(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
    if (ancestor(u, v)) {
        return u;
    }
    if (ancestor(v, u)) {
        return v;
    }
    for (int i = 19; i >= 0; i--) {
        if (!ancestor(parent[u][i], v)) {
            u = parent[u][i];
        }
    }
    return parent[u][0];
}

void read() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main() {
    read();
    dfs(1, 1);
    while (q--) {
        int a, b;
        cin>>a>>b;
        cout << lca(a, b) << endl;
    }
}
