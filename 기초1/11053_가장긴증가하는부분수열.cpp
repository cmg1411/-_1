/*
    가장 긴 증가하는 부분수열 LIS LONGEST INCREASING SUBSEQUENCE

    dp[i]  10  20  10  30  20  50
    a[i]   1   2   1   3   2   4

    a[] 배열을 선언하여 인덱스가 크고, 값도 크다면 +1을 해줌

    dp[N] = dp
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> dp(n);

    for(int i=0 ; i<n ; i++){
        cin >> v[i];
    }

    for(int i=0 ; i<n ; i++){
        dp[i]=1;
        for(int j=0 ; j<i ; j++){
            if(dp[j]+1>dp[i]&&v[j]<v[i]) // 앞의 값보다 큰 값이고, 횟수가 앞의 횟수+1 보다 작은값 즉 변경되지 않은 값 1이다.
                dp[i] = dp[j]+1;
        }
    }

    cout << *max_element(dp.begin(),dp.end()); // 배열의 최솟값/최댓값 구하는 함수. 배열의 주소를 리턴하기에 * 붙인다.

    return 0;
}