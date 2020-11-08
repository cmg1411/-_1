/*           B
    사용한 것을 체크
*/

#include<iostream>
using namespace std;

int ans[9];
bool ch[9]={false,};

void solve(int index, int n, int m){
    if(index==m){
        for(int i=0 ; i<m ; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    for(int i=1 ; i<=n ; i++){
        if(ch[i]) continue;
        ch[i]=true;
        ans[index] = i;
        solve(index+1, n, m);
        ch[i]=false;
    }
    return ;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    solve(0, n, m);

    return 0;
}