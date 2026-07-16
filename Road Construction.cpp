//
// Created by Hongkang (School) on 7/12/26.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
struct dsu {
    int parent;
    int size;
    int depth;
}nodes[100010];

void init() {
    for (int i = 0;i<n;i++) {
        nodes[i]={i,1,1};
    }
}

int deepest_parent(int x) {
    if (nodes[x].parent==x) {
        return x;
    }
    return deepest_parent(nodes[x].parent);
}

int merge(int a, int b) {
    int pa = deepest_parent(a);
    int pb = deepest_parent(b);
    if (nodes[pa].depth>=nodes[pb].depth) {
        nodes[pb].parent=pa;
        nodes[pa].depth++;
        nodes[pa].size+=nodes[pb].size;
        return nodes[pa].size;
    }else {
        nodes[pa].parent=pb;
        nodes[pb].depth++;
        nodes[pb].size+=nodes[pa].size;
        return nodes[pb].size;
    }
}

int main() {
    cin>>n>>m;
    init();
    int num_components = n;
    int max_size=1;
    for (int i = 0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        a--; b--;
        // cout<<a<<" "<<b<<endl;
        // cout<<deepest_parent(a)<<" "<<deepest_parent(b)<<endl;
        if (deepest_parent(a)!=deepest_parent(b)) {
            max_size=max(max_size,merge(a,b));
            num_components--;
        }
        cout<<num_components<<" "<<max_size<<endl;
    }
}