#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans[10];
int ch[10001]={false,};

void solve(int idx, int n, int m, vector<int >& v){
    if(idx==m){
        for(int i=0 ; i<m ; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    for(int i=0 ; i<n ; i++){
        if(!ch[v[i]]){
            ch[v[i]]=true;
            ans[idx]=v[i];
            solve(idx+1, n, m, v);
            ch[v[i]]=false;
        }
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