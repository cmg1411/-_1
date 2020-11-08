/*
    브루트포스에서 재귀는 1.순서 2.선택의 방법으로 풀 수 있다.

    이번 문제는 순서를 기준으로 푼다.

    뒤에는 큰 수만 나와야 하므로 idx : 숫자를 넣는 번째
                          start : 현재보다 큰 가장 작은 수 
    로 두고 푼다.
*/

#include<iostream>
using namespace std;

int ans[9];

void solve(int idx, int start, int n, int m){
    if(idx==m){
        for(int i=0 ; i<m ; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return ;
    }

    for(int i=start ; i<=n ; i++){
        ans[idx]=i;
        solve(idx+1, i+1, n, m);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    solve(0, 1, n, m);

    return 0;
}