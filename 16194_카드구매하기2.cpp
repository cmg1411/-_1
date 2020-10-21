/*
    최솟값은 초기화를 유의, 0으로 초기화하면 항상 작은값이 된다.

    카드팩에는 i개의 카드가 들어 있을 수 있다.
    dp[N] = N개의 카드를 구매하기 위한 지불금액의 최댓값

    dp[N] = max(dp[N-i] + p[i])
    1<=i<=N
*/


#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001];
int p[1001];

int solve(int n){
    if(n==0) return 0;
    if(dp[n]>-1) return dp[n];  //초기화값이 바뀌어서 메모조건도 바꿈
    
    for(int i=1 ; i<=n ; i++){
        dp[n] = min(solve(n-i)+p[i], dp[n]>-1 ? dp[n] : 10000000);
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        cin >> p[i];
    }

    for(int i=1 ; i<=n ; i++){
        dp[i]=-1; // 최솟값은 초기화
    }
    cout << solve(n);

    return 0;
}