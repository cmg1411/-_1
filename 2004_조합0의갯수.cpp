/*
    조합 0의 갯수는 2의 갯수와 5의 갯수를 샌 후 적은것 고른다.
    nCr = n!/(n-r)!r!
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    long long int n, r;
    cin >> n >> r;

/*
    입력이 20억이므로 long long int형 쓴다.
*/

    long long int two=0, five=0;

/*
    N!를 소인수분해했을때 X가 몇번인지 알고 싶다면,
    X부터 X^2, X^3으로 늘어나면서 N을 나눈 갯수를 더하면 된다.

    EX) 100!에서 5의 개수는(5^3=125>100이므로 5^2까지)
    100/5 + 100/25 = 24이다.
*/
    for(long long int i=2 ; i<=n ; i=i*2){
        two = two+n/i;
    }
    for(long long int i=2 ; i<=n-r ; i=i*2){
        two = two-(n-r)/i;
    }
    for(long long int i=2 ; i<=r ; i=i*2){
        two = two-r/i;
    }
    for(long long int i=5 ; i<=n ; i=i*5){
        five = five+n/i;
    }
    for(long long int i=5 ; i<=n-r ; i=i*5){
        five = five-(n-r)/i;
    }
    for(long long int i=5 ; i<=r ; i=i*5){
        five = five-r/i;
    }

    cout << min(two, five);
     
    return 0;
}