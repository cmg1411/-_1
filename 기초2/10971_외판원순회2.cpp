#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int root[11];
int vec[11][11];

bool next_per(int n){
    int i = n-1;
    while(root[i-1]>=root[i] && i>0) i-=1;
    if(i==0) return false;

    int j=n-1;
    while(root[i-1]>=root[j]) j-=1;

    swap(root[i-1], root[j]);

    j = n-1;
    while(i<j){
        swap(root[i], root[j]);
        i+=1; j-=1;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        root[i]=i+1;
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> vec[i][j];
        }
    }

    int min = 987654321;
    do{
        int sum=0;
        bool flag = false;
        for(int i=0 ; i<n-1 ; i++){
            if(vec[root[i]][root[i+1]] == 0){
                flag = true;
                break;
            }
            sum += vec[root[i]][root[i+1]];
        }
        if(flag || vec[root[n-1]][root[0]]==0) continue;
        sum += vec[root[n-1]][root[0]];
        if(min > sum) min = sum;
    }while(next_per(n));

    cout << min;

    return 0;
}