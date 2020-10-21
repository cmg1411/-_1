/*
    dp[N] = 연산 세개를 이용하여 N을 만들 때, 연산을 사용하는 횟수의 최솟값.

    dp[N] = min(dp[N/3], dp[N/2], dp[N+1])+1;
*/


#include<iostream>
#include<algorithm>
using namespace std;

int memo[1000001];

int solve(int n){
    if(n==1) return 0;
    if(memo[n]>0) return memo[n];
    memo[n] = solve(n-1)+1;
    if(n%2==0){
        int tmp = solve(n/2)+1;
        if(tmp < memo[n]) memo[n] = tmp;
    }
    if(n%3==0){
        int tmp = solve(n/3)+1;
        if(tmp < memo[n]) memo[n] = tmp;
    }

    return memo[n];
}

int main(){

    int n;
    cin >> n;

    cout << solve(n);

    return 0;
}