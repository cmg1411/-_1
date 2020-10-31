#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    stack<char> l, r;
    
    string str;
    cin >> str;
    for(char c : str){
        l.push(c);
    }
    
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        char cmd;
        cin >> cmd;

        if(cmd=='L'){
            if(l.empty()) continue;
            r.push(l.top());
            l.pop();
        }else if(cmd=='D'){
            if(r.empty()) continue;
            l.push(r.top());
            r.pop();
        }else if(cmd=='B'){
            if(l.empty()) continue;
            l.pop();
        }else{
            char ch;
            cin >> ch;
            l.push(ch);
        }
    }

    int range = l.size();
    for(int i=0 ; i<range; i++){
        r.push(l.top()); //왼쪽 스택은 거꾸로 출력되므로 오른쪽으로 모아서 출력한다.
        l.pop();
    }
    range = r.size();
    for(int i=0 ; i<range ; i++){
        cout << r.top();
        r.pop();  
    }


    return 0;
}