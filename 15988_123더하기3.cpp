/*
    dp[N] = N을 1,2,3의 합으로 나타낼 수 있는 경우의 수
    dp[N] = dp[N-1] + dp[N-2] + DP[n-3]
*/

#include<iostream>
using namespace std;

long long dp[1000001];
const long long MOD = 1000000009LL;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;

    for(int j=4 ; j<=1000000 ; j++){
        dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        dp[j] %= MOD;
    }

    //dp를 여러개 구하는 것은 그냥 범위대로 다 dp값을 구해온 다음 출력하는 것이 빠르다.
    //(입력마다 dp를 돌리는 것 보다.)
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }


    return 0;
}