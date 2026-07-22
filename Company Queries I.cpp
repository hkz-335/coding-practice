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

int n,q;
int parent[200010][20];

int main() {
    cin>>n>>q;
    for (int i = 2;i<=n;i++) {
        cin>>parent[i][0];
    }
    for (int j = 1;j<20;j++) {
        for (int i = 1;i<=n;i++) {
            parent[i][j]=parent[parent[i][j-1]][j-1];
        }
    }
    while (q--) {
        int x, k;
        cin>>x>>k;
        for (int i = 0;i<20;i++) {
            if (k&(1<<i)) {
                x=parent[x][i];
            }
        }
        if (x>0) {
            cout<<x;
        }else {
            cout<<-1;
        }
        cout<<endl;
    }
}