//
// Created by Hongkang (School) on 7/21/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <unordered_map>
using namespace std;

int n;
char arr[1010][1010];
int64_t dp[1010][1010];
int mod = 1000000007;

int main() {
    cin>>n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin>>arr[i][j];
        }
    }
    dp[1][1] = (arr[1][1] == '.');
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == '.') {
                if(arr[i-1][j] == '.') {
                    dp[i][j] += dp[i-1][j];
                }if(arr[i][j-1] == '.') {
                    dp[i][j] += dp[i][j-1];
                }
                dp[i][j] %= mod;
            }
        }
    }
    cout<<dp[n][n];
}