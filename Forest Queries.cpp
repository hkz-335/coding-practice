//
// Created by Hongkang (School) on 7/23/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;


int n,q;
int arr[1010][1010];


int main() {
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin>>c;
            arr[i][j] = arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
            if(c == '*') {
                arr[i][j]++;
            }
        }
    }
    while (q--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1]<<endl;
    }
}
