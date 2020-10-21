/*
    1이 연속으로 나오면 안된다.
    dp[N][L] = dp[N-1][L-1] + dp[N-1][L+1]

*/

#include<iostream>
using namespace std;

long long dp[91][2]; // long long 형을 안써서 계속 틀림 ....

long long solve(int n, int l){ // long long 형을 안써서 계속 틀림 ....
    if(n==0 || n==1&&l==0) return 0;
    if(dp[n][l]>0) return dp[n][l];

    if(l==1)
        dp[n][1] = solve(n-1, 0);
    else if(l==0)
        dp[n][0] = solve(n-1, 0) + solve(n-1, 1);
    

    return dp[n][l];
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    dp[1][0]=0;
    dp[1][1]=1;

    cout << solve(n,1) + solve(n,0);

    return 0;
}