/*
    골바추 : 2보다 큰 짝수는 두 소수의 합으로 표한할 수 있다.
    3보다 큰 홀수는 세 소수의 합으로 표현할 수 있다.

    골바추는 에라토스테네스 채로 푼다.
*/

#include<iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    bool chk[1000001];

    // 채로 소수리스트를 먼저 뽑아 놓아야 시간초과 안남.
    chk[1]=true;
    for(int i=2 ; i*i<=1000000 ; i++){
        for(int j=i*2 ; j<=1000000 ; j=j+i){
            chk[j]=true;
        }
    }    

    while(1){
        int n;
        cin >> n;
        if(n==0) break; 
        bool flag =false;
        for(int i=2 ; i+i<=n ; i++){
            if(!chk[i] && !chk[n-i]){ //키 포인트
                cout << n << " = " << i << " + " << n-i << '\n';
                flag = true;
                break;
            }
        }

        if(flag==false) cout << "Goldbach's conjecture is wrong.";
    }

    return 0;
}