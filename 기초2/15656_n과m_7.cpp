#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans[10];

void solve(int idx, int n, int m, vector<int >& v){
    if(idx==m){
        for(int i=0 ; i<m ; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return ;
    }

    for(int i=0 ; i<n ; i++){
            ans[idx]=v[i];
            solve(idx+1, n, m, v);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    solve(0,n,m,v);

    return 0;
}