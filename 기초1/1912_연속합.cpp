#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int ans[100001];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    ans[0]=arr[0];
    for(int i=1 ; i<n ; i++){
        if(arr[i]>ans[i-1]+arr[i]) ans[i]=arr[i];
        else ans[i]=ans[i-1]+arr[i];
    }

    cout << *max_element(ans, ans+n);

    return 0;
}