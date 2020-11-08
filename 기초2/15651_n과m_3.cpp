#include<iostream>
using namespace std;

int ans[10];

void solve(int idx, int n, int m){
    if(idx==m){
        for(int i=0 ; i<m ; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    for(int i=1 ; i<=n ; i++){
        ans[idx]=i;
        solve(idx+1, n, m);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    solve(0,n,m);

    return 0;
}