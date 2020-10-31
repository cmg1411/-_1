#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    stack<int> s, ans;
    string str;
    cin >> str;
    for(int i=0 ; i<str.size() ; i++){
        s.push(str[i]-'0');
    }

    while(!s.empty()){
        int n=3, two=1;
        int res=0;
        bool flag=false;
        while(n>0){
            if(s.top()==1) res+=two;
            s.pop();
            if(s.empty()){
                flag = true;
                break;
            }
            two*=2;
            n--;
        }
        ans.push(res);
    }

    
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    return 0;
}