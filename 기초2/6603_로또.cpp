#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool next(vector<int> &v, int n){
    int i=n-1;
    while(v[i-1]>=v[i] && i>0)i-=1;
    if(i==0) return false;

    int j=n-1;
    while(v[i-1]>=v[j]) j-=1;

    swap(v[i-1], v[j]);

    j=n-1;
    while(i<j){
        swap(v[i],v[j]);
        j-=1;
        i+=1;
    }
    return true;
}

int main(){

    while(1){
        int n;
        cin >> n;
        if(n==0) break;
        vector<int> s(n);
        for(int i=0 ; i<n ; i++){
            cin >> s[i];
        }
        vector<int> v(n);
        for(int i=n-1 ; 5<i ; i--){
            v[i]=1;
        }

        do{
            for(int i=0 ; i<n ; i++){
                if(v[i]==0){
                    cout << s[i] << ' ';
                }
            }
            cout << '\n';
        }while(next(v,n));

        cout << '\n';
    }

    return 0;
}