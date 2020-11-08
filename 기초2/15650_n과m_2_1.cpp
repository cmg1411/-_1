/*
    같은 문제를 이번에는 선택을 기준으로 푼다.

    각 수에서 선택함, 선택안함의 두가지가 가능하다.
*/

#include<iostream>
using namespace std;

int ans[10];

void solve(int idx, int selected, int n, int m){
    if(selected==m){
        for(int i=0 ; i<n ; i++){
            if(ans[i]!=0)
                cout << ans[i] << ' ';
        }
        cout << '\n';
        return ;
    }

    if(idx>n) return ;

    ans[selected]=idx;
    solve(idx+1, selected+1, n, m);
    ans[selected]=0;
    solve(idx+1, selected, n, m);
    return ;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    solve(1, 0, n, m);

    return 0;
}