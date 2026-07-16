//
// Created by Hongkang (School) on 7/10/26.
//
#include <iostream>
#include <climits>
using namespace std;

int arr[200010];
unsigned int dp[200010][2];
int n;

void read(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        dp[i][0]=INT_MAX;
        dp[i][1]=INT_MAX;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        read();
        dp[1][0]=arr[1];
        dp[2][0]=arr[1]+arr[2];
        dp[1][1]=INT_MAX;
        dp[2][1]=min((unsigned)INT_MAX,dp[1][0]);
        for(int i = 3;i<=n;i++){
            dp[i][1]=min(dp[i-1][0],dp[i-2][0]);
            dp[i][0]=min(dp[i-1][1]+arr[i],dp[i-2][1]+arr[i-1]+arr[i]);
            // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }
        cout<<min(dp[n][0],dp[n][1])<<endl;
    }
}