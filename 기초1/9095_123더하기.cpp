/*
    dp[N] = N을 1, 2, 3의 합으로 나타내는 방법의 수

    dp[N] = dp[N-1] + dp[N-2] + dp[N-3]
*/


#include<iostream>
#include<algorithm>
using namespace std;

int memo[12];

int solve(int n){
    if(memo[n]>0) return memo[n];

    memo[n]=solve(n-1) + solve(n-2) + solve(n-3);
    return memo[n];
}

int main(){
    int n;
    cin >> n;

    memo[1]=1;
    memo[2]=2;
    memo[3]=4;

    for(int i=0 ; i<n ; i++){
        int m;
        cin >> m;
        cout << solve(m) << '\n';
    }

    return 0;
}