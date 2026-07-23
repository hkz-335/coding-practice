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

int subordinates[200010];
vector<int> children[200010];
int n;

void read() {
    cin>>n;
    for (int i = 2;i<=n;i++) {
        int x;
        cin>>x;
        children[x].push_back(i);
    }
}

void dfs(int node) {
    subordinates[node]=1;
    for (auto e : children[node]) {
        dfs(e);
        subordinates[node]+=subordinates[e];
    }
}

int main() {
    read();
    dfs(1);
    for (int i = 1;i<=n;i++) {
        cout<<subordinates[i]-1<<" ";
    }
}