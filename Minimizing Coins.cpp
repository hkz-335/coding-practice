//
// Created by Hongkang (School) on 7/16/26.
//

#include <iostream>
using namespace std;

int n,x;
int val[110];
int dp[2000010];

void read() {
    cin>>n>>x;
    for (int i =0;i<n;i++) {
        cin>>val[i];
    }
    for (auto &e : dp) {
        e = 1234567;
    }
}

int main() {
    read();
    dp[0] = 0;
    for (int i =0;i<=x;i++) {
        for (int j = 0;j<n;j++) {
            dp[i+val[j]]=min(dp[i+val[j]],dp[i]+1);;
        }
    }
    if (dp[x]==1234567) {
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<dp[x];
}
