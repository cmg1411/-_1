/*
    기존 rgb거리 문제에서 원형으로 이웃인 경우의 문제이다.
    직선으로 하는 방법을 구한 다음 원형으로 적절히 바꿔보자.

    처음과 끝의 색이 같지 않다라는 조건이 추가되었음.
    빨 초
    빨 파
    초 빨
    초 파
    파 빨
    파 초
    의 6가지 경우가 존재
    각 경우의 존재를 모두 구해서 최솟값을 출력.
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

    int n, ans = 98763541;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<3 ; j++){
            cin >> fee[i][j];
        }
    }

    for(int c=0 ; c<3 ; c++){ // 첫 집이 색을 세가지 가지는 경우
        dp[1][c] = fee[1][c];
        for(int c1=0 ; c1<3 ; c1++){
            if(c1!=c) dp[1][c1]=1001; // 해당 경우의 색이 아닌 경우 최솟값을 가지지 못하게 큰 값을 넣어준다.
        }

        for(int i=2 ; i<=n ; i++){
            dp[i][0]=min(dp[i-1][1], dp[i-1][2]) + fee[i][0];
            dp[i][1]=min(dp[i-1][0], dp[i-1][2]) + fee[i][1];
            dp[i][2]=min(dp[i-1][0], dp[i-1][1]) + fee[i][2];
        }

        for(int i=0 ; i<3 ; i++){ //dp[n][i]는 n-1번째와 색이 겹치치 않는 경우 중 최솟값이므로 위에서 지정한 첫 집과 색을 겹치지 않게 한다.
            if(i==c) continue; // 첫 집과 색이 같으면 스킵
            ans = min(dp[n][i], ans);
        }
    }

    cout << ans;
    return 0;
}