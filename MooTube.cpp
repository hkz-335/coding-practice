//
// Created by Hongkang (School) on 7/13/26.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,q;
struct edge {
    int a;
    int b;
    int relevance;
} edges[100010];
struct query {
    int pos;
    int video;
    int relevance;
} queries[100010];
bool operator < (edge a, edge b) {
    return a.relevance < b.relevance;
}
bool operator < (query a, query b) {
    return a.relevance < b.relevance;
}
int parent[100010];
int total_size[100010];

void init() {
    for (int i = 0;i<n;i++) {
        parent[i] = i;
        total_size[i] = 1;
    }
}

int deepest_parent(int x) {
    if (x==parent[x]) {
        return x;
    }
    return deepest_parent(parent[x]);
}
void merge(int a, int b) {
    int pa = deepest_parent(a);
    int pb = deepest_parent(b);
    total_size[pb]+=total_size[pa];
    parent[pa]=pb;
}

void read() {
    cin>>n>>q;
    for (int i = 0;i<n-1;i++) {
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        edges[i]={a,b,c,};
    }
    for (int i = 0;i<q;i++) {
        int a, b;
        cin>>a>>b;
        a--;
        queries[i]={i,a,b};
    }
    sort(edges,edges+n);
    sort(queries,queries+q);
}

int main() {
    read();
    init();
    int ans[100010];
    int curr = 0;
    for (int i = 0;i<q;i++) {
        query qe = queries[i];
        while (curr<n&&edges[curr].relevance>qe.relevance) {
            merge(edges[curr].a,edges[curr].b);
            curr++;
        }
        ans[qe.pos]=total_size[deepest_parent(qe.video)];
    }
    for (int i = 0;i<q;i++) {
        cout<<ans[i]<<endl;
    }
}


