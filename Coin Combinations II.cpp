//
// Created by Hongkang (School) on 7/17/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,x;
int arr[110];
int dp[1000010];


void read() {
    cin>>n>>x;
    for (int i = 0;i<n;i++) {
        cin>>arr[i];
    }
}

int main() {
    read();
    dp[0] = 1;
    for (int i = 1;i<=x;i++) {
        int total = 0;
        for (int j = 0;j<n;j++) {
            if (arr[j]==i) {
                total+=dp[i-arr[j]];
                if (total>=1000000007) {
                    total-=1000000007;
                }
            }
        }
        dp[i]=total;
    }
    cout<<dp[x];
}