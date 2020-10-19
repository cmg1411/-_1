#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, ans=0;
    string str;
    cin >> str >> n;

    int mul=1;
    for(int i=str.size()-1 ; 0<=i ; i--){
        if('A'<=str[i]&&str[i]<='Z') ans+=(str[i]-55)*mul;
        else ans+=(str[i]-'0')*mul;
        mul*=n;
    }

    cout << ans;

    return 0;
}