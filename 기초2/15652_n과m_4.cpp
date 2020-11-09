// 선택으로 풀기
/*
    이번 문제는 선택으로 풀 때, 같은 수를 여러번 선택할 수 있다.
    선택했을 때, 몇번 선택했는가를 고려해서 풀어야 한다.
*/

#include<iostream>
using namespace std;

int ans[10];

void solve(int idx, int selected, int n, int m){
    if(selected==m){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<ans[i] ; j++)
                cout << i+1 << ' ';
        }
        cout << '\n';
        return ;
    }
    if(idx>=n) return ;
    for(int i=m-selected ; 1<=i ; i--){
        ans[idx]=i;
        solve(idx+1, selected+i, n, m);
    }
    ans[idx]=0;
    solve(idx+1, selected, n, m);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    solve(0,0,n,m);

    return 0;
}