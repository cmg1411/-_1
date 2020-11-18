#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans=0;
int p[16];
int t[16];

void go(int money, int idx, int n){
    if(idx>n) return ;
    if(idx==n){
        if(money>ans) ans=money;
        return;
    }
    go(money+p[idx], idx+t[idx], n);
    go(money, idx+1, n);
}

int main(){

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        cin >> t[i] >> p[i];
    }

    //누적값, 인덱스
    go(0, 0, n);

    cout << ans;

    return 0;
}