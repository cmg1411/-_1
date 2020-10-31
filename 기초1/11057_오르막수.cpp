/*
    dp[N][L] = n개자리 오르막수를 만드는 방법의 수, 마지막 숫자가 L

    dp[N][L] = dp[N-1][i];
    i의 범위는 0<=i<=L인 정수
    L의 범위는 0~9
*/

#include<iostream>
using namespace std;

int dp[1001][10];
const int MOD = 10007;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<=9 ; i++){
        dp[1][i]=1;
    }

    for(int i=2 ; i<=n ; i++){
        for(int j=0 ; j<=9 ; j++){
            for(int z=0 ; z<=j ; z++){
                dp[i][j] += dp[i-1][z]%MOD;
            }
        }
    }

    int ans=0;
    for(int i=0 ; i<=9 ; i++){
        ans += dp[n][i]%MOD;
    }

    cout << ans%MOD;

    return 0;
}