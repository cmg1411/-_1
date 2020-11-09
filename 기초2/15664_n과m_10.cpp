#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int ans[10];
int num[10];
vector<vector<int> > v;

void solve(int idx, int start, int n, int m){
    if(idx==m){
        vector<int> tmp;
        for(int i=0 ; i<m ; i++){
            tmp.push_back(num[ans[i]]);
        }
        v.push_back(tmp);
        return;
    }

    for(int i=start ; i<n ; i++){
        ans[idx]=i;
        solve(idx+1, i+1, n, m);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=0 ; i<n ; i++){
        cin >> num[i];
    }

    sort(num, num+n);
    solve(0,0,n,m);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto &a : v){
        for(int i=0 ; i<m ; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}