//
// Created by Hongkang (School) on 7/13/26.
//
#include <iostream>
#include <vector>
using namespace std;



bool dp[110][100010];

int main() {
    int n;
    cin >> n;
    vector<int> coins_values(n);
    for (int i = 0; i < n; i++) {
        cin >> coins_values[i];
    }
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int current_sum = 0; current_sum <= 100000; current_sum++) {
            dp[i][current_sum] = dp[i - 1][current_sum];
            int prev_sum = current_sum - coins_values[i - 1];
            if (prev_sum >= 0 && dp[i - 1][prev_sum]) { dp[i][current_sum] = true; }
        }
    }
    vector<int> possible;
    for (int sum = 1; sum <= 100000; sum++) {
        if (dp[n][sum]) {
            possible.push_back(sum);
        }
    }
    cout << possible.size() << endl;
    for (int sum : possible) {
        cout << sum << " ";
    }
    cout << endl;
}