#include<iostream>
#include<stack>
#include<vector>
#include<string.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string str;
    getline(cin, str);
    str+='\n';
    
    bool flag = false;
    stack<char> s;
    for(int i=0 ; i<str.length() ; i++){    
        if(str[i]=='<'){
            if(!s.empty()){
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }
            }
            flag =true;
            cout<<str[i];
        }else if(str[i]=='>'){
            flag=false;
            cout<<str[i];
        }else if(flag==true){
            cout<<str[i];
        }else if(flag==false){
            if(str[i]==' '||str[i]=='\n'){
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }
                cout << str[i];
            }else{
                s.push(str[i]);
            }
        }
    }
    return 0;
}