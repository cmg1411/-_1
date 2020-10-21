/*

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
    if(dp[n]>0) return dp[n];
    
    for(int i=1 ; i<=n ; i++){
        dp[n] = max(solve(n-i)+p[i], dp[n]);
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        cin >> p[i];
    }

    dp[1] = p[1];
    cout << solve(n);

    return 0;
}