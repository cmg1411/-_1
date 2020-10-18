#include<iostream>
using namespace std;

int gcd(int a, int b){
    int c=a%b;
    if(c==0) return b;
    return gcd(b, c);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> b;
        cout << a*b/gcd(a, b) << '\n';
    }

    return 0;
}