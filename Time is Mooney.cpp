//
// Created by Hongkang (School) on 7/11/26.
//

#include <iostream>
#include <vector>
using namespace std;

int64_t n, m, c;
int64_t arr[1010];
vector<int64_t> adj[1010];
int64_t dp[1010][1010];

void read() {
    cin>>n>>m>>c;
    for (int64_t i = 0;i<n;i++) {
        cin>>arr[i];
    }
    for (int64_t i = 0;i<m;i++) {
        int64_t a, b;
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
    }
}


int main() {
    // freopen("time.in", "r", stdin);
    // freopen("time.out", "w", stdout);
    read();
    for (int64_t i = 0;i<=1000;i++) {
        for (int64_t j = 0;j<=1000;j++) {
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    for (int64_t t = 1;t<=1000;t++) {
        for (int64_t i = 0;i<n;i++) {
            for (auto e : adj[i]) {
                dp[e][t]=max(dp[e][t],dp[i][t-1]+arr[e]);
                cout<<"i, e, t, dp[e][t]: "<<i<<" "<<e<<" "<<t<<" "<<dp[e][t]<<endl;
            }
        }
    }
    int64_t ans = 0;
    for (int64_t i = 0;i<=1000;i++) {
        ans = max(ans,dp[0][i]-i*i);
    }
    cout<<ans;
}