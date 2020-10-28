/*
    2n의 표에서 세로로 한줄씩 n줄이 있는데,
    한줄에서 0.하나도 안고르는 경우, 1.위에것 고르는 경우, 1.밑에것 고르는 경우 세가지가 있다.

    dp[N][m] = 2N개의 스티커에서 남길 수 있는 최대의 비용, 마지막에 고른 경우가 m

    dp[N][0] = max(dp[N-1][1], dp[N-1][2]) + fee[N][0];
    dp[N][1] = max(dp[N-1][0], dp[N-1][2]) + fee[N][1];
    dp[N][2] = max(dp[N-1][0], dp[N-1][1]) + fee[N][2];
*/

#include<iostream>
#include<algorithm>
using namespace std;

int dp[100001][3];
int fee[100001][3];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int z=0 ; z<t ; z++){
        int n;
        cin >> n;
        for(int i=1 ; i<=2 ; i++){
            for(int j=1 ; j<=n ; j++)
                cin >> fee[j][i];
        }


        for(int i=1 ; i<=n ; i++){
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + fee[i][1];
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + fee[i][2];  
        }

        cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
    }



    return 0;
}