/*
    dp[N] = N을 나타낼 수 있는 제곱수의 최소 갯수.

    dp[N] = dp[N-i*i]+1;
    (1<=i, i*i<=N)
*/


#include<iostream>
#include<algorithm>
using namespace std;

int dp[100001];

int solve(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]<7) return dp[n];

    for(int i=1 ; i*i<=n ; i++){
        dp[n]=min(dp[n],solve(n-i*i)+1);
    }

    return dp[n];
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false); 

    int n;
    cin >> n;

    // for(int i=1 ; i<=n ; i++){
    //     dp[i] = i;
    //     for(int j=1 ; j*j<=i ; j++){
    //         if(dp[i]>dp[i-j*j]+1)
    //             dp[i] = dp[i-j*j]+1;
    //     } 
    // }

    for(int i=0 ; i<=n ;i++){
        dp[i]=n;
    }

    cout << solve(n);

    return 0;
}