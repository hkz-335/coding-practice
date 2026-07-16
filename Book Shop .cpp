//
// Created by Hongkang (School) on 7/13/26.
//
#include <iostream>

using namespace std;

int n, x;
int val[1010], price[1010];
int dp[1010][100010];

void read() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
}

int main() {
    read();
    for(int i = 0;i<=n+1;i++){
        for(int j = 0;j<=x+1;j++){
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= price[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + val[i - 1]);
            }
        }
    }
    cout << dp[n][x] << endl;
