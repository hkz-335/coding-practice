//
// Created by Hongkang (School) on 7/23/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;

int64_t n,q;
int64_t ds[200010];

void update(int64_t idx, int64_t val){
    for(int64_t i = idx; i <= n; i += -i&i)
        ds[i] += val;
}

int64_t query(int64_t idx){
    int64_t sum = 0;
    for(int64_t i = idx; i > 0; i -= -i&i) {
        sum += ds[i];
    }
    return sum;
}

void read() {
    cin>>n>>q;
    for (int64_t i = 1;i<=n;i++) {
        int64_t x;
        cin>>x;
        update(i, x);
        update(i+1,-x);
    }
}

int main(){
    read();
    while (q--){
        int64_t t;
        cin>>t;
        if(t == 1){
            int64_t a, b, x;
            cin>>a>>b>>x;
            update(b+1, -x);
            update(a, x);
        } else if(t == 2){
            int64_t k;
            cin>>k;
            cout<<query(k)<<endl;
        }
    }
}