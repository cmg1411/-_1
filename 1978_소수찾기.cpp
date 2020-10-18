/*
    소수를 판별하기 위해서는 
    1~N 까지 다 검사하는법
    1~N/2 까지 검사하는법
    1~root(N) 까지 검사하는 법 이 있다.
*/

#include<iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int cnt=0;
    for(int i=0 ; i < n ; i++){
        int m;
        bool flag=true;
        cin >> m;
        if(m==1) continue;
        if(m==2){cnt++; continue;}
        for(int j=2 ; j*j<=m ; j++){ //for(a;b;c)d 작동순서 a>b>d>c 초기화 한 식도 조건 검사함     //<=가 아니라 <이면 4에서 반례가 생긴다.
            if(m%j==0){flag=false; break;}
        }
        if(flag) cnt ++;
    }

    cout << cnt;
}