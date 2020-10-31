#include <iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int dl[100001];
int dr[100001];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    for(int i=0 ; i<n ; i++){
        dl[i]=arr[i];
        if(i==0) continue;
        if(dl[i]<dl[i-1]+arr[i])
            dl[i]=dl[i-1]+arr[i];
    }

    for(int i=n-1 ; 0<=i ; i--){
        dr[i]=arr[i];
        if(i==n-1) continue;
        if(dr[i]<dr[i+1]+arr[i])
            dr[i]=dr[i+1]+arr[i];
    }

    int max = *max_element(dl, dl+n);

    for(int i=1 ; i<n-1 ; i++){
        if (max < dl[i-1] + dr[i+1]) {
            max = dl[i-1] + dr[i+1];
        }
    }

    cout << max;


	return 0;
}

