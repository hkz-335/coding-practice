//
// Created by Hongkang (School) on 7/19/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <unordered_map>
using namespace std;


int64_t n;
pair<int64_t,int64_t> dp[1<<20];
int64_t x, arr[30];

int main() {
    cin>>n>>x;
    for (int64_t i = 0;i<n;i++) {
        cin>>arr[i];
    }
    dp[0]={1,0};
    for (int64_t i = 0;i<1<<n;i++) {
        dp[i]={30,0};
        for (int64_t j = 0;j<n;j++) {
            if (i&(1<<j)) {
                pair<int64_t,int64_t> possible=dp[i^(1<<j)];
                if (possible.second+arr[j]<=x) {
                    possible.second+=arr[j];
                }else {
                    possible.first++;
                    possible.second=arr[j];
                }
                dp[i]=min(possible,dp[i]);
            }
        }
    }
    cout<<dp[(1<<n)-1].first;
}