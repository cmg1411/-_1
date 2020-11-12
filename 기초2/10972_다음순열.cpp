/*
    순열 찾는법
    0. 길이 구하기
    1. i찾기 (i=0이면 마지막임 처리)
    2. j찾기
    3. i-1 j 바꾸기
    4. 뒤 숫자 뒤집기

*/


#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;

bool next_per(int n){
    int i = n-1;
    while(i>0&&vec[i]<=vec[i-1]){
        i = i-1;
    }
    if(i==0) return false; // 마지막임
    int j = n-1;
    while(vec[i-1]>=vec[j]) j = j-1;
    swap(vec[i-1], vec[j]);
    j = n-1;
    while(i<j){
        swap(vec[i], vec[j]);
        j=j-1;
        i=i+1;
    }
    return true;
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=0 ; i<n ; i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }

    if(next_per(vec.size())){
        for(int i=0 ; i<vec.size() ; i++){
            cout << vec[i] << ' ';
        }
    }else{
        cout << -1;
    }

    return 0;
}