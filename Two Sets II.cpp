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


int mod = 1000000007;
int dp[510];

int main(){
    int n;
    cin>>n;
    int sum =(n*(n+1)/2);
    if(sum%2==1){
        cout<<0<<endl;
        return 0;
    }
    int target = sum/2;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=target-i;j>=0;j--){
            dp[j+1] += dp[j-i];
            dp[j]%=mod;
        }
    }
    cout<<(dp[target]*(mod+1)/2)%mod<<endl;
    return 0;
}