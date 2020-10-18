#include<iostream>
#include<vector>
#include<string>
using namespace std;

int getGCD(int a, int b){
    int c=a%b;
    if(c==0) return b;
    return getGCD(b, c);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t;

    for(int i=0 ; i<t ; i++){
        cin >> n;
        vector<int> v(n);
        long long int gcd=0; // 한줄에 테케가 100개면 가능한 쌍은 100*99/2 = 약5000개, 테케가 모두 100만이라고 치면 100만*5000 = 500억은 int범위 넘어감.

        for(int j=0 ; j<n ; j++){
            cin >> v[j];
        }

        for(int k=0 ; k<n-1 ; k++){
            for(int z=k+1 ; z<n ; z++){
                gcd+=getGCD(v[k], v[z]);
            }
        }

        cout << gcd << '\n';
    }

    return 0;
}