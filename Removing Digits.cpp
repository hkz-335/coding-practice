//
// Created by Hongkang (School) on 7/17/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[1000010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x = i, max_digit = 0;
        while (x > 0) {
            max_digit = max(max_digit, x % 10);
            x /= 10;
        }
        dp[i] = dp[i - max_digit] + 1;
    }
    cout << dp[n] << endl;
    return 0;
}