/*
    팩토리얼의 0의 갯수는 5의 갯수를 샌다.
*/

#include<iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, cnt=0;
    cin >> n;

    while(n>0){
        int tmp = n;
        while(tmp%5==0){
            tmp=tmp/5;
            cnt++;
        }
        n--;   
    }
    cout << cnt;

    return 0;
}