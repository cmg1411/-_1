/*
    n x 2의 우리에서 사자를 겹치지 않게 넣는다

    dp[N][L] = N개 열의 우리에 사자를 배치하는 경우의 수

    1. L=0 사자 한마리도 안넣는 경우   ->    이후에 하나도 안넣는 경우까지 '세가지' 가능
    2. L=1 사자 왼쪽에만 넣는 경우     ->    넣지 않는 경우와 오른쪽 두가지
    3. L=2 사자 오른쪽에만 넣는 경우   ->    넣지 않는 경우와 왼쪽 두가지
*/

#include<iostream>
using namespace std;

int dp[100001][3];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<3 ; i++){
        dp[1][i]=1;
    }

    for(int i=2 ; i<=n ; i++){
        dp[i][0]=dp[i-1][1]+dp[i-1][2]+ dp[i-1][0];
        dp[i][0] %= 9901;
        dp[i][1]=dp[i-1][0]+dp[i-1][2];
        dp[i][1] %= 9901;
        dp[i][2]=dp[i-1][0]+dp[i-1][1];
        dp[i][2] %= 9901;
    }

    cout << (dp[n][0] + dp[n][1] + dp[n][2])%9901;

    return 0;
}