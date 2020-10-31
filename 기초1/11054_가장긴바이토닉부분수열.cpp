#include<iostream>
#include<algorithm>
using namespace std;

int a[1001];
int dl[1001], dr[1001];

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    for(int i=0 ; i<n ; i++){
        dl[i]=1;
        for(int j=0 ; j<i ; j++){
            if(a[i]>a[j] && dl[j]+1>dl[i])
                dl[i] = dl[j]+1;
        }
    }

    for(int i=n-1 ; 0<=i ; i--){
        dr[i]=1;
        for(int j=n-1 ; i<j ; j--){
            if(a[i]>a[j] && dr[j]+1 > dr[i])
                dr[i]=dr[j]+1;
        }
    }

    int max=-987654321;
    for(int i=0 ; i<n ; i++){
        if(dr[i]+dl[i]-1> max)
            max = dr[i]+dl[i]-1;
    }

    cout << max;

    return 0;
}