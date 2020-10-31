#include<iostream>
using namespace std;

// 소인수 분해는 그냥 다 새는 것이 빠름,, 아리스토테네스 채가 더 오래걸림

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=2 ; i*i <= n ; i++){
        while(n%i == 0){
            cout << i << '\n';
            n=n/i;
        }
    }

    if(n>1) cout << n; //자기가 소수일 때.

    return 0;
}
// #include<iostream>
// using namespace std;

// bool chk[10000001];

// int main(){
//     cin.tie(0);
//     cout.tie(0);
//     ios_base::sync_with_stdio(false);

//     for(int i=2 ; i*i<=10000000 ; i++){
//         for(int j=i+i ; j<=10000000 ; j=j+i){
//             chk[j]=true;
//         }
//     }


//     int n;
//     cin >> n;

//     for(int i=2 ; i<=n ; i++){
//         if(chk[i]==false){
//             while((n%i)==0){
//                 cout << i << '\n';
//                 n=n/i;
//             }
//         }
//     }

//     return 0;
// }