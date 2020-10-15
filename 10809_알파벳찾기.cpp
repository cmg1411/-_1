#include<iostream>
using namespace std;

int ans[26];

int main(){

    string str;
    cin >> str;

    int len = str.size();
    for(int i=0 ; i<26 ; i++) ans[i]=-1;
    for(int i=0 ; i<len ; i++){
        if(ans[str[i]-'a']<0)
        ans[str[i]-'a']=i;
    }

    for(int i=0 ; i<26 ; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}