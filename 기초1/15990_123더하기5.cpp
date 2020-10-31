/*
    dp[N] = N을 1, 2, 3의 합으로 나타내는 방법의 수.
    근데 연속해서 쓰면 안됨.

    dp[N][L] = N을 123의 합으로 나타내는데 마지막을 L을 씀

    
    dp[N][3] = dp[N-1][1] + dp[N-2][2];
    dp[N][2] = dp[N-1][1] + dp[N-3][3];
    dp[N][1] = dp[N-2][2] + dp[N-3][3];
    0은 1만되고 9는 8만 된다.//
*/

#include<iostream>
using namespace std;

long long dp[100001][4];
const long long MOD = 1000000009LL;

long long solve(int n, int l){
    if(n<=0) return 0;
    if(n==l) return 1; // dp[1][1], dp[2][2], dp[3][3]은 1
    if(dp[n][l]>0) return dp[n][l];

    if(l==1){
        dp[n][1] = solve(n-1, 2) + solve(n-1, 3);
        dp[n][1] %= MOD;
    }else if(l==2){
        dp[n][2] = solve(n-2, 1) + solve(n-2, 3);
        dp[n][2] %= MOD;
    }else if(l==3){
        dp[n][3] = solve(n-3, 1) + solve(n-3, 2);
        dp[n][3] %= MOD;
    }

    return dp[n][l];
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=1 ; i<3 ; i++){
        long long h = solve(100000,i);
    }

    for(int i=0 ; i<n ; i++){
        int m;
        cin >> m;
        cout << (solve(m, 1)+solve(m,2)+solve(m,3))%MOD << '\n';
    }

    return 0;
}