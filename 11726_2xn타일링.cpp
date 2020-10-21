/*
    dp[N] = 2xn 직사각형을 1x2, 2x1로 채우는 방법의 수
    
    세로로 한개 들어가는것 + 가로로 두개 들어가는 것
    dp[N] = dp[N-1] + dp[N-2]
*/


#include<iostream>
#include<algorithm>
using namespace std;

int memo[1001];

int solve(int n){
    if(memo[n]>0) return memo[n];

    memo[n] = (solve(n-1) + solve(n-2))%10007;

    return memo[n];
}

int main(){

    int n;
    cin >> n;

    memo[1]=1;
    memo[2]=2;
    cout << solve(n);

    return 0;
}