#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans[10];
vector<vector<int> > d;

void solve(int idx, int n, int m, vector<int >& v){
    if(idx==m){
        vector<int> tmp;
        for(int i=0 ; i<m ; i++){
            tmp.push_back(ans[i]);
        }
        d.push_back(tmp);
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
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    for(auto &a : d){
        for(int i=0 ; i<m ; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}