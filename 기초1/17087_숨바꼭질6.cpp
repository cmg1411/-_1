#include<iostream>
using namespace std;

int num[100001];

int solve(int a, int b){
    int c = a%b;
    if(c==0) return b;
    return solve(b, c);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, my;
    cin >> n >> my;

    for(int i=0 ; i<n ; i++){
        int fri;
        cin >> fri;
        num[i]=abs(my-fri);
    }

    if(n==1){
        cout << num[0];
        return 0;
    }

    int m=solve(num[0], num[1]);
    for(int i=2 ; i<n ; i++){
        m = solve(m, num[i]);
    }

    cout << m;
    return 0;
}