/*

    dp[N][C] = N개의 집을 칠하는 비용의 최솟값 인데 마지막 색이 C
    색은 0,1,2 = R,G,B

    dp[N][0] = min(dp[N-1][1], dp[N-1][2]) + fee[N][0];
    N개의 집을 칠하는데 마지막을 빨간색으로 칠하는 방법의 최솟값 = 마지막 앞을 초록색으로 칠하는 방법의 최솟값과 파란색으로 칠하는 방법의 최솟값 중 더 작은거 + N번째 집의 빨간색의 비용
*/

#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001][3];
int fee[1001][3];

// 0:R, 1:G, 2:B

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<3 ; j++){
            cin >> fee[i][j];
        }
    }

    for(int i=1 ; i<=n ; i++){
        dp[i][0]=min(dp[i-1][1], dp[i-1][2]) + fee[i][0];
        dp[i][1]=min(dp[i-1][0], dp[i-1][2]) + fee[i][1];
        dp[i][2]=min(dp[i-1][0], dp[i-1][1]) + fee[i][2];
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}