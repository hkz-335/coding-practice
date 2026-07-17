//
// Created by Hongkang (School) on 7/17/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int64_t dp[1000010][2];
int64_t MOD=1000000007;

int main() {
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int64_t i = 1;i<1000000;i++) {
        dp[i][1]=(2*dp[i-1][1]%MOD+dp[i-1][0]%MOD)%MOD;
        dp[i][0]=(4*dp[i-1][0]%MOD+dp[i-1][1]%MOD)%MOD;
    }
    int64_t t;
    cin>>t;
    while (t--) {
        int64_t n;
        cin>>n;
        cout<<(dp[n-1][1]+dp[n-1][0]%MOD)%MOD<<endl;
    }
}