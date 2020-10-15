#include<iostream>
using namespace std;

int alp[26];

int main(){

    string str;
    cin >> str;

    int len = str.size();
    for(int i=0 ; i<len ; i++){
        alp[str[i]-'a']++;
    }

    for(int i=0 ; i<26 ; i++){
        cout << alp[i] << ' ';
    }

    return 0;
}