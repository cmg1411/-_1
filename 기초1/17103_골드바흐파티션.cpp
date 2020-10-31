#include<iostream>
using namespace std;

bool chk[1000001];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    for(int i=2 ; i*i<=1000000 ; i++){
        for(int j=i+i ; j<=1000000 ; j=j+i){
            chk[j]=true;
        }
    }


    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        int m, cnt=0;
        cin >> m;

        for(int k=2 ; k*2<=m ; k++){
            if(!chk[k]&&!chk[m-k]) cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}