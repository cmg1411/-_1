#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vec;

bool next_per(int n){
    int i=n-1;
    while(i>0 && vec[i-1]>=vec[i]) i-=1;
    if(i==0) return false;

    int j=n-1;
    while(vec[i-1]>=vec[j]) j-=1;

    swap(vec[i-1], vec[j]);

    j=n-1;
    while(i<j){
        swap(vec[i], vec[j]);
        j-=1; i+=1;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        vec.push_back(i);
    }

    int size = vec.size();
    do{
        for(int i=0 ; i<n ; i++) cout << vec[i] << ' ';
        cout << '\n';
    }while(next_per(size));

    return 0;
}