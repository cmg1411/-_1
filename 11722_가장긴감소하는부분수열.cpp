#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001];
int arr[1001];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        cin >> arr[i];
    }

    for(int i=1 ; i<=n ; i++){
        dp[i]=1;
        for(int j=1 ; j<i ; j++){
            if(arr[j]>arr[i] && dp[j]+1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    cout << *max_element(dp+1, dp+n+1);

    return 0;
}