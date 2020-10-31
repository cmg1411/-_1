#include<iostream>
#include<algorithm>
using namespace std;
/*
    유클리드 호제법 : A, B의 최대공약수는 A%B와 B의 최대공약수와도 같다. 제귀를 돌려서 한쪽이 0이나오면 다른쪽이 최대 공약수이다.

    A*B=GCD(A,B)*LCM(A*B);
*/


int gcd(int a, int b){
    int c=a%b;
    if(c==0) return b;
    return gcd(b, c);
}

int lcm(int gcd, int mul){
    return mul/gcd;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int g, l;
    int n, m;
    cin >> n >> m;

    g = gcd(n, m);
    l = lcm(g, n*m);

    cout << g << '\n' << l ;
    return 0;
}