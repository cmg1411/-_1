#include<iostream>
#include<stack>
#include<string>
using namespace std;

int cmdpre(char cmd){
    if(cmd=='+'||cmd=='-') return 1;
    else if(cmd=='*'||cmd=='/') return 2;
    else return 0;
}

stack<char> s;

int main (){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    char c;
    while(cin >> c){
        if(c>='A'&&c<='Z') cout << c;
        else if(c=='(') s.push(c);
        else if(c==')'){
            while(s.top()!='('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }else{
            while(!s.empty() && (cmdpre(c)<=cmdpre(s.top()))){ // ( 를 우선순위 1로 지정했기 때문에 s.top()에서 ( 를 만나면 무조건 그만한다.
                cout << s.top();
                s.pop();
            }
            s.push(c);
            
        }
    }

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    return 0;
}