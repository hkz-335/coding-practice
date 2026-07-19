//
// Created by Hongkang (School) on 7/18/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>
using namespace std;

int64_t n,m,q;
int64_t dist[510][510];

void read() {
    cin>>n>>m>>q;
    for (int64_t i = 0;i<n;i++) {
        for (int64_t j = 0;j<n;j++) {
            dist[i][j]=INT64_MAX;
        }
    }
    for (int64_t i = 0;i<m;i++) {
        int64_t a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        dist[a][b]=dist[b][a]=c;
    }
    for (int64_t i = 0;i<n;i++) {
        dist[i][i]=0;
    }
}

int main() {
    read();
    for (int64_t i = 0;i<n;i++) {
        for (int64_t j = 0;j<n;j++) {
            for (int64_t k = 0;k<n;k++) {
                if (dist[i][k]<INT64_MAX&&dist[k][j]<INT64_MAX) {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    for (int64_t i = 0;i<q;i++) {
        int64_t a, b;
        cin>>a>>b;
        a--; b--;
        if (a==b) {
            cout<<0;
        }else if (dist[a][b]==INT64_MAX) {
            cout<<-1<<endl;
        }else {
            cout<<dist[a][b]<<endl;
        }
    }
}

