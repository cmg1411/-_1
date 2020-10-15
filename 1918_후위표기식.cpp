#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    stack<char> alp, cmd;
    string str;

    char c;
    while(cin>>c){
        if(c=='(') continue;
        if(c==')'){

        }

        if(c>='A'&&c<='Z'){
            alp.push(c);
        }else{
            cmd.push(c);
        }
    }
    a
    return 0;
}