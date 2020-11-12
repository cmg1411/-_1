/*
    순열
    0. 길이 구하기
    1. i구하기
    2. j구하기
    3. i-1, j 바꾸기
    4. 뒤에거 뒤집기
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> vec(n);
    for(int i=0 ; i<n ; i++){
        cin >> vec[i];
    }

    if(prev_permutation(vec.begin(), vec.end())){
    
        for(int i=0 ; i<n ; i++){
            cout << vec[i] << ' ';
        }
    }else{
        cout << -1;
    }
}

// bool prev_per(vector<int> &vec, int n){
//     int i=n-1;
//     while(i>0 && vec[i-1]<=vec[i]) i-=1;
//     if(i==0) return false;

//     int j=n-1;
//     while (vec[i-1]<=vec[j]) j-=1;
    
//     swap(vec[i-1], vec[j]);

//     j=n-1;
//     while(i<j){
//         swap(vec[i], vec[j]);
//         i+=1; j-=1;
//     }
//     return true;
// }

// int main(){
//     cin.tie(nullptr);
//     ios_base::sync_with_stdio(false);

//     int n;
//     cin >> n;

//     vector<int> vec(n);
//     for(int i=0 ; i<n ; i++){
//         cin >> vec[i];
//     } 

//     if(prev_per(vec, vec.size())){
//         for(int i=0 ; i<n ; i++){
//             cout << vec[i] << ' ';
//         }
//     }else{
//         cout << -1;
//     }

//     return 0;
// }