//
// Created by Hongkang (School) on 7/20/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <unordered_map>
using namespace std;

int n;
int dist[200010];
vector<int> children[200010];

void read() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        children[a].push_back(b);
        children[b].push_back(a);
    }
}


void dfs(int u,int parent) {
    for (int v: children[u]) {
        if (v != p) {
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
    }
}

int main() {
    read();
    dfs(1,0);
    int last;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[last]) {
            last = i;
        }
    }
    dist[last] = 0;
    dfs(last);
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[last]) {
            last = i;
        }
    }
    cout << dist[last] << endl;
}
