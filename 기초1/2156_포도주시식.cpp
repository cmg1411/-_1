/*
    0먹 먹 안
    1먹 안 먹
    2안 먹 먹
*/
#include<iostream>
#include<algorithm>
using namespace std;

int dp[10001][3];
int wine[10001];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    
    for(int i=1 ; i<=n ; i++){
        cin >> wine[i];
    }

    for(int i=1 ; i<=n ; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]}); // 0개먹는 경우 = 그전에 안먹든, 1개먹든, 2개먹든 중 최댓값.
        dp[i][1] = dp[i-1][0] + wine[i]; // 1개째인 경우 = 그전에 안먹었음.
        dp[i][2] = dp[i-1][1] + wine[i]; // 2개째인 경우 = 그전에 한개 먹었음.
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}