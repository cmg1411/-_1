#include<iostream>
#include<algorithm>
using namespace std;

int ans[10];
int num[10];

void solve(int idx, int start, int n, int m){
    if(idx==m){
        for(int i=0 ; i<m ; i++){
            cout << num[ans[i]] << ' ';
        }
        cout << '\n';
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

    return 0;
}