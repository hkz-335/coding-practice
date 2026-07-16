//
// Created by Hongkang (School) on 7/14/26.
//
#include <iostream>
#include <algorithm>
using namespace std;

int64_t n,m;
struct road{
    int64_t a;
    int64_t b;
    int64_t price;
};

bool comp(road a,road b){
    return a.price<b.price;
}

int64_t parent[100000];
int64_t ranks[100000];
road roads[200000];
void read(){
    cin>>n>>m;
    for(int64_t i = 0;i<m;i++){
        cin>>roads[i].a>>roads[i].b>>roads[i].price;
        roads[i].a--;
        roads[i].b--;
    }
    for(int i = 0;i<n;i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int64_t deepest_parent(int64_t node){
    if(parent[node] == node){
        return node;
    }else{
        return deepest_parent(parent[node]);
    }
}

void merge(int64_t node1, int64_t node2){
    int64_t parent1 = deepest_parent(node1);
    int64_t parent2 = deepest_parent(node2);
    if(ranks[parent1] > ranks[parent2]){
        parent[parent2] = parent1;
    }else if(ranks[parent1] < ranks[parent2]){
        parent[parent1] = parent2;
    }else{
        parent[parent1] = parent2;
        ranks[parent2]++;
    }
}

bool connected(int64_t node1, int64_t node2){
    int64_t parent1 = deepest_parent(node1);
    int64_t parent2 = deepest_parent(node2);
    return parent1 == parent2;
}

bool all_connected(){
    int64_t p = deepest_parent(0);
    for(int i = 1;i<n;i++){
        if(deepest_parent(i)!=p){
            return false;
        }
    }
    return true;
}

int64_t calc(){
    int64_t ans = 0;
    sort(roads,roads+m,comp);
    for(road r : roads){
        if(!connected(r.a,r.b)){
            merge(r.a,r.b);
            ans+=r.price;
        }
    }
    return ans;
}

int main(){
    read();
    int64_t a = calc();
    if(!all_connected()){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<a;
    }
}
