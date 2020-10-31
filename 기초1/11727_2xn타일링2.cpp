/*
    dp[N] = 2xn 직사각형을 1x2, 2x1, 2x2로 채우는 방법의 수
    
    기존의 1x2 가로로 두개가 2x2와 같음.

    dp[N] = dp[N-1] + 2*dp[N-2]
*/


#include<iostream>
#include<algorithm>
using namespace std;

int memo[1001];

int solve(int n){
    if(memo[n]>0) return memo[n];

    memo[n]=(solve(n-1)%10007 + 2*solve(n-2)%10007)%10007;
    return memo[n];
}

int main(){
    int n;
    cin >> n;
    memo[1]=1;
    memo[2]=3;
    cout << solve(n);
    return 0;
}