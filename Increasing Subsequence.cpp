//
// Created by Hongkang (School) on 7/16/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
int arr[200010];
vector<int> tails;

void read() {
    cin>>n;
    for (int i = 0;i<n;i++) {
        cin>>arr[i];
    }
}

int main() {
    read();
    for (int i = 0;i<n;i++) {
        auto it = lower_bound(tails.begin(),tails.end(),arr[i]);
        if (it==tails.end()) {
            tails.push_back(arr[i]);
        }else {
            *it=arr[i];
        }
    }
    cout<<tails.size()<<endl;
}