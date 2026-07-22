#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <unordered_map>
using namespace std;

int n;
int dp[1000010];

int main() {
    cin>>n;
    dp[0]=1;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=6;j++) {
            if (i-j>=0) {
                dp[i]=(dp[i]+dp[i-j])%1000000007;
            }
        }
    }
    cout<<dp[n];
}