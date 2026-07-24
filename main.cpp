#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;


int n,q;
char arr[1010][1010];
int prefix[1010][1010];

void update(int x, int y, int val){
    for(int i = x; i <= n; i += -i&i) {
        for(int j = y; j <= n; j += -j&j) {
            prefix[i][j] += val;
        }
    }
}

int query(int x, int y){
    int sum = 0;
    for(int i = x; i > 0; i -= -i&i)
        for(int j = y; j > 0; j -= -j&j)
            sum += prefix[i][j];
    return sum;
}

int main(){
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        string s;
        cin>>s;
        for(int j = 1; j <= n; j++){
            arr[i][j]=s[j-1];
            if(arr[i][j] == '*') {
                update(i, j, 1);
            }
        }
    }
    while (q--){
        int t;
        cin>>t;
        if(t == 1){
            int x, y;
            cin>>x>>y;
            if(arr[x][y] == '*'){
                update(x, y, -1);
                arr[x][y] = '.';
            } else if(arr[x][y] == '.'){
                update(x, y, 1);
                arr[x][y] = '*';
            }
        } else if(t == 2){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<query(x2, y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1)<<endl;
        }
    }
}