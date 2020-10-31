#include<iostream>
using namespace std;

long long cnt=0;

void sol(long long n, long long digit){
    if(digit==1) return;
    if(n>digit/2){
        cnt++;
        sol(n-digit/2, digit/2);
    }
    else
        sol(n, digit/2);
    
    return;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;

    long long temp = 1;
    while(1){
        if(temp/2<n && n<=temp) break;
        temp=temp*2;
    }

    sol(n, temp);
    if(cnt%2==0){
        cout << 0;
    }else{
        cout << 1;
    }
    return 0;
}
// 0 - 1
// 01 - 2
// 0110 - 4
// 01101001 - 8
// 0110100110010110 - 16