/*
    dp[n]=N개의 수 중 증가하는 부분수열 중 합이 가장 큰 합
    dp[n] = dp[j]+arr[n];
*/

#include<iostream>
using namespace std;

int dp[1001];
int arr[1001];
int sum[1001];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        cin >> arr[i];
    }

    dp[1]=arr[1];
    for(int i=2 ; i<=n ; i++){
        dp[i]=arr[i];
        for(int j=1 ; j<i ; j++){
            if(arr[j]<arr[i] && dp[j]+arr[i]>dp[i]) // 가장~증가하는 부분수열에서는 두가지 조건을 따진다.
                dp[i]=dp[j]+arr[i];                 // 1. 증가하니까 배열의 값이 커야 한다.
        }                                           // 2. 큰, 긴 이라는 값을 DP에 넣을텐데, 이전단계의 DP값에 현재 크기나 길이를 더했을 때, 현재값이 더 크다면 그 앞에서 더 길거나 큰 경우가 이미 들어온 경우이므로
    }                                               // 이전 DP값에 현재 길이나 크기를 더했을 때, 들어있는 현재 DP값보다 커야 교환할 수 있따.

    int max = 0;
    for(int i=1 ; i<=n ; i++){
        if(max<dp[i]) max = dp[i];
    }

    cout << max;

    return 0;
}