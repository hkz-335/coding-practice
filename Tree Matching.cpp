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


int n, a, b, count_pairs;
bool used[200010];
vector<int> children[200010];

void dfs(int u, int parent){
    for(int v : children[u])
        if(v != parent)
            dfs(v, u);

    if(!used[parent] && !used[u] && parent != 0){
        used[parent] = used[u] = true;
        count_pairs++;
    }
}

void read() {
    cin>>n;
    for (int i = 0;i<n-1;i++) {
        cin>>a>>b;
        children[a].push_back(b);
        children[b].push_back(a);
    }
}

int main() {
    read();
    dfs(1,0);
    printf("%d\n", count_pairs);
}