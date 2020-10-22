/*
    dp[K][N] = K번사용하여 N을 만들 수 있는 방법의 수.

    dp[K][N] = dp[K-1][N-i];

    1<=K<=주어진 횟수
    1<=N<=주어진 수
    1<=i<=N
*/


#include<iostream>
#include<algorithm>
using namespace std;

long long dp[201][201];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false); 

    int n, k;
    cin >> n >> k;

    for(int i=0 ; i<=n ; i++){
        dp[1][i]=1;
    }

    for(int i=1 ; i<=k ; i++){
        for(int j=0 ; j<=n ; j++){
            for(int k=0 ; k<=j ; k++)
                dp[i][j] += dp[i-1][j-k]%1000000000;
        }
    }

    cout << dp[k][n];

    return 0;
}