#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;

    int ans=0;
    stack<int> s;
    int n = str.size();
    for(int i=0 ; i<n ; i++){
        if(str[i]=='('){
            s.push(i);
        }else{
            if(s.top()+1 == i){
                s.pop();
                ans+=s.size();
            }else{
                s.pop();
                ans+=1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}