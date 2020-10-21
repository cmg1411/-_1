/*
    dp[N][L] = dp[N-1][L-1] + dp[N-1][L+1]

*/

#include<iostream>
using namespace std;

long long dp[101][10];
const long long MOD = 1000000000LL;

long long solve(int n, int l){
    if(n==0 || n==1&&l==0) return 0;
    if(dp[n][l]>0) return dp[n][l];

    if(l==0) dp[n][l] = solve(n-1, l+1)%MOD;
    else if(l==9) dp[n][l] = solve(n-1, l-1)%MOD;
    else dp[n][l] = (solve(n-1, l-1)%MOD + solve(n-1, l+1)%MOD)%MOD;

    return dp[n][l];
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=1 ; i<10 ; i++){
        dp[1][i] = 1;
    }

    long long res=0;
    for(int i=0 ; i<10 ; i++){
        res += solve(n, i)%MOD;
    }

    cout << res%MOD;

    return 0;
}