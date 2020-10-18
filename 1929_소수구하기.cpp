/*
    N까지의 소수를 구하기 위해서는 에라토스테네스의 채를 이용하자.
*/

#include<iostream>
using namespace std;

bool chk[1000001];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int m, n;
    cin >> m >> n;

    chk[1]=true; // 1은 소수가 아니므로 처리해준다.
    for(int i=2 ; i*i<=n ; i++){ // 2부터 i*i<=n까지
        if(chk[i]) continue;
        else{
            for(int j=2*i ; j<=n ; j=j+i){ // 2i부터시작
                chk[j]=true;
            }
        }
    }

    for(int i=m ; i<=n ; i++)
        if(!chk[i]) cout << i << '\n';

    return 0;
}