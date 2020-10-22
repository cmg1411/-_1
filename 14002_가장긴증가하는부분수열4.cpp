#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001];
int v[1001];
int ans[1001];

void go(int p){
    if(p==-1) return ;

    go(ans[p]);
    cout << v[p] << ' ';
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        cin >> v[i];
    }

    for(int i=0 ; i<n ; i++){
        dp[i]=1;
        ans[i]=-1;
        for(int j=0 ; j<i ; j++){
            if(v[j]<v[i]&&dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
                ans[i] = j;
            }
        }
    }

    int res= dp[0];
    int p=0;
    for(int i=0 ; i<n ; i++){
        if(res < dp[i]){
            res = dp[i];
            p = i;
        }
    }

    cout << res << '\n';
    go(p);

    return 0;
}